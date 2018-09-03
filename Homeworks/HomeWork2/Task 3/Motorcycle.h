#pragma once

#include "Vehicle.h"

class Motorcycle :public Vehicle
{
public:
	Motorcycle();
	Motorcycle(const char* mark, const char* model, const char* color, int year, double mileage, const char* type);
	Motorcycle(const Motorcycle& other);
	Motorcycle& operator=(const Motorcycle& other);
	void SetType(const char* type);
	const char* GetType()const;
	~Motorcycle();
	virtual void Details()const;
private:
	char* type;
};