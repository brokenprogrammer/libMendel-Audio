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

// Abstract base class for music files.
// Handles basic music file metadata, file and file path.
// Setters are implemented as abstract for the user to decide implementation.
class MusicFile
{
protected:
	FILE* file;					//File object for the music file.
	std::string filePath;		//Path to target music file.

	std::string artist;			//Artist metadata connected to file.
	std::string album;			//Album metadata connected to file.
	std::string title;			//Title metadata connected to file.
	std::string genre;			//Genre metadata connected to file.
	std::string trackNumber;	//Track number metadata connected to file.
	std::string date;			//Date metadata connected to file.

public:
	//Empty virtual destructor for propper cleanup.
	virtual ~MusicFile();

	//Returns a pointer to a file for this music file.
	FILE* getFile();
	//Pure virtual setter for the file for this music file.
	virtual void setFile(FILE* f) =0;

	//Returns the file path.
	std::string getFilePath();
	//Pure virutal setter for the file path.
	virtual void setFilePath(std::string path) = 0;

	//Returns the artist metadata of the music file.
	std::string getArtist();
	//Pure virtual setter for the artist of the music file.
	virtual void setArtist(std::string artist) = 0;

	//Returns the album metadata of the music file.
	std::string getAlbum();
	//Pure virtual setter for the album of the music file.
	virtual void setAlbum(std::string album) = 0;

	//Returns the title metadata of the music file.
	std::string getTitle();
	//Pure virtual setter for the title of the music file.
	virtual void setTitle(std::string title) = 0;

	//Returns the genre metadata of the music file.
	std::string getGenre();
	//Pure virtual setter for the genre of the music file.
	virtual void setGenre(std::string genre) = 0;

	//Returns the track number metadata of the music file.
	std::string getTrackNumber();
	//Pure virtual setter for the track number of the music file.
	virtual void setTrackNumber(std::string trackNumber) = 0;

	//Returns the date metadata of the music file.
	std::string getDate();
	//Pure virtual setter for the date of the music file.
	virtual void setDate(std::string date) = 0;
};

