#pragma once

#include "Vehicle.h"

class Truck : public Vehicle
{
public:
	Truck();
	Truck(const char* mark, const char* model, const char* color, int year, double mileage, double size);
	void SetSize(double);
	double GetSize()const;
	~Truck() {};
	virtual void Details()const;
private:
	double size;
};