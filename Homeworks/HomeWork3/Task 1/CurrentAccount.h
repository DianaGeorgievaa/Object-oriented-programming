#pragma once
#include "Account.h"

class CurrentAccount : public Account
{
public:
	CurrentAccount(const std::string iban, int ownerId, double amount);
	CurrentAccount(const CurrentAccount& other);

	virtual void Deposit(double sum) override;
	virtual bool Withdraw(double sum)override;
	virtual void Display()const override;
	virtual Account *Clone()override;
	virtual ~CurrentAccount();
};