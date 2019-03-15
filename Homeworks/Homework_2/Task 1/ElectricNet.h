#pragma once

#include "ElectricDevice.h"

class ElectricNet
{
public:
	ElectricNet();
	ElectricNet(int maxConsumation);
	ElectricNet(const ElectricNet& other);
	ElectricNet& operator=(const ElectricNet& other);
	void SetMaxConsumation(int maxConsumation);
	int GetMaxConsumation()const;
	void Print()const;
	ElectricNet operator+(const ElectricDevice& device);// add electric device
	ElectricNet& operator+=(const ElectricDevice & device);
	ElectricNet operator-(const char* name);// remove electric device
	ElectricNet& operator-=(const char*name);
	bool operator!();// check if there are any electric devices in the net
	ElectricNet& operator++();//prefix, increase the power
	ElectricNet& operator++(int);//postfix
	ElectricNet& operator--();//prefix,reduce the power
	ElectricNet& operator--(int);//postfix
	ElectricDevice operator[](const char* name);
	~ElectricNet();
private:
	void Resize();

	enum { SIZE = 50 };
	int maxConsumation;
	ElectricDevice * electricDevice;
	int maxLength;
	int numberOfElectricDevices;
};
