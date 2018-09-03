#pragma once
#include "Account.h"
class PrivilegeAccount :public Account
{
public:
	PrivilegeAccount(const std::string iban, int ownerId, double amount, double overdraft);
	PrivilegeAccount(const PrivilegeAccount& other);
	double GetOverdraft()const;
	void SetOverdraft(double overdraft);

	virtual void Deposit(double sum)override;
	virtual bool Withdraw(double sum)override;
	virtual void Display()const override;
	virtual Account *Clone()override;
private:
	double overdraft;
};