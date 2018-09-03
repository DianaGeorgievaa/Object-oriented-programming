#pragma once

#include<iostream>

class ElectricDevice
{
public:
	ElectricDevice();
	ElectricDevice(const char* name, int power);
    ElectricDevice(const ElectricDevice & other);
    ElectricDevice &operator=(const ElectricDevice & other);
	void SetName(const char*name);
	void SetPower(int);
	const char*GetName()const;
	int GetPower()const;
    friend std::ostream &operator<<(std::ostream &os, const ElectricDevice & e);
   ~ElectricDevice();
private:
	char*name;
	int power;
};

