#include <iostream>

#include "Store.h"

const int MAX_SIZE = 50;

int main()
{
	Store store;
	Product product;
	while (true)
	{
		std::cout << "Choose A to Add new product" << std::endl;
		std::cout << "Choose X to Delete a product" << std::endl;
		std::cout << "Choose C to Change a product" << std::endl;
		std::cout << "Choose D to Display the products" << std::endl;
		std::cout << "Choose Q to Quite" << std::endl;
		char choice;
		char* SKU = new char[MAX_SIZE];
		std::cout << "Please,enter your choice:";
		std::cin >> choice;
		switch (toupper(choice))
		{
		case 'A':
			std::cin >> product;
			store.Add(product);
			break;
		case 'X':
			std::cout << "Enter SKU: ";
			std::cin >> SKU;
			store.DeleteProduct(SKU);
			break;
		case 'C':
			std::cout << "Enter SKU: ";
			std::cin >> SKU;
			store.Change(SKU);
			break;
		case 'D':
			store.Display();
			break;
		case 'Q':
			exit(0);
		default:
			std::cout << "Your choice is invalid!" << std::endl;
			break;
		}
	}
	return 0;
}
