#include "ElectricDevice.h"

ElectricDevice::ElectricDevice() : power(0)
{
	this->SetName("no name");
}

ElectricDevice::ElectricDevice(const char* name, int power)
{
	this->SetName(name);
	this->SetPower(power);
}

ElectricDevice::~ElectricDevice()
{
	delete[] this->name;
}

void ElectricDevice::SetName(const char * name)
{
	int i = 0;
	int l = strlen(name);
	this->name = new char[l + 1];
	for (i = 0; i < l; i++)
	{
		this->name[i] = name[i];
	}
	this->name[i] = 0;
}

void ElectricDevice::SetPower(int power)
{
	if (power >= 0)
	{
		this->power = power;
	}
	else
	{
		std::cout << "Invalid power!" << std::endl;
	}
}

const char * ElectricDevice::GetName() const
{
	return this->name;
}

int ElectricDevice::GetPower() const
{
	return this->power;
}

ElectricDevice& ElectricDevice::operator=(const ElectricDevice& other)
{
	if (this != &other)
	{
		delete[]this->name;
		this->SetName(other.GetName());
		this->SetPower(other.GetPower());
	}
	return *this;
}

ElectricDevice::ElectricDevice(const ElectricDevice & other)
{
	this->SetName(other.GetName());
	this->SetPower(other.GetPower());
}

std::ostream& operator<<(std::ostream& os, const ElectricDevice& e)
{
	os << "Name of device: " << e.GetName() << std::endl;
	os << "Power of device: " << e.GetPower() << std::endl;

	return os;
}