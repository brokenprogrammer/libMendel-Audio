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

// Provides IO Utilities like functions to handle and read bit operations.
class IOUtils
{
public:
	// Reads the ifstream and populates the char array b with the next len bytes
	// if the end of file was reached an exception will be thrown.
	static void readBytes(std::ifstream input, char* b, int len);

	// Reads the ifstream and populates the char array b with the next len bytes
	// starting from the offset. If the end of file was reached an 
	// exception will be thrown.
	static void readBytes(std::ifstream input, char* b, int len, int off);

	// Converts an integer to a signed byte.
	static char intToByte(int i);

	// Converts a byte into an integer value.
	static int  byteToInt(char b);

	// Retrieves the bit at specified position.
	static int  getBitAt(char b, int pos);

	// Retrueves the bit at specified position using Big-Endian approach.
	static int  getBitAtBE(char b, int pos);

	// Returns the top four bits within a byte.
	static int  getTopNibble(char b);

	// Returns the bottom four bits within a byte.
	static int  getBottomNibble(char b);

	// Returns the top four bits within an integer.
	static int  getTopNibble(int i);

	// Returns the bottom four bits within an integer.
	static int  getBottomNibble(int i);
	
	// Combines two bytes into a number.
	static int  addBytesToInt(int x1, int x2);

	// Combies three bytes into a number.
	static long addBytesToInt(int x1, int x2, int x3);

	// Combines four bytes into a number.
	static long addBytesToInt(int x1, int x2, int x3, int x4);

	// Combines two bytes into a number using Big-Endian approach.
	static int  addBytesToIntBE(int x1, int x2);

	// Combines three bytes into a number using Big-Endian approach.
	static long addBytesToIntBE(int x1, int x2, int x3);

	// Combines four bytes into a number using Big-Endian approach.
	static long addBytesToIntBE(int x1, int x2, int x3, int x4);

	// Combines four bytes into a number from a byte array.
	static long addBytesToInt4(char* b);

	// Combines four bytes into a number from a byte array starting from specified offset.
	static long addBytesToInt4(char* b, int off);

	// Combines four bytes into a number from a byte array using an Big-Endian approach.
	static long addBytesToInt4BE(char* b);

	// Combines four bytes into a number from a byte array using an Big-Endian approach
	// from specified offeset.
	static long addBytesToInt4BE(char* b, int off);

	// Creates a string of specified amount of bits at the target offset.
	static std::string createByteString(int bits, int offset);

	// Converts a set of bytes into human readable form.
	static std::string getBytesToString(char* b, int offset, int len);
};
