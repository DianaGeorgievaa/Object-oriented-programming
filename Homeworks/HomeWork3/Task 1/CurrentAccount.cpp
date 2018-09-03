#include "CurrentAccount.h"

CurrentAccount::CurrentAccount(const std::string iban, int ownerId, double amount) 
			:Account(iban, ownerId, amount)
{
}
CurrentAccount::CurrentAccount(const CurrentAccount & other)
{
	this->SetAmount(other.GetBalance());
	this->SetIban(other.GetIban());
	this->SetOwnerId(other.GetOwnerId());
}
void CurrentAccount::Deposit(double sum)
{
	Account::Deposit(sum);
}
bool CurrentAccount::Withdraw(double sum)
{   
	if (this->GetBalance() < sum && sum >0)
	{
		return false;
	}
	else
		// if it is possible to withdraw
	{
		this->SetAmount(this->GetBalance() - sum);
		return true;
	}
}
void CurrentAccount::Display() const
{
	std::cout << "Current account" << std::endl;
	Account::Display();
}
Account * CurrentAccount::Clone()
{
	return new CurrentAccount(*this);
}
CurrentAccount::~CurrentAccount()
{
}