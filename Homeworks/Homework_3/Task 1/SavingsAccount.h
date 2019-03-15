#pragma once
#include "Account.h"
class SavingsAccount :public Account
{
public:
	SavingsAccount(const std::string iban, int ownerId, double amount, double interestRate);
	SavingsAccount(const SavingsAccount&other);
	double GetInterestRate()const;
	void SetInterestRate(double interestRate);

	virtual void Deposit(double sum)override;
	virtual bool Withdraw(double sum)override;
	virtual void Display()const override;
	virtual Account *Clone()override;
private:
	double interestRate;
};

