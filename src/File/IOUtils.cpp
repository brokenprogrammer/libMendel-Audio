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

#include "IOUtils.h"

void IOUtils::readBytes(std::ifstream& input, char * b, int len)
{
	readBytes(input, b, len, 0);
}

void IOUtils::readBytes(std::ifstream& input, char * b, int len, int off)
{
	// TODO: Implement error checking.
	input.seekg(input.tellg()+=off);
	input.read(b, len);
}

BYTE IOUtils::intToByte(int i)
{
	//The given integer is too large for a byte.
	if (i > 256) {
		// Throw exception.
	}

	if (i > 127) {
		return (BYTE)(i - 256);
	}
	return (BYTE)i;
}

int IOUtils::byteToInt(BYTE b)
{
	return b;
}

int IOUtils::getBitAt(char b, int pos)
{
	return (b >> pos) & 1;
}

int IOUtils::getBitAtBE(char b, int pos)
{
	return (b >> (7-pos)) & 1;
}

int IOUtils::getTopNibble(char b)
{
	return (b >> 4) & 0x0F;
}

int IOUtils::getBottomNibble(char b)
{
	return (b & 0x0F);
}

int IOUtils::getTopNibble(int i)
{
	return (i >> 4) & 0x0F;
}

int IOUtils::getBottomNibble(int i)
{
	return (i & 0x0F);
}

int IOUtils::addBytesToInt(int x1, int x2)
{
	return (x2 << 8) | (x1 & 0xFF);
}

long IOUtils::addBytesToInt(int x1, int x2, int x3)
{
	return (x3 << 16) | (x2 << 8) | (x1 & 0xFF);
}

long int IOUtils::addBytesToInt(int x1, int x2, int x3, int x4)
{
	return (x4 << 24) | (x3 << 16) | (x2 << 8) | (x1 & 0xFF);
}

int IOUtils::addBytesToIntBE(int x1, int x2)
{
	return (x1 << 8) | (x2 & 0xFF);
}

long IOUtils::addBytesToIntBE(int x1, int x2, int x3)
{
	return (x1 << 16) | (x2 << 8) | (x3 & 0xFF);
}

long IOUtils::addBytesToIntBE(int x1, int x2, int x3, int x4)
{
	return (x1 << 24) | (x2 << 16) | (x3 << 8) | (x4 & 0xFF);
}

long IOUtils::addBytesToInt4(unsigned char * b)
{
	return addBytesToInt4(b, 0);
}

long IOUtils::addBytesToInt4(unsigned char * b, int off)
{
	int i = off;
	int x1 = b[i++] & 0xFF;
	int x2 = b[i++] & 0xFF;
	int x3 = b[i++] & 0xFF;
	int x4 = b[i++] & 0xFF;

	return addBytesToInt(x1, x2, x3, x4);
}

long IOUtils::addBytesToInt4BE(unsigned char * b)
{
	return addBytesToInt4BE(b, 0);
}

long IOUtils::addBytesToInt4BE(unsigned char * b, int off)
{
	int i = off;
	int x1 = b[i++] & 0xFF;
	int x2 = b[i++] & 0xFF;
	int x3 = b[i++] & 0xFF;
	int x4 = b[i++] & 0xFF;

	return addBytesToIntBE(x1, x2, x3, x4);
}

std::string IOUtils::createByteString(int bits, int offset)
{
	if (bits > 8 || (bits+offset) > 8) {
		//Throw exception
	}

	int populated = 0;
	std::string s = "";

	for (int x = 0; x < offset; x++) {
		s += "0";
		populated++;
	}

	for (int x = 0; x < bits; x++) {
		s += "1";
		populated++;
	}

	for (int x = populated; x < 8; x++) {
		s += "0";
	}

	return s;
}

std::string IOUtils::getBytesToString(const char * b, size_t len)
{
	//TODO: Change parameter to unsigned char* and add offset parameter.
	//TODO: Make a new const char* taking all content from target offset
	//TODO: from the unsigned char*
	return std::string(b, len);
}
