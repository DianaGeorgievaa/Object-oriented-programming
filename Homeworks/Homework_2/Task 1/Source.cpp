#include <iostream>

#include "ElectricNet.h"

int main()
{
	ElectricDevice e1("toaster", 76);
	ElectricDevice e2("refrigerator", 90);
	ElectricDevice e3("TV", 30);
	ElectricDevice e4("oven", 50);
	ElectricNet net(280);

	net += e1;
	net += e2;
	net += e3;

	net++;
	net.Print();
	std::cout << std::endl;

	std::cout << "Checks if there are devices in the electric net: " <<!net << std::endl; 
	std::cout << std::endl;

	std::cout << net["refrigerator"] << std::endl; 
	std::cout << net["microwave"] << std::endl;
	--net;
	net -= "toaster"; 
	net.Print();
	std::cout << "**************************************" << std::endl;
	ElectricNet net2(100);

	net2 = net + e1;
	net2 += e4;
	net2.Print();
	std::cout << std::endl;

	net2 -= "oven";	
	net2.Print();
	std::cout << std::endl;

	net2 = net - "refrigerator";  
	net2.Print();
	std::cout << std::endl;

	return 0;
}
