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

#include <string>
#include <stdio.h>

class MusicFile
{
protected:
	FILE* file;
	std::string filePath;

	std::string artist;
	std::string album;
	std::string title;
	std::string genre;
	std::string trackNumber;
	std::string date;

public:
	FILE* getFile();
	virtual void setFile(FILE* f) =0;

	std::string getFilePath();
	virtual void setFilePath(std::string path) = 0;

	std::string getArtist();
	virtual void setArtist(std::string artist) = 0;

	std::string getAlbum();
	virtual void setAlbum(std::string album) = 0;

	std::string getTitle();
	virtual void setTitle(std::string title) = 0;

	std::string getGenre();
	virtual void setGenre(std::string genre) = 0;

	std::string getTrackNumber();
	virtual void setTrackNumber(std::string trackNumber) = 0;

	std::string getDate();
	virtual void setDate(std::string date) = 0;
};

