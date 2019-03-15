#include <iostream>

#include "Vehicle.h"
#include "Truck.h"

Truck::Truck() :Vehicle()
{
	this->SetSize(0.0);
}

Truck::Truck(const char * mark, const char * model, const char * color, int year, double mileage, double size) :
	Vehicle(mark, model, color, year, mileage)
{
	this->SetSize(size);
}

void Truck::Details() const
{
	Vehicle::Details();
	std::cout << "Size of truck: " << this->GetSize() << std::endl;

}

void Truck::SetSize(double size)
{
	if (size >= 0)
	{
		this->size = size;
	}
	else
	{
		std::cout << "Invalid size!" << std::endl;
	}
}

double Truck::GetSize() const
{
	return this->size;
}
