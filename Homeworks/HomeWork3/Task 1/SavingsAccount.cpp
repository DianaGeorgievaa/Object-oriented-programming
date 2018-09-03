#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(const std::string iban, int ownerId, double amount, double interestRate) :Account(iban, ownerId, amount)
{
	this->SetInterestRate(interestRate);
}
SavingsAccount::SavingsAccount(const SavingsAccount & other)
{
	this->SetAmount(other.GetBalance());
	this->SetIban(other.GetIban());
	this->SetOwnerId(other.GetOwnerId());
	this->SetInterestRate(other.GetInterestRate());
}
double SavingsAccount::GetInterestRate() const
{
	return this->interestRate;
}
void SavingsAccount::SetInterestRate(double interestRate)
{
	if (interestRate >= 0)
	{
		this->interestRate = interestRate;
	}
	else
	{
		std::cout << "Invalid interestrate!" << std::endl;
	}
}
void SavingsAccount::Deposit(double sum)
{
	Account::Deposit(sum);
}
bool SavingsAccount::Withdraw(double sum)
{
	if (this->GetBalance() < sum && sum > 0)
	{
		return false;
	}
	else
	{
		this->SetAmount(this->GetBalance() - sum);
		return true;
	}
}
void SavingsAccount::Display() const
{
	std::cout << "Savings Account" << std::endl;
	Account::Display();
	std::cout << "Interestrate: " << this->GetInterestRate() << std::endl;
}
Account * SavingsAccount::Clone()
{
	return new SavingsAccount(*this);
}
