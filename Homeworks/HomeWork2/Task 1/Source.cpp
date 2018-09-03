#include <iostream>

#include "ElectricNet.h"

int main()
{
	ElectricDevice e1("toaster", 76);
	ElectricDevice e2("refrigerator", 90);
	ElectricDevice e3("TV", 30);
	ElectricDevice e4("oven", 50);
	ElectricNet net(280);

	//add new devices
	net += e1;
	net += e2;
	net += e3;

	net++;
	net.Print();
	std::cout << std::endl;

	std::cout << "Checks if there are devices in the electric net: " <<!net << std::endl; 
	std::cout << std::endl;

	std::cout << net["refrigerator"] << std::endl; // get information about device
	std::cout << net["microwave"] << std::endl;
	--net;
	net -= "toaster"; //remove device
	net.Print();
	std::cout << "**************************************" << std::endl;
	ElectricNet net2(100);

	//add new device
	net2 = net + e1;
	net2 += e4;
	net2.Print();
	std::cout << std::endl;

	net2 -= "oven";	// remove the device 'oven' from 'net2'
	net2.Print();
	std::cout << std::endl;

	net2 = net - "refrigerator";  // remove the device 'refrigerator' from 'net'
	net2.Print();
	std::cout << std::endl;

	return 0;
}