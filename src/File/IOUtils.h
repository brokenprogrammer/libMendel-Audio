/*
 * libMendel-Audio
 *
 * The MIT License (MIT)
 *
 * Copyright (C) 2017 Oskar Mendel
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#pragma once

#include <fstream>
#include <string>

class IOUtils
{
public:
	static void readBytes(std::ifstream input, char* b, int len);
	static void readBytes(std::ifstream input, char* b, int len, int off);
	static char intToByte(int i);
	static int  byteToInt(char b);
	static int  getBitAt(char b, int pos);
	static int  getBitAtBE(char b, int pos);
	static int  getTopNibble(char b);
	static int  getBottomNibble(char b);
	static int  getTopNibble(int i);
	static int  getBottomNibble(int i);
	
	static int  addBytesToInt(int x1, int x2);
	static long addBytesToInt(int x1, int x2, int x3);
	static long addBytesToInt(int x1, int x2, int x3, int x4);

	static int  addBytesToIntBE(int x1, int x2);
	static long addBytesToIntBE(int x1, int x2, int x3);
	static long addBytesToIntBE(int x1, int x2, int x3, int x4);

	static long addBytesToInt4(char* b);
	static long addBytesToInt4(char* b, int off);

	static long addBytesToInt4BE(char* b);
	static long addBytesToInt4BE(char* b, int off);

	static std::string createByteString(int bits, int offset);
	static std::string getBytesToString(char* b, int offset, int len);
};

