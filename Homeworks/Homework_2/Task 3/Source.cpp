#include <iostream>

#include "Car.h"
#include "Truck.h"
#include "Motorcycle.h"

int main()
{
	Car car("BMW", "I8", "black", 2017, 7659);
	car.Details();
	std::cout << "*************************************" << std::endl;
	Truck truck("Volvo", "Fl280", "white", 2002, 654, 65);
	truck.Details();
	std::cout << "*************************************" << std::endl;
	Motorcycle motorcycle("Yamaha", "FJR1300", "black", 2015, 3420, "touring");
	motorcycle.Details();

	return 0;
}
