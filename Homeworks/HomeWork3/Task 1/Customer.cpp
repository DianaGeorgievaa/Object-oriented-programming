#include "Customer.h"

Customer::Customer(int customerId, const std::string customerName, const std::string customerAddress)
{
	this->SetId(customerId);
	this->SetName(customerName);
	this->SetAddress(customerAddress);
}
int Customer::GetId() const
{
	return this->customerId;
}
const std::string Customer::GetName() const
{
	return this->customerName;
}
const std::string Customer::GetAddress() const
{
	return this->customerAddress;
}
void Customer::SetId(int customerId)
{
	if (customerId > 0)
	{
		this->customerId = customerId;
	}
	else
	{
		std::cout << "Invalid Id!" << std::endl;
	}
}
void Customer::SetName(const std::string customerName)
{
	this->customerName = customerName;
}
void Customer::SetAddress(const std::string customerAddress)
{
	this->customerAddress = customerAddress;
}
void Customer::Display() const
{
	std::cout << "Id: " << this->GetId() << " Name: " << this->GetName() << " Address: " << this->GetAddress() << std::endl;
}
