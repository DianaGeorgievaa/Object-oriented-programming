#include "Account.h"

Account::Account(const std::string iban, int ownerId, double amount)
{
	this->SetIban(iban);
	this->SetOwnerId(ownerId);
	this->SetAmount(amount);
}
void Account::Deposit(double sum)
{   
	if (sum >= 0)
	{
		this->SetAmount(amount + sum);
	}
	else
	{
		std::cout << "The sum can not be negative!" << std::endl;
	}
}
void Account::Display() const
{
	std::cout << "Iban: " << this->GetIban() << std::endl;
	std::cout << "ID of the owner: " << this->GetOwnerId() << std::endl;
	std::cout << "Balance: " << this->GetBalance() << std::endl;
}
double Account::GetBalance() const
{
	return this->amount;
}
const std::string Account::GetIban() const
{
	return this->iban;
}
int Account::GetOwnerId() const
{
	return this->ownerId;
}
void Account::SetIban(const std::string iban)
{
	this->iban = iban;
}
void Account::SetOwnerId(int ownerId)
{
	if (ownerId > 0)
	{
		this->ownerId = ownerId;
	}
	else
	{
		std::cout << "Invalid ownerId!" << std::endl;
	}
}
void Account::SetAmount(double amount)
{   
	// without any checkings because of the privilege account 
	this->amount = amount;
}
Account::~Account()
{
}