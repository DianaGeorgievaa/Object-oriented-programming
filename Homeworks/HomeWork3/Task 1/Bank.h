#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "Customer.h"
#include "Account.h"

class Bank
{
public:
	Bank(const std::string bankName, const std::string bankAddress);
	Bank(const Bank& other);
	Bank &operator=(const Bank& other);
	const std::string GetName()const;
	const std::string GetAddress()const;
	void SetName(const std::string bankName);
	void SetAddress(const std::string bankAddress);
	void AddCustomer(int customerId, const std::string customerName, const std::string customerAddress);
	void ListCustomers()const;
	void DeleteCustomer(int customerId);
	void AddAccount(const std::string type, const std::string iban, int ownerId, double amount);
	void DeleteAccount(const std::string iban);
	void ListAccounts()const;
	void ListCustomerAccount(int customerId)const;
	void Transfer(const std::string fromIBAN, const std::string  toIBAN, double amount);
	void Display()const;
	void WithdrawFromAccount(const std::string iban, double sum);
	void DepositToAccount(const std::string iban, double sum);
	~Bank();

private:
	void CopyBank(const Bank& other);
	void ClearBank();
	void DeleteCustomerAccounts(int id);

	std::string bankName;
	std::string bankAddress;
	std::vector<Account*> accounts;
	std::vector<Customer> customers;
};