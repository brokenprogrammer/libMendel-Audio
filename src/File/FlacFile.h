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

#include "MusicFile.h"

class FlacFile : public MusicFile
{
public:
	FlacFile();

	//Constructs a new FlacFile object and directly populates it with data from the
	//file at the specified path.
	FlacFile(std::string path);

	//Constructs a new FlacFile object and directly populates it with data from the 
	//specified FILE.
	FlacFile(FILE * f);

	~FlacFile();

	// Inherited via MusicFile

	//Setter for the file for this flac file.
	void setFile(FILE * f) override;

	//Setter for the file path.
	void setFilePath(std::string path) override;

	//Setter for the artist of the flac file.
	void setArtist(std::string a) override;

	//Setter for the album of the flac file.
	void setAlbum(std::string a) override;

	//Setter for the title of the flac file.
	void setTitle(std::string t) override;

	//Setter for the genre of the flac file.
	void setGenre(std::string g) override;

	//Setter for the track number of the flac file.
	void setTrackNumber(std::string t) override;

	//Setter for the date of the flac file.
	void setDate(std::string d) override;

	//Returns the minimum block size of the song.
	int getMinimumBlockSize();
	//Setter for the minimum block size.
	void setMinimumBlockSize();

	//Returns the maximum block size of the song.
	int getMaximumBlockSize();
	//Setter for the maximum block size.
	void setMaximumBlockSize();

	//Returns the minimum frame size of the song.
	int getMinimumFrameSize();
	//Setter for the minimum frame size.
	void setMinimumFrameSize();

	//Returns the maximum frame size of the song.
	int getMaximumFrameSize();
	//Setter for the maximum frame size.
	void setMaximumFrameSize();

	//Returns the sample rate of the song.
	int getSampleRate();
	//Setter for the sample rate.
	void setSampleRate();

	//Returns the number of channels in the song.
	int getNumChannels();
	//Setter for the number of channels.
	void setNumChannels();

	//Returns the number of bits per sample.
	int getBitsPerSample();
	//Setter for the number of bits per sample.
	void setBitsPerSample();

	//Returns the number of samples.
	int getNumSamples();
	//Setter for the number of samples.
	void setNumSamples();

	//Returns the Vendor from the Vorbis comments.
	std::string getVendor();
	//Setter for the Vendor of the Vorbis comments.
	void setVendor();

private:
	int minimumBlockSize;
	int maximumBlockSize;
	int minimumFrameSize;
	int maximumFrameSize;

	int sampleRate;
	int numChannels;
	int bitsPerSample;
	int numSamples;

	//Data from the vorbis comment within the Flac file;
	std::string vendor;

	//Initializes the parsing of data for the FlacFile.
	void parse();
};

