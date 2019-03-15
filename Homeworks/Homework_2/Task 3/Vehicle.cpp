#include <iostream>

#include "Vehicle.h"

Vehicle::Vehicle() :year(0), mileage(0.0)
{
	this->SetMark("no mark");
	this->SetModel("no model");
	this->SetColor("no color");
}

Vehicle::Vehicle(const char* mark, const char* model, const char* color, int year, double mileage)
{
	this->SetMark(mark);
	this->SetModel(model);
	this->SetColor(color);
	this->SetYear(year);
	this->SetMileage(mileage);
}

Vehicle::~Vehicle()
{
	delete[]this->mark;
	delete[]this->model;
	delete[]this->color;
}

Vehicle & Vehicle::operator=(const Vehicle & other)
{
	if (this != &other)
	{
		delete[]this->mark;
		delete[]this->model;
		delete[]this->color;
		this->SetMark(other.GetMark());
		this->SetModel(other.GetModel());
		this->SetColor(other.GetColor());
		this->SetYear(other.GetYear());
		this->SetMileage(other.GetMileage());
	}
	return *this;
}

Vehicle::Vehicle(const Vehicle & other)
{
	this->SetMark(other.GetMark());
	this->SetModel(other.GetModel());
	this->SetColor(other.GetColor());
	this->SetYear(other.GetYear());
	this->SetMileage(other.GetMileage());
}

void Vehicle::SetMark(const char * mark)
{
	int i = 0;
	int l = strlen(mark);
	this->mark = new char[l + 1];
	for (i = 0; i < l; i++)
	{
		this->mark[i] = mark[i];
	}
	this->mark[i] = 0;
}

void Vehicle::SetModel(const char * model)
{
	int i = 0;
	int l = strlen(model);
	this->model = new char[l + 1];
	for (i = 0; i < l; i++)
	{
		this->model[i] = model[i];
	}
	this->model[i] = 0;
}

void Vehicle::SetColor(const char * color)
{
	int i = 0;
	int l = strlen(color);
	this->color = new char[l + 1];
	for (i = 0; i < l; i++)
	{
		this->color[i] = color[i];
	}
	this->color[i] = 0;
}

void Vehicle::SetYear(int year)
{
	if (year >= 0)
	{
		this->year = year;
	}
	else
	{
		std::cout << "The year is invalid!" << std::endl;
	}
}

void Vehicle::SetMileage(double mileage)
{
	if (mileage >= 0)
	{
		this->mileage = mileage;
	}
	else
	{
		std::cout << "Invalid mileage!" << std::endl;
	}
}

const char * Vehicle::GetMark() const
{
	return this->mark;
}

const char * Vehicle::GetModel() const
{
	return this->model;
}

const char * Vehicle::GetColor() const
{
	return this->color;
}

int Vehicle::GetYear() const
{
	return this->year;
}

double Vehicle::GetMileage() const
{
	return this->mileage;
}
void Vehicle::Details()const
{
	std::cout << "Brand: " << this->GetMark() << std::endl;
	std::cout << "Model: " << this->GetModel() << std::endl;
	std::cout << "Color: " << this->GetColor() << std::endl;
	std::cout << "Year: " << this->GetYear() << std::endl;
	std::cout << "Mileage: " << this->GetMileage() << std::endl;
}
