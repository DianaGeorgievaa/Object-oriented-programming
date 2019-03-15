#pragma once

#include "Vehicle.h"

class Car : public Vehicle
{
public:
	Car();
	Car(const char* mark, const char* model, const char* color, int year, double mileage);
	Car(const Car& other);
	Car &operator=(const Car& other);
	~Car();
	virtual void Details()const;
};
