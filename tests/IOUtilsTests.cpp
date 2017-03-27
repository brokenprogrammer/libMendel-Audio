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

	SECTION("Get bit at target position")
	{
		unsigned char b1 = 0x0F;
		unsigned char b2 = 0xFF;
		// unsigned char b3 = Byte.parseByte(BinaryUtil.createByteString(2, 6), 2);
		// unsigned char b4 = Byte.parseByte(BinaryUtil.createByteString(4, 2), 2);

		CHECK(IOUtils::getBitAt(b1, 0) == 1);
		CHECK(IOUtils::getBitAt(b1, 1) == 1);
		CHECK(IOUtils::getBitAt(b1, 2) == 1);
		CHECK(IOUtils::getBitAt(b1, 3) == 1);
		CHECK(IOUtils::getBitAt(b1, 4) == 0);
		CHECK(IOUtils::getBitAt(b1, 5) == 0);
		CHECK(IOUtils::getBitAt(b1, 6) == 0);
		CHECK(IOUtils::getBitAt(b1, 7) == 0);

		CHECK(IOUtils::getBitAt(b2, 4) == 1);
		CHECK(IOUtils::getBitAt(b2, 1) == 1);
		CHECK(IOUtils::getBitAt(b2, 7) == 1);

		// CHECK(IOUtils::getBitAt(b3, 7) == 0);
		// CHECK(IOUtils::getBitAt(b3, 0) == 1);
		// CHECK(IOUtils::getBitAt(b3, 1) == 1);

		// CHECK(IOUtils::getBitAt(b4, 2) == 1);
		// CHECK(IOUtils::getBitAt(b4, 4) == 1);
		// CHECK(IOUtils::getBitAt(b4, 6) == 0);
	}

	SECTION("Get bit at target position through Big-Endian")
	{
		unsigned char b1 = 0x0F;
		unsigned char b2 = 0xFF;
		// unsigned char b3 = Byte.parseByte(BinaryUtil.createByteString(2, 6), 2);
		// unsigned char b4 = Byte.parseByte(BinaryUtil.createByteString(4, 2), 2);

		CHECK(IOUtils::getBitAtBE(b1, 0) == 0);
		CHECK(IOUtils::getBitAtBE(b1, 1) == 0);
		CHECK(IOUtils::getBitAtBE(b1, 2) == 0);
		CHECK(IOUtils::getBitAtBE(b1, 3) == 0);
		CHECK(IOUtils::getBitAtBE(b1, 4) == 1);
		CHECK(IOUtils::getBitAtBE(b1, 5) == 1);
		CHECK(IOUtils::getBitAtBE(b1, 6) == 1);
		CHECK(IOUtils::getBitAtBE(b1, 7) == 1);

		CHECK(IOUtils::getBitAtBE(b2, 4) == 1);
		CHECK(IOUtils::getBitAtBE(b2, 1) == 1);
		CHECK(IOUtils::getBitAtBE(b2, 7) == 1);

		// CHECK(IOUtils::getBitAtBE(b3, 7) == 1);
		// CHECK(IOUtils::getBitAtBE(b3, 0) == 0);
		// CHECK(IOUtils::getBitAtBE(b3, 1) == 0);

		// CHECK(IOUtils::getBitAtBE(b4, 2) == 1);
		// CHECK(IOUtils::getBitAtBE(b4, 4) == 1);
		// CHECK(IOUtils::getBitAtBE(b4, 6) == 0);
	}

	SECTION("Get top nibble of byte")
	{
		unsigned char b1 = 0x0F;
		unsigned char b2 = 0xFF;
		// unsigned char b3 = Byte.parseByte(BinaryUtil.createByteString(2, 6), 2);
		// unsigned char b4 = Byte.parseByte(BinaryUtil.createByteString(4, 2), 2);

		CHECK(IOUtils::getTopNibble(b1) == 0);
		CHECK(IOUtils::getTopNibble(b2) == 15);
		// CHECK(IOUtils::getTopNibble(b3) == 0);
		// CHECK(IOUtils::getTopNibble(b4) == 3);
	}

	SECTION("Get bottom nibble of byte")
	{
		unsigned char b1 = 0x0F;
		unsigned char b2 = 0xFF;
		// unsigned char b3 = Byte.parseByte(BinaryUtil.createByteString(2, 6), 2);
		// unsigned char b4 = Byte.parseByte(BinaryUtil.createByteString(4, 2), 2);

		CHECK(IOUtils::getBottomNibble(b1) == 15);
		CHECK(IOUtils::getBottomNibble(b2) == 15);
		// CHECK(IOUtils::getBottomNibble(b3) == 3);
		// CHECK(IOUtils::getBottomNibble(b4) == 12);
	}

	SECTION("Get top nibble of integer")
	{
		int b1 = 15;
		int b2 = 255;
		int b3 = 3;
		int b4 = 60;

		CHECK(IOUtils::getTopNibble(b1) == 0);
		CHECK(IOUtils::getTopNibble(b2) == 15);
		CHECK(IOUtils::getTopNibble(b3) == 0);
		CHECK(IOUtils::getTopNibble(b4) == 3);
	}

	SECTION("Get bottom nibble of integer")
	{
		int b1 = 15;
		int b2 = 255;
		int b3 = 3;
		int b4 = 60;

		CHECK(IOUtils::getBottomNibble(b1) == 15);
		CHECK(IOUtils::getBottomNibble(b2) == 15);
		CHECK(IOUtils::getBottomNibble(b3) == 3);
		CHECK(IOUtils::getBottomNibble(b4) == 12);
	}

	SECTION("Adding two bytes")
	{
		int b1 = 15;
		int b2 = 255;
		int b3 = 3;
		int b4 = 60;

		//1111 1111 0000 1111 = 65295
		CHECK(IOUtils::addBytesToInt(b1, b2) == 65295);
		//0000 0011 1111 1111 = 1023
		CHECK(IOUtils::addBytesToInt(b2, b3) == 1023);
		//0011 1100 0000 0011 = 15363
		CHECK(IOUtils::addBytesToInt(b3, b4) == 15363);
	}

	SECTION("Adding three bytes")
	{
		int b1 = 15;
		int b2 = 255;
		int b3 = 3;
		int b4 = 60;

		//0000 0011 1111 1111 0000 1111 = 261903
		CHECK(IOUtils::addBytesToInt(b1, b2, b3) == 261903);
		//0011 1100 0000 0011 1111 1111 = 3933183
		CHECK(IOUtils::addBytesToInt(b2, b3, b4) == 3933183);
		//0000 1111 0011 1100 0000 0011 = 998403
		CHECK(IOUtils::addBytesToInt(b3, b4, b1) == 998403);
	}

	SECTION("Adding four bytes")
	{
		int b1 = 15;
		int b2 = 255;
		int b3 = 3;
		int b4 = 60;

		// 0011 1100 0000 0011 1111 1111 0000 1111 = 1006894863
		CHECK(IOUtils::addBytesToInt(b1, b2, b3, b4) == 1006894863);
		//0000 1111 0011 1100 0000 0011 1111 1111 = 255591423
		CHECK(IOUtils::addBytesToInt(b2, b3, b4, b1) == 255591423);
		//1111 1111 0000 1111 0011 1100 0000 0011 = 4279188483
		CHECK(IOUtils::addBytesToInt(b3, b4, b1, b2) == 4279188483);
	}

	SECTION("Adding two bytes Big-Endian")
	{
		int b1 = 15;
		int b2 = 255;
		int b3 = 3;
		int b4 = 60;

		//0000 1111 1111 1111 = 4095
		CHECK(IOUtils::addBytesToIntBE(b1, b2) == 4095);
		//1111 1111 0000 0011 = 65283
		CHECK(IOUtils::addBytesToIntBE(b2, b3) == 65283);
		//0000 0011 0011 1100 = 828
		CHECK(IOUtils::addBytesToIntBE(b3, b4) == 828);
	}

	SECTION("Adding three bytes Big-Endian")
	{
		int b1 = 15;
		int b2 = 255;
		int b3 = 3;
		int b4 = 60;

		//0000 1111 1111 1111 0000 0011 = 1048323
		CHECK(IOUtils::addBytesToIntBE(b1, b2, b3) == 1048323);
		//1111 1111 0000 0011 0011 1100 = 16712508
		CHECK(IOUtils::addBytesToIntBE(b2, b3, b4) == 16712508);
		//0000 0011 0011 1100 0000 1111 = 211983
		CHECK(IOUtils::addBytesToIntBE(b3, b4, b1) == 211983);
	}

	SECTION("Adding four bytes Big-Endian")
	{
		int b1 = 15;
		int b2 = 255;
		int b3 = 3;
		int b4 = 60;

		//0000 1111 1111 1111 0000 0011 0011 1100 = 268370748
		CHECK(IOUtils::addBytesToIntBE(b1, b2, b3, b4) == 268370748);
		//1111 1111 0000 0011 0011 1100 0000 1111 = 4278402063
		CHECK(IOUtils::addBytesToIntBE(b2, b3, b4, b1) == 4278402063);
		//0000 0011 0011 1100 0000 1111 1111 1111 = 54267903
		CHECK(IOUtils::addBytesToIntBE(b3, b4, b1, b2) == 54267903);
	}

	SECTION("Adding bytes using array")
	{
		unsigned char b1[] = { 15, 255, 3, 60 };
		unsigned char b2[] = { 255, 3, 60, 15 };
		unsigned char b3[] = { 3, 60, 15, 255 };

		CHECK(IOUtils::addBytesToInt4(b1) == 1006894863);
		CHECK(IOUtils::addBytesToInt4(b2) == 255591423);
		CHECK(IOUtils::addBytesToInt4(b3) == 4279188483);
	}

	SECTION("Adding bytes using array and offset")
	{
		unsigned char b1[] = { 15, 255, 3, 60, 1, 127 };
		unsigned char b2[] = { 1, 44, 82, 255, 3, 60, 15 };
		unsigned char b3[] = { 111, 32, 222, 210, 3, 60, 15, 255 };

		CHECK(IOUtils::addBytesToInt4(b1, 0) == 1006894863);
		CHECK(IOUtils::addBytesToInt4(b2, 3) == 255591423);
		CHECK(IOUtils::addBytesToInt4(b3, 4) == 4279188483);
	}

	SECTION("Adding bytes using array Big-Endian")
	{
		unsigned char b1[] = { 15, 255, 3, 60 };
		unsigned char b2[] = { 255, 3, 60, 15 };
		unsigned char b3[] = { 3, 60, 15, 255 };

		CHECK(IOUtils::addBytesToInt4BE(b1) == 268370748);
		CHECK(IOUtils::addBytesToInt4BE(b2) == 4278402063);
		CHECK(IOUtils::addBytesToInt4BE(b3) == 54267903);
	}

	SECTION("Adding bytes using array and offset Big-Endian")
	{
		unsigned char b1[] = { 15, 255, 3, 60, 1, 127 };
		unsigned char b2[] = { 1, 44, 82, 255, 3, 60, 15 };
		unsigned char b3[] = { 111, 32, 222, 210, 3, 60, 15, 255 };

		CHECK(IOUtils::addBytesToInt4BE(b1, 0) == 268370748);
		CHECK(IOUtils::addBytesToInt4BE(b2, 3) == 4278402063);
		CHECK(IOUtils::addBytesToInt4BE(b3, 4) == 54267903);
	}

	SECTION("Creating a byte string")
	{
		std::string fifteen = IOUtils::createByteString(4,4);
		std::string fifteenBytes = "00001111";

		std::string three = IOUtils::createByteString(2, 6);
		std::string threeBytes = "00000011";

		CHECK(fifteen.compare(fifteenBytes) == 0);
		CHECK(three.compare(threeBytes) == 0);
	}

	SECTION("Converting bytes to string") 
	{
		const char *str1 = "Hello World";
		const char *str2 = "Oskar Mendel";

		std::string helloStr = IOUtils::getBytesToString(str1, strlen(str1));
		std::string nameStr = IOUtils::getBytesToString(str2, strlen(str2));

		CHECK(helloStr.compare("Hello World") == 0);
		CHECK(nameStr.compare("Oskar Mendel") == 0);
	}
}