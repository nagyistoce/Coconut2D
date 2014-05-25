/* Generated by Coconut2D C++ Compiler from file CocoRenderContext.jspp */

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "CocoRenderContext.hpp"
#include "ICocoRenderContext.hpp"
#include "HTMLCanvasElement.hpp"
#include "HTMLDocument.hpp"
#include "HTMLElement.hpp"
#include "HTMLWindow.hpp"
#include "WebGLRenderingContext.hpp"
#include "CocoRenderContextGL.hpp"
#include "CanvasRenderingContext2D.hpp"
#include "CocoRenderContext2D.hpp"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////
ICocoRenderContext* CocoRenderContext::createContext()
{
	HTMLCanvasElement* canvas = document->body->appendChild(document->createElement(String("canvas")));
	canvas->width = ((float)window->innerWidth);
	canvas->height = ((float)window->innerHeight);
	WebGLRenderingContext* gl = ((WebGLRenderingContext*)canvas->getContext(String("webgl")));
	if(gl)
	{
		return new CocoRenderContextGL(gl);
	}
	gl = ((WebGLRenderingContext*)canvas->getContext(String("experimental-webgl")));
	if(gl)
	{
		return new CocoRenderContextGL(gl);
	}
	CanvasRenderingContext2D* ctx = ((CanvasRenderingContext2D*)canvas->getContext(String("2d")));
	if(ctx)
	{
		return new CocoRenderContext2D(ctx);
	}
	throw CocoException(String("Invalid rendering device."));
}