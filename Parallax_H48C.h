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