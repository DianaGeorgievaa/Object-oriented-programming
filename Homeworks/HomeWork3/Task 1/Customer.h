#pragma once
#include <iostream>
#include <string>
class Customer
{
public:
	Customer(int id, const std::string customerName, const std::string customerAddress);
	int GetId()const;
	const std::string GetName()const;
	const std::string GetAddress()const;
	void SetId(int customerId);
	void SetName(const std::string customerName);
	void SetAddress(const std::string customerAddress);
	void Display()const;
private:
    int customerId;
	std::string customerName;
	std::string customerAddress;
};
