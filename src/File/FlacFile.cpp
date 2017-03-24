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
#include <iostream>
#include <fstream>

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

int FlacFile::getMinimumBlockSize()
{
	return minimumBlockSize;
}

void FlacFile::setMinimumBlockSize(int size)
{
	minimumBlockSize = size;
}

int FlacFile::getMaximumBlockSize()
{
	return maximumBlockSize;
}

void FlacFile::setMaximumBlockSize(int size)
{
	maximumBlockSize = size;
}

int FlacFile::getMinimumFrameSize()
{
	return minimumFrameSize;
}

void FlacFile::setMinimumFrameSize(int size)
{
	minimumFrameSize = size;
}

int FlacFile::getMaximumFrameSize()
{
	return maximumFrameSize;
}

void FlacFile::setMaximumFrameSize(int size)
{
	maximumFrameSize = size;
}

int FlacFile::getSampleRate()
{
	return sampleRate;
}

void FlacFile::setSampleRate(int rate)
{
	sampleRate = rate;
}

int FlacFile::getNumChannels()
{
	return numChannels;
}

void FlacFile::setNumChannels(int channels)
{
	numChannels = channels;
}

int FlacFile::getBitsPerSample()
{
	return bitsPerSample;
}

void FlacFile::setBitsPerSample(int bits)
{
	bitsPerSample = bits;
}

int FlacFile::getNumSamples()
{
	return numSamples;
}

void FlacFile::setNumSamples(int samples)
{
	numSamples = samples;
}

std::string FlacFile::getVendor()
{
	return std::string();
}

void FlacFile::setVendor(std::string v)
{
	vendor = v;
}

void FlacFile::parse()
{
	//Temp code, Reads first 4 bytes of a file, if its a flac file it should print out
	//fLaC from the output stream.
	std::ifstream in(getFilePath());

	for (int i = 0; i < 4; i++) {
		char c = in.get();
		if (in.fail()) {
			std::cout << std::endl << "Error, closing.." << std::endl;
			break;
		}
		else {
			std::cout << c;
		}
	}
	std::cout << std::endl;
	in.close();
}
