// 
// 
// 

#include "Parallax_H48C.h"

Parallax_H48C::Parallax_H48C(uint8_t dataPin, uint8_t clockPin, uint8_t chipSelect)
{
	this->dataPin = dataPin;
	this->clockPin = clockPin;
	this->chipSelect = chipSelect;

	pinMode(this->clockPin, OUTPUT);
	pinMode(this->chipSelect, OUTPUT);
	digitalWrite(this->chipSelect, HIGH);
}

uint16_t Parallax_H48C::readRegister(uint8_t reg)
{
	pinMode(this->dataPin, OUTPUT);
	digitalWrite(this->chipSelect, LOW);
	writeData(reg<<3);
	pinMode(this->dataPin, INPUT);
	uint16_t nRet = getData();
	digitalWrite(this->chipSelect, HIGH);
	return nRet;
}

uint16_t Parallax_H48C::readReference()
{
	return readRegister(VRef);
}

float Parallax_H48C::convertToG(uint16_t val)
{
	uint16_t ref = readReference();
	return ((val >= ref) ? ((val - ref)*ConvG) : -1*((ref - val)*ConvG));
}

uint16_t Parallax_H48C::getData() {
	uint16_t value = 0;
	uint16_t i;

	for (i = 0; i < 13; ++i) {
		digitalWrite(clockPin, HIGH);
		digitalWrite(clockPin, LOW);
		value |= digitalRead(dataPin) << (12 - i);
	}
	return value;
}

float Parallax_H48C::readXAxis()
{
	return convertToG(readRegister(XAxis));
}

float Parallax_H48C::readYAxis()
{
	return convertToG(readRegister(YAxis));
}

float Parallax_H48C::readZAxis()
{
	return convertToG(readRegister(ZAxis));
}

float* Parallax_H48C::readAllAxes()
{
	this->axisVals[0] = readXAxis();
	this->axisVals[1] = readYAxis();
	this->axisVals[2] = readZAxis();
	return axisVals;
}

void Parallax_H48C::writeData(uint8_t val)
{
	uint8_t i;

	for (i = 0; i < 5; i++)  {
		digitalWrite(this->dataPin, !!(val & (1 << (7 - i))));
		digitalWrite(this->clockPin, HIGH);
		digitalWrite(this->clockPin, LOW);
	}
}