/**
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

package me.oskarmendel.libMendelAudio.flac;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;

import me.oskarmendel.libMendelAudio.MusicFile;

/**
 * Object to represent files of the Flac format.
 * Implemented using the formatting for Flac files represented here:
 * https://xiph.org/flac/format.html
 *
 * @author Oskar Mendel
 * @version 0.00.00
 * @name FlacFile.groovy
 */
public class FlacFile extends MusicFile{
	
	private int minimumBlockSize;	//Represented as 16 bits
	private int maximumBlockSize;	//Represented as 16 bits
	private int minimumFrameSize;	//Represented as 24 bits
	private int maximumFrameSize;	//Represented as 24 bits
	
	private int sampleRate;			//Represented as 20 bits
	private int numChannels;		//Represented as 3 bits
	private int bitsPerSample;		//Represented as 5 bits
	private int numSamples;			//Represented as 36 bits
	
	//Data from the Vorbis Comments within the Flac file.
	String vendor;
	
	public FlacFile() {
		
	}
	
	/**
	 * Constructs a new FlacFile object and directly populates it with data
	 * from the specified file at the target file path.
	 * 
	 * @param path - Path of the Flac file.
	 * @throws IOException 
	 * @throws FileNotFoundException 
	 */
	public FlacFile(String path) throws FileNotFoundException, IOException {
		this.filePath = path;
		this.file = new File(this.filePath);
		
		parse();
	}
	
	/**
	 * Constructs a new FlacFile object and directly populates it with data
	 * from the specified file object.
	 * 
	 * @param file - File object to retrieve data from.
	 * @throws IOException 
	 * @throws FileNotFoundException 
	 */
	public FlacFile(File file) throws FileNotFoundException, IOException {
		this.file = file;
		this.filePath = "$file";
		
		parse();
	}

	/**
	 * Initializes the parsing of data using the FlacParser class.
	 * @throws IOException 
	 * @throws FileNotFoundException 
	 * @throws IllegalArgumentException - When the FlacFile doesn't have an initialized file and filepath.
	 */
	@Override
	public void parse() throws FileNotFoundException, IOException {
		if(this.file == null || this.filePath == null) {
			throw new IllegalArgumentException("File and file path is not initialized!");
		}
		FlacParser.parseFlacFile(this.file, this);
	}

	/**
	 * @return the minimumBlockSize
	 */
	public int getMinimumBlockSize() {
		return minimumBlockSize;
	}

	/**
	 * @param minimumBlockSize the minimumBlockSize to set
	 */
	public void setMinimumBlockSize(int minimumBlockSize) {
		this.minimumBlockSize = minimumBlockSize;
	}

	/**
	 * @return the maximumBlockSize
	 */
	public int getMaximumBlockSize() {
		return maximumBlockSize;
	}

	/**
	 * @param maximumBlockSize the maximumBlockSize to set
	 */
	public void setMaximumBlockSize(int maximumBlockSize) {
		this.maximumBlockSize = maximumBlockSize;
	}

	/**
	 * @return the minimumFrameSize
	 */
	public int getMinimumFrameSize() {
		return minimumFrameSize;
	}

	/**
	 * @param minimumFrameSize the minimumFrameSize to set
	 */
	public void setMinimumFrameSize(int minimumFrameSize) {
		this.minimumFrameSize = minimumFrameSize;
	}

	/**
	 * @return the maximumFrameSize
	 */
	public int getMaximumFrameSize() {
		return maximumFrameSize;
	}

	/**
	 * @param maximumFrameSize the maximumFrameSize to set
	 */
	public void setMaximumFrameSize(int maximumFrameSize) {
		this.maximumFrameSize = maximumFrameSize;
	}

	/**
	 * @return the sampleRate
	 */
	public int getSampleRate() {
		return sampleRate;
	}

	/**
	 * @param sampleRate the sampleRate to set
	 */
	public void setSampleRate(int sampleRate) {
		this.sampleRate = sampleRate;
	}

	/**
	 * @return the numChannels
	 */
	public int getNumChannels() {
		return numChannels;
	}

	/**
	 * @param numChannels the numChannels to set
	 */
	public void setNumChannels(int numChannels) {
		this.numChannels = numChannels;
	}

	/**
	 * @return the bitsPerSample
	 */
	public int getBitsPerSample() {
		return bitsPerSample;
	}

	/**
	 * @param bitsPerSample the bitsPerSample to set
	 */
	public void setBitsPerSample(int bitsPerSample) {
		this.bitsPerSample = bitsPerSample;
	}

	/**
	 * @return the numSamples
	 */
	public int getNumSamples() {
		return numSamples;
	}

	/**
	 * @param numSamples the numSamples to set
	 */
	public void setNumSamples(int numSamples) {
		this.numSamples = numSamples;
	}

	/**
	 * @return the vendor
	 */
	public String getVendor() {
		return vendor;
	}

	/**
	 * @param vendor the vendor to set
	 */
	public void setVendor(String vendor) {
		this.vendor = vendor;
	}
}