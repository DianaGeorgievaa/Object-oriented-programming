#include <iostream>

#include "ElectricNet.h"

ElectricNet::ElectricNet()
{
	this->maxLength = SIZE;
	this->electricDevice = new ElectricDevice[this->maxLength];
	this->numberOfElectricDevices = 0;
	this->SetMaxConsumation(0);
}

ElectricNet::ElectricNet(int maxConsumation)
{
	if (maxConsumation > 0)
	{
		this->SetMaxConsumation(maxConsumation);
		this->maxLength = SIZE;
		this->electricDevice = new ElectricDevice[maxLength];
		this->numberOfElectricDevices = 0;
	}
}


ElectricNet::~ElectricNet()
{
	delete[]this->electricDevice;
}

void ElectricNet::SetMaxConsumation(int maxConsumation)
{
	if (maxConsumation >= 0)
	{
		this->maxConsumation = maxConsumation;
	}
	else
	{
		std::cout << "Invalid number for maximal consumation!" << std::endl;
	}
}

int ElectricNet::GetMaxConsumation() const
{
	return this->maxConsumation;
}

ElectricNet::ElectricNet(const ElectricNet& other)
{
	this->SetMaxConsumation(other.GetMaxConsumation());
	this->numberOfElectricDevices = other.numberOfElectricDevices;
	this->maxLength = other.maxLength;
	this->electricDevice = new ElectricDevice[this->maxLength];
	for (int i = 0; i < this->numberOfElectricDevices; i++)
	{
		this->electricDevice[i].SetName(other.electricDevice[i].GetName());
		this->electricDevice[i].SetPower(other.electricDevice[i].GetPower());
	}
}

ElectricNet& ElectricNet::operator=(const ElectricNet& other)
{
	if (this != &other)
	{
		delete[]this->electricDevice;
		this->SetMaxConsumation(other.GetMaxConsumation());
		this->numberOfElectricDevices = other.numberOfElectricDevices;
		this->maxLength = other.maxLength;
		this->electricDevice = new ElectricDevice[this->maxLength];
		for (int i = 0; i < this->numberOfElectricDevices; i++)
		{
			this->electricDevice[i].SetName(other.electricDevice[i].GetName());
			this->electricDevice[i].SetPower(other.electricDevice[i].GetPower());
		}
	}
	return *this;
}

void ElectricNet::Print() const
{
	for (int i = 0; i < this->numberOfElectricDevices; i++)
	{
		std::cout << "The name of the electric device: " << this->electricDevice[i].GetName() << std::endl;
		std::cout << "The power of the electric device: " << this->electricDevice[i].GetPower() << std::endl;
	}
}

ElectricNet ElectricNet::operator+(const ElectricDevice& device)
{
	ElectricNet e(this->GetMaxConsumation() + device.GetPower());
	e.numberOfElectricDevices = this->numberOfElectricDevices;
	e.maxLength = this->maxLength + 1;
	int i;
	for (i = 0; i <= e.numberOfElectricDevices - 1; i++)
	{
		e.electricDevice[i].SetName(this->electricDevice[i].GetName());
		e.electricDevice[i].SetPower(this->electricDevice[i].GetPower());
	}
	e.electricDevice[i].SetName(device.GetName());
	e.electricDevice[i].SetPower(device.GetPower());
	e.numberOfElectricDevices++;

	return e;
}

ElectricNet& ElectricNet::operator+=(const ElectricDevice & device)
{
	int sumPower = 0;
	for (int i = 0; i < this->numberOfElectricDevices; i++)
	{
		sumPower = sumPower + this->electricDevice[i].GetPower();

	}
	sumPower += device.GetPower();
	if (sumPower <= maxConsumation)
	{  
		if (this->numberOfElectricDevices + 1 >= maxLength)
		{
			Resize();
		}
		this->electricDevice[numberOfElectricDevices] = device;
		this->numberOfElectricDevices++;
	}
	else
	{  
		std::cout << "The electric device can't be added!" << std::endl;
	}
	return *this;
}

ElectricNet ElectricNet::operator-(const char * name)
{  
	if (this->numberOfElectricDevices - 1 >= 0)
	{
		ElectricNet e(this->GetMaxConsumation());
		e.maxLength = this->maxLength;
		e.numberOfElectricDevices = this->numberOfElectricDevices;
		bool isFind = false;
		int index = 0;
		for (int i = 0; i < this->numberOfElectricDevices; i++)
		{
			if (strcmp(this->electricDevice[i].GetName(), name) != 0)
			{
				e.electricDevice[index].SetName(this->electricDevice[i].GetName());
				e.electricDevice[index].SetPower(this->electricDevice[i].GetPower());
				index++;
			}
			else
			{
				isFind = true;
			}
		}
		if (isFind == true)
		{
			e.numberOfElectricDevices--;
		}
		return e;
	}
	else
	{
		std::cout << "Can not remove device from electric net!" << std::endl;
		return *this;
	}
}

ElectricNet&  ElectricNet::operator-=(const char * name)
{
	if (this->numberOfElectricDevices - 1 >= 0)
	{
		ElectricDevice * newArr = new ElectricDevice[this->numberOfElectricDevices - 1];
		bool isFind = false;
		int newInd = 0;
		for (int i = 0; i < this->numberOfElectricDevices; i++)
		{
			if (strcmp(this->electricDevice[i].GetName(), name) != 0)
			{
				newArr[newInd].SetName(this->electricDevice[i].GetName());
				newArr[newInd].SetPower(this->electricDevice[i].GetPower());
				newInd++;
			}
			else
			{
				isFind = true;
			}
		}
		delete[]this->electricDevice;
		this->electricDevice = newArr;
		if (isFind == true)
		{
			this->numberOfElectricDevices--;
		}
		else
		{
			std::cout << "There is no device with name: " << name << std::endl;
		}
	}
	else
	{
		std::cout << "Can not remove device from electric net!" << std::endl;
	}
	return *this;
}

bool ElectricNet::operator!()
{  
	if (this->numberOfElectricDevices - 1 >= 0)
	{
		return true;
	}
	return false;
}

ElectricNet& ElectricNet::operator++()
{  
	this->SetMaxConsumation(this->GetMaxConsumation() * 2);
	return *this;
}

ElectricNet& ElectricNet::operator++(int n)
{
	n = 2;
	this->SetMaxConsumation(this->GetMaxConsumation() * n);
	return *this;
}

ElectricNet& ElectricNet::operator--()
{
	int sum = 0;
	int newMaxConsumation = this->maxConsumation / 2;
	for (int i = 0; i < this->numberOfElectricDevices; i++)
	{
		sum = sum + electricDevice[i].GetPower();
	}
	if (newMaxConsumation >= sum)
	{
		this->SetMaxConsumation(newMaxConsumation);
	}
	else
	{
		std::cout << "The power can't be reduced!" << std::endl;
	}
	return *this;
}

ElectricNet& ElectricNet::operator--(int n)
{
	int sum = 0;
	n = 2;
	int newMaxConsumation = this->maxConsumation / n;
	for (int i = 0; i < this->numberOfElectricDevices; i++)
	{
		sum = sum + electricDevice[i].GetPower();
	}
	if (newMaxConsumation >= sum)
	{
		this->SetMaxConsumation(newMaxConsumation);
	}
	else
	{
		std::cout << "The power can't be reduced!" << std::endl;
	}
	return *this;
}

ElectricDevice ElectricNet::operator[](const char * name)
{
	bool isFind = false;
	for (int i = 0; i < numberOfElectricDevices; i++)
	{
		if (strcmp(this->electricDevice[i].GetName(), name) == 0)
		{
			isFind = true;
			return this->electricDevice[i];
		}
	}
	if (isFind == false)
	{
		std::cout << "Can not find device by name: " << name << std::endl;
	}
	return ElectricDevice(); 
}

void ElectricNet::Resize()
{
	ElectricDevice* newArr = new ElectricDevice[maxLength * 2];
	for (int i = 0; i < this->numberOfElectricDevices; i++)
	{
		newArr[i].SetName(this->electricDevice[i].GetName());
		newArr[i].SetPower(this->electricDevice[i].GetPower());
	}
	delete[]this->electricDevice;
	this->electricDevice = newArr;
	this->maxLength = maxLength * 2;
}
