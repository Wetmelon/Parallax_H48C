// Written by Wetmelon
// March 30 2015

// The MIT License (MIT)

// Copyright (c) <year> <copyright holders>

// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the // rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE // AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN // THE SOFTWARE.

// Parallax_H48C.h

#ifndef Parallax_H48C_h
#define Parallax_H48C_h
	#include "Arduino.h"
	
#define VRef	0x1B
#define	XAxis	0x18
#define	YAxis	0x19
#define ZAxis	0x1A

#define ConvG	0.002200

class Parallax_H48C
{
 protected:
	 uint16_t reference;
	 float axisVals[3];

	 uint8_t dataPin;
	 uint8_t clockPin;
	 uint8_t chipSelect;

	 void writeData(uint8_t val);
	 uint16_t readRegister(uint8_t reg);
	 uint16_t getData();
	 uint16_t readReference();	// Reads the reference voltage

	 float convertToG(uint16_t);

 public:
	 float readXAxis();	// Reads only the X axis
	 float readYAxis();	// Reads only the Y axis
	 float readZAxis();	// Reads only the Z axis
	 float* readAllAxes();	// Reads all axes { X, Y, Z }

	 Parallax_H48C(uint8_t dataPin, uint8_t clockPin, uint8_t chipSelect);
};

#endif // !Parallax_H48C_h