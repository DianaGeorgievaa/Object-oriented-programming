#pragma once

class Vehicle //abstract base class
{
public:
	Vehicle();
	Vehicle(const char* mark, const char* model, const char* color, int year, double mileage);
	Vehicle(const Vehicle& other);
	Vehicle & operator=(const Vehicle& other);
	void SetMark(const char* mark);
	void SetModel(const char* model);
	void SetColor(const char* color);
	void SetYear(int year);
	void SetMileage(double mileage);
	const char* GetMark()const;
	const char* GetModel()const;
	const char* GetColor()const;
	int GetYear()const;
	double GetMileage()const;
	virtual ~Vehicle();
	virtual void Details()const = 0;//print
private:
	char* mark;
	char*model;
	char*color;
	int year;
	double mileage;
};