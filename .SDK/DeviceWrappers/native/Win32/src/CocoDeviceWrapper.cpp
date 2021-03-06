﻿/* ***** BEGIN LICENSE BLOCK *****
 *
 * Copyright (C) 2013-2014 www.coconut2D.org
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * ***** END LICENSE BLOCK ***** */

#include <windows.h>
#include <commctrl.h>
#include "resource.h"
#include "CocoDeviceWrapper.h"

//////////////////////////////////////////////////////////////////////////////////////////////
CocoDeviceWrapper::CocoDeviceWrapper(int width, int height)
{
	// Initialise common controls.
	INITCOMMONCONTROLSEX icc;
	icc.dwSize = sizeof(icc);
	icc.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&icc);

	// Create a window rect and expand it by border size.
	RECT rc;
	SetRect(&rc, 0, 0, width, height);
	AdjustWindowRectEx(&rc, WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_OVERLAPPEDWINDOW, FALSE, WS_EX_APPWINDOW | WS_EX_WINDOWEDGE);
	LONG dx = GetSystemMetrics(SM_CXSCREEN) - (rc.right - rc.left);
	LONG dy = GetSystemMetrics(SM_CYSCREEN) - (rc.bottom - rc.top);

	// Get Module
	m_hInstance = GetModuleHandle(NULL);

	// Class for our main window.
	LPCTSTR MainWndClass = L"Win32 Test application";
	WNDCLASSEX wc;
	wc.cbSize       	= sizeof(wc);
	wc.style 			= CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.lpfnWndProc 		= MainWndProc;
	wc.cbClsExtra 		= 0;
	wc.cbWndExtra 		= 0;
	wc.hInstance 		= m_hInstance;
	wc.hIcon         	= (HICON) LoadImage(m_hInstance, MAKEINTRESOURCE(IDI_APPICON), IMAGE_ICON, 0, 0, LR_DEFAULTSIZE | LR_DEFAULTCOLOR | LR_SHARED);
	wc.hIconSm       	= (HICON) LoadImage(m_hInstance, MAKEINTRESOURCE(IDI_APPICON), IMAGE_ICON, GetSystemMetrics(SM_CXSMICON), GetSystemMetrics(SM_CYSMICON), LR_DEFAULTCOLOR | LR_SHARED);
	wc.hCursor 			= LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground 	= CreateSolidBrush(0);
	wc.lpszMenuName 	= NULL;
	wc.lpszClassName 	= MainWndClass;

	// Register our window classes
	RegisterClassEx(&wc);

	// Create instance of main window.
	m_glHWND = CreateWindowEx(WS_EX_APPWINDOW | WS_EX_WINDOWEDGE, MainWndClass, L"$(PROJECT_NAME)", WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, rc.right - rc.left, rc.bottom - rc.top, NULL, NULL, m_hInstance, NULL);

	// Get Window hDC, show window and force a paint.
	m_glHDC = GetDC(m_glHWND);
	ShowWindow(m_glHWND, SW_SHOW);
	UpdateWindow(m_glHWND);
	SetForegroundWindow(m_glHWND);
	SetFocus(m_glHWND);

	// Keep window size information for OpenGL calculations
	screen.width = width;
	screen.height = height;
	screen.pixelRatio = 1.0f;
	screen.top = 0;
	screen.isPortrait = (screen.height > screen.width);
	screen.rotation = fxScreen::Rotation::NONE;

	// Initialize OpenGL
	PIXELFORMATDESCRIPTOR pdf;
	pdf.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pdf.nVersion = 1;
	pdf.dwFlags = PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW | PFD_DOUBLEBUFFER | PFD_TYPE_RGBA;
	pdf.iPixelType = PFD_TYPE_RGBA;
	pdf.cColorBits = 32;
	pdf.cDepthBits = 16;
	pdf.iLayerType = PFD_MAIN_PLANE;

	int iPixelFormat = ChoosePixelFormat(m_glHDC, &pdf);

	if(iPixelFormat!=0)
	{
		if(SetPixelFormat(m_glHDC, iPixelFormat, &pdf))
		{
			m_OpenGLContext = wglCreateContext(m_glHDC);
			if(wglMakeCurrent(m_glHDC, m_OpenGLContext))
			{
				glEnable(GL_TEXTURE_2D);
				glDisable(GL_DEPTH_TEST);
				glDisable(GL_CULL_FACE);
				glDisable(GL_LIGHTING);
				glDisable(GL_DITHER);
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			}
		}
	}

	glewInit();

	// Create the HTMLWindow and HTMLDocument
	window = new HTMLWindow();
	window->setScreen(screen);
	window->innerWidth = screen.width;
	window->innerHeight = screen.height;
	window->devicePixelRatio = screen.pixelRatio;
	window->deviceRotation = 0.0f;
	global = window;
	document = window->document;

	// Create a WebGL Canvas
	engine = new GameEngine();

	alive = true;
	EventLoop();
};

//////////////////////////////////////////////////////////////////////////////////////////////
CocoDeviceWrapper::~CocoDeviceWrapper(void)
{
	if(wglDeleteContext(m_OpenGLContext)) m_OpenGLContext = NULL;
	if(m_glHDC) m_glHDC = (ReleaseDC(m_glHWND, m_glHDC), (HDC)NULL);
	if(m_glHWND) m_glHWND = (DestroyWindow(m_glHWND), (HWND)NULL);
	//UnregisterClass("CocoWindow", m_hInstance);
};

//////////////////////////////////////////////////////////////////////////////////////////////
void CocoDeviceWrapper::EventLoop()
{
	// Read clock frequency and adjust to milliseconds
	LARGE_INTEGER freq, m_TCurrent, m_TFirst, m_TLast;
	QueryPerformanceFrequency(&freq);
	double currentTime, ellapsedTime, m_Freq = double(freq.QuadPart)/1000.0;
	QueryPerformanceCounter(&m_TFirst);
	m_TLast = m_TFirst;

	RECT rc;

	do
	{
		// Get total and elapsed milliseconds since last tick.
		QueryPerformanceCounter(&m_TCurrent);
		currentTime = (double(m_TCurrent.QuadPart) - double(m_TFirst.QuadPart)) / m_Freq;
		ellapsedTime = (double(m_TCurrent.QuadPart) - double(m_TLast.QuadPart)) / m_Freq;

		// Update Window Size
		GetClientRect(m_glHWND, &rc);
		screen.width = rc.right-rc.left+1;
		screen.height = rc.bottom-rc.top+1;
		window->innerWidth = screen.width;
		window->innerHeight = screen.height;

		if(ellapsedTime>=16.0)
		{
			// Tick APIs (HTML, HTTP, Audio, Video, Physics, etc.)
			HandleDeviceEvents();
			tick();

			// Mark last time for next cycle.
			m_TLast = m_TCurrent;
		}

		Sleep(0);
	}
	while(alive);
}

//////////////////////////////////////////////////////////////////////////////////////////////
void CocoDeviceWrapper::HandleDeviceEvents()
{
 	// Process messages on OpenGL-hooked window.
	while(PeekMessage(&msg, m_glHWND, 0, 0, PM_REMOVE))
	{
		switch(msg.message)
		{
		case WM_KEYDOWN:
			window->handleEvent(0, fxEvent::KEYDOWN, &msg);
			break;

		case WM_KEYUP:
			window->handleEvent(0, fxEvent::KEYUP, &msg);
			break;

		case WM_LBUTTONDOWN:
			window->handleEvent(0, fxEvent::TOUCHSTART, &msg);
			break;

		case WM_LBUTTONUP:
			window->handleEvent(0, fxEvent::TOUCHEND, &msg);
			break;

		case WM_MOUSEMOVE:
			window->handleEvent(0, fxEvent::TOUCHMOVE, &msg);
			break;

		case WM_CLOSE:
		case WM_QUIT:
			alive = false;
			break;
		}
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////
// Window procedure for our main window.
LRESULT CALLBACK CocoDeviceWrapper::MainWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	static HINSTANCE hInstance;

	switch (msg)
	{
		case WM_CREATE:
		{
			hInstance = ((LPCREATESTRUCT) lParam)->hInstance;
			return 0;
		}

		case WM_DESTROY:
		{
			PostQuitMessage(0);
			return 0;
		}
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

//////////////////////////////////////////////////////////////////////////////////////////////
void CocoDeviceWrapper::tick()
{
	#ifdef __XMLHTTPREQUEST_HPP__
	XMLHttpRequest::tick();
	#endif

	engine->run(16);
	SwapBuffers(m_glHDC);
}