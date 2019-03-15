#include <iostream>

#include "Vehicle.h"
#include "Motorcycle.h"

Motorcycle::Motorcycle() :Vehicle()
{
	this->SetType("no type");
}

Motorcycle::Motorcycle(const char * mark, const char * model, const char * color, int year, double mileage, const char * type) :
	Vehicle(mark, model, color, year, mileage)
{
	this->SetType(type);
}

Motorcycle::Motorcycle(const Motorcycle & other) :Vehicle(other)
{
	this->SetType(other.GetType());
}

Motorcycle & Motorcycle::operator=(const Motorcycle & other)
{
	if (this != &other)
	{
		Vehicle::operator=(other);
		delete[] this->type;
		this->SetType(other.GetType());
	}
	return *this;
}

Motorcycle::~Motorcycle()
{
	delete[]this->type;
}

void Motorcycle::SetType(const char * type)
{
	int i = 0;
	int l = strlen(type);
	this->type = new char[l + 1];
	for (i = 0; i < l; i++)
	{
		this->type[i] = type[i];
	}
	this->type[i] = 0;
}

const char * Motorcycle::GetType() const
{
	return this->type;
}

void Motorcycle::Details() const
{
	Vehicle::Details();
	std::cout << "Type of motorcycle: " << this->GetType() << std::endl;
}
