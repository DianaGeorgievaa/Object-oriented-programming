#pragma once

#include <iostream>
#include <string>

class Account
{
public:
	Account() {};
	Account(const std::string iban, int ownerId, double amount);
	double GetBalance()const;
	const std::string GetIban()const;
	int GetOwnerId()const;
	void SetIban(const std::string iban);
	void SetOwnerId(int ownerId);
	void SetAmount(double amount);

	virtual void Deposit(double sum) = 0;
	virtual bool Withdraw(double sum) = 0;
	virtual void Display()const = 0;
	virtual Account *Clone() = 0; 
	virtual ~Account();
private:
	std::string iban;
	int ownerId;
	double amount;
};
