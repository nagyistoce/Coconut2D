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

// ==================================================================================================================================
//	    ____                           ____        __
//	   /  _/___ ___  ____ _____ ____  / __ \____ _/ /_____ _
//	   / // __ `__ \/ __ `/ __ `/ _ \/ / / / __ `/ __/ __ `/
//	 _/ // / / / / / /_/ / /_/ /  __/ /_/ / /_/ / /_/ /_/ /
//	/___/_/ /_/ /_/\__,_/\__, /\___/_____/\__,_/\__/\__,_/
//	                    /____/
// ==================================================================================================================================

#ifndef __IMAGEDATA_HPP__
#define __IMAGEDATA_HPP__

#include "Coconut2D.hpp"

class ImageData
{
public:
	ImageData(std::string str);
	ImageData(std::string w, std::string h);
	~ImageData();
	TypedArray<uint8_t>* data;
	int width;
	int height;
	std::string src;
};

#endif /* __IMAGEDATA_HPP__ */
