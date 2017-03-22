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

#include "FlacFile.h"

FlacFile::FlacFile()
{

}

FlacFile::FlacFile(std::string path)
{
	filePath = path;
	//populate file with the file at the specified path.
}

FlacFile::FlacFile(FILE * f)
{
	file = f;
	//Get the file path of file and populate filePath with the path.
}

FlacFile::~FlacFile()
{
}

void FlacFile::setFile(FILE * f)
{
	file = f;
}

void FlacFile::setFilePath(std::string path)
{
	filePath = path;
}

void FlacFile::setArtist(std::string a)
{
	artist = a;
}

void FlacFile::setAlbum(std::string a)
{
	album = a;
}

void FlacFile::setTitle(std::string t)
{
	title = t;
}

void FlacFile::setGenre(std::string g)
{
	genre = g;
}

void FlacFile::setTrackNumber(std::string t)
{
	trackNumber = t;
}

void FlacFile::setDate(std::string d)
{
	date = d;
}

//implement methods below
int FlacFile::getMinimumBlockSize()
{
	return 0;
}

void FlacFile::setMinimumBlockSize()
{
}

int FlacFile::getMaximumBlockSize()
{
	return 0;
}

void FlacFile::setMaximumBlockSize()
{
}

int FlacFile::getMinimumFrameSize()
{
	return 0;
}

void FlacFile::setMinimumFrameSize()
{
}

int FlacFile::getSampleRate()
{
	return 0;
}

void FlacFile::setSampleRate()
{
}

int FlacFile::getNumChannels()
{
	return 0;
}

void FlacFile::setNumChannels()
{
}

int FlacFile::getBitsPerSample()
{
	return 0;
}

void FlacFile::setBitsPerSample()
{
}

int FlacFile::getNumSamples()
{
	return 0;
}

void FlacFile::setNumSamples()
{
}

std::string FlacFile::getVendor()
{
	return std::string();
}

void FlacFile::setVendor()
{
}

void FlacFile::parse()
{
}
