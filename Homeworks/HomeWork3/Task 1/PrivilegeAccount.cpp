#include "PrivilegeAccount.h"

PrivilegeAccount::PrivilegeAccount(const std::string iban, int ownerId, double amount, double overdraft) :Account(iban, ownerId, amount)
{
	this->SetOverdraft(overdraft);
}
PrivilegeAccount::PrivilegeAccount(const PrivilegeAccount & other)
{
	this->SetAmount(other.GetBalance());
	this->SetIban(other.GetIban());
	this->SetOwnerId(other.GetOwnerId());
	this->SetOverdraft(other.GetOverdraft());
}
double PrivilegeAccount::GetOverdraft() const
{
	return this->overdraft;
}
void PrivilegeAccount::SetOverdraft(double overdraft)
{
	if (overdraft >= 0)
	{
		this->overdraft = overdraft;
	}
	else
	{
		std::cout << "Invalid overdraft!" << std::endl;
	}
}
void PrivilegeAccount::Deposit(double sum)
{
	Account::Deposit(sum);
}
bool PrivilegeAccount::Withdraw(double sum)
{
	if (this->GetBalance() + this->GetOverdraft() < sum && sum >0)
	{
		return false;
	}
	else
	{
		this->SetAmount(this->GetBalance() - sum);
		return true;
	}
}
void PrivilegeAccount::Display() const
{
	std::cout << "Savings Account" << std::endl;
	Account::Display();
	std::cout << "Overdraft: " << this->GetOverdraft() << std::endl;
}
Account * PrivilegeAccount::Clone()
{
	return new PrivilegeAccount(*this);
}