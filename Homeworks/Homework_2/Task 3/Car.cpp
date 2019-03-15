#include "Car.h"
#include "Vehicle.h"

Car::Car(const char* mark, const char* model, const char* color, int year, double mileage):Vehicle(mark,model,color,year,mileage)
{
}

Car::Car():Vehicle()
{
}

Car & Car::operator=(const Car & other)
{
	if (this != &other)
	{
		Vehicle::operator=(other);
	}
	return *this;
}

Car::Car(const Car & other):Vehicle(other)
{
}

Car::~Car()
{
}

void Car:: Details()const
{
	Vehicle::Details();
}
