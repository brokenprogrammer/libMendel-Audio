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

#include "includes\catch.hpp"
#include"../src/File/IOUtils.h"
#include <string>
#include <iostream>

static const std::string flacFilePath = "../demo/Jimmy Pengiun - Untitled Star.flac";

TEST_CASE("IOUtils")
{
	SECTION("Read bytes from stream")
	{
		std::ifstream in(flacFilePath);
		char* STREAMTAG = new char[4];
		
		IOUtils::readBytes(in, STREAMTAG, 4);

		CHECK(STREAMTAG[0] == 'f');
		CHECK(STREAMTAG[1] == 'L');
		CHECK(STREAMTAG[2] == 'a');
		CHECK(STREAMTAG[3] == 'C');
		
		in.close();
	}

	SECTION("Read bytes from stream with offset")
	{
		std::ifstream in(flacFilePath);
		char* STREAMTAG = new char[2];

		IOUtils::readBytes(in, STREAMTAG, 2, 2);

		CHECK(STREAMTAG[0] == 'a');
		CHECK(STREAMTAG[1] == 'C');

		in.close();
	}

	SECTION("Convert integer to byte")
	{
		int b1 = 10;
		int b2 = 127;
		int b3 = 200;
		int b4 = 255;
		int b5 = 128;
		int b6 = 4;

		CHECK(IOUtils::intToByte(b1) == 10);
		CHECK(IOUtils::intToByte(b2) == 127);
		CHECK(IOUtils::intToByte(b3) == 200);
		CHECK(IOUtils::intToByte(b4) == 255);
		CHECK(IOUtils::intToByte(b5) == (1 << 7));
		CHECK(IOUtils::intToByte(b6) == (1 << 2));
	}

	SECTION("Convert byte to integer")
	{
		unsigned char b1 = 0x0F;
		unsigned char b2 = 0xFF;
		// unsigned char b3 = Byte.parseByte(BinaryUtil.createByteString(2, 6), 2);
		// unsigned char b4 = Byte.parseByte(BinaryUtil.createByteString(4, 2), 2);

		CHECK(IOUtils::byteToInt(b1) == 15);
		CHECK(IOUtils::byteToInt(b2) == 255);
		// CHECK(IOUtils::byteToInt(b3) == 3);
		// CHECK(IOUtils::byteToInt(b4) == 60);
	}
}