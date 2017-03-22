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
#include"../src/libMendelAudio.h"
#include <iostream>

TEST_CASE("FlacFile") 
{

	SECTION("String constructor sets the file path")
	{
		FlacFile file("path/to/my/file");
		CHECK(std::string(file.getFilePath()).compare("path/to/my/file") == 0);
	}

	SECTION("File constructor sets the file and the path")
	{

	}

	SECTION("setFile sets the file")
	{

	}

	SECTION("setFilePath sets the file path")
	{
		FlacFile file;
		file.setFilePath("path/to/my/file");
		CHECK(std::string(file.getFilePath()).compare("path/to/my/file") == 0);

		FlacFile file2("path/to/my/file");
		CHECK(std::string(file2.getFilePath()).compare("path/to/my/file") == 0);
	}

	SECTION("setArtist sets the artist metadata")
	{
		FlacFile file;
		file.setArtist("Jimmy Ate World");
		CHECK(std::string(file2.getArtist()).compare("Jimmy Ate World") == 0);
	}

	/*FlacFile file;
	file.setTitle("The Middle");

	std::string mystr("The Middle");
	REQUIRE(std::string(file.getTitle()).compare(mystr) == 0);*/
}