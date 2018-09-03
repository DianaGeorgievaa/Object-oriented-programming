#include "Bank.h"
#include "CurrentAccount.h"
#include "SavingsAccount.h"
#include "PrivilegeAccount.h"

Bank::Bank(const std::string bankName, const std::string bankAddress)
{
	this->SetName(bankName);
	this->SetAddress(bankAddress);
}
Bank::Bank(const Bank & other)
{
	this->CopyBank(other);
}
Bank & Bank::operator=(const Bank & other)
{
	if (this != &other)
	{
		ClearBank();
		CopyBank(other);
	}
	return *this;
}
const std::string Bank::GetName() const
{
	return this->bankName;
}
const std::string Bank::GetAddress() const
{
	return this->bankAddress;
}
void Bank::SetName(const std::string bankName)
{
	this->bankName = bankName;
}
void Bank::SetAddress(const std::string bankAddress)
{
	this->bankAddress = bankAddress;
}
void Bank::AddCustomer(int customerId, const std::string customerName, const std::string customerAddress)
{
	Customer newCustomer(customerId, customerName, customerAddress);// the new customer
	this->customers.push_back(newCustomer); // adding the new customer
}
void Bank::ListCustomers() const
{   // if there are any customers
	if (this->customers.size() > 0)
	{
		for (int i = 0; i < this->customers.size(); i++)
		{
			this->customers[i].Display();
		}
	}
	else
	{
		std::cout << "There are no customers in the Bank!" << std::endl;
	}
}
void Bank::DeleteCustomer(int customerId)
{   // if there are any customers
	if (this->customers.size() > 0)
	{
		for (int i = 0; i < this->customers.size(); i++)
		{   // if the customer is with the same Id
			if (this->customers[i].GetId() == customerId)
			{  // deleting the customer
				DeleteCustomerAccounts(customerId);
				this->customers.erase(this->customers.begin() + i);
			}
		}
	}
	else
	{   // if there are no customers
		std::cout << "There are no customers in the Bank!" << std::endl;
	}
}
void Bank::AddAccount(const std::string type, const  std::string iban, int ownerId, double amount)
{
	bool isExsistId = false;
	bool isExsistIBAN = false;
	for (int i = 0; i < this->customers.size(); i++)
	{   // if the acount is with the same Id or iban
		if (this->customers[i].GetId() == ownerId)
		{
			isExsistId = true;
			break;
		}
	}
	for (int i = 0; i < this->accounts.size(); i++)
	{
		if (this->accounts[i]->GetIban() == iban)
		{
			isExsistIBAN = true;
			break;
		}
	}
	if (isExsistId == true && isExsistIBAN == false)
	{
		if (type == "current")
		{   // adding new current account
			this->accounts.push_back(new CurrentAccount(iban, ownerId, amount));
		}
		else if (type == "privilege")
		{
			double overdraft;
			std::cout << "Overdraft: ";
			std::cin >> overdraft;
			//adding new privilege account
			this->accounts.push_back(new PrivilegeAccount(iban, ownerId, amount, overdraft));
		}
		else
		{
			double interestRate;
			std::cout << "Interestrate:";
			std::cin >> interestRate;
			//adding new saving account
			this->accounts.push_back(new SavingsAccount(iban, ownerId, amount, interestRate));
		}
	}
	else
	{
		std::cout << "There is customer with the same ID or account with the same Iban!" << std::endl;
	}
}
void Bank::DeleteAccount(const std::string iban)
{
	std::vector<Account*> newAccount;
	if (this->accounts.size() > 0)
	{
		for (int i = 0; i < this->accounts.size(); i++)
		{  // if the account is with the same iban
			if (this->accounts[i]->GetIban() != iban)
			{   // delete the account
				newAccount.push_back(this->accounts[i]->Clone());
			}
		}
		ClearBank();
		this->accounts = newAccount;
	}
	else
	{
		std::cout << "There are no accounts in the Bank!" << std::endl;
	}
}
void Bank::ListAccounts() const
{   // if there are any accounts
	if (this->accounts.size() > 0)
	{
		for (int i = 0; i < this->accounts.size(); i++)
		{
			this->accounts[i]->Display();
		}
	}
	else
	{
		std::cout << "There are no accounts in the Bank!" << std::endl;
	}
}
void Bank::ListCustomerAccount(int customerId) const
{
	if (this->accounts.size() > 0)
	{
		for (int i = 0; i < this->accounts.size(); i++)
		{   // if the id of the owner is the same with the id of the customer
			if (this->accounts[i]->GetOwnerId() == customerId)
			{
				this->accounts[i]->Display();
			}
		}
	}
	else
	{
		std::cout << "There are no customers in the Bank!" << std::endl;
	}
}
void Bank::Transfer(const std::string fromIBAN, const  std::string toIBAN, double amount)
{
	int first = 0;
	int second = 0;
	for (int i = 0; i < this->accounts.size(); i++)
	{   // if the iban is the same with the iban that we want to transfer from
		if (this->accounts[i]->GetIban() == fromIBAN)
		{
			first = i;
		}
		else if (this->accounts[i]->GetIban() == toIBAN)
		{
			second = i;
		}
	}
	// if it is possible to make the transfer
	if (this->accounts[first]->GetBalance() - amount >= 0)
	{
		this->accounts[second]->Deposit(amount);
		this->accounts[first]->Withdraw(amount);
	}
}
void Bank::Display() const
{
	std::cout << "Name of the bank: " << this->GetName() << std::endl;
	std::cout << "Address of the bank: " << this->GetAddress() << std::endl;
	std::cout << "Number of clients: " << this->customers.size() << std::endl;
	std::cout << "Number of accounts: " << this->accounts.size() << std::endl;
}
void Bank::WithdrawFromAccount(const std::string iban, double sum)
{
	for (int i = 0; i < this->accounts.size(); i++)
	{
		if (this->accounts[i]->GetIban() == iban)
		{
			this->accounts[i]->Withdraw(sum);
			break;
		}
	}
}
void Bank::DepositToAccount(const std::string iban, double sum)
{
	for (int i = 0; i < accounts.size(); i++)
	{
		if (this->accounts[i]->GetIban() == iban)
		{
			this->accounts[i]->Deposit(sum);
			break;
		}
	}
}
Bank::~Bank()
{
	ClearBank();
}
void Bank::CopyBank(const Bank & other)
{
	this->SetAddress(other.GetAddress());
	this->SetName(other.GetName());
	this->customers = other.customers;
	for (int i = 0; i < this->accounts.size(); i++)
	{
		this->accounts.push_back(other.accounts[i]->Clone());
	}
}
void Bank::ClearBank()
{
	for (int i = 0; i < this->accounts.size(); i++)
	{
		delete this->accounts[i];
	}
}
void Bank::DeleteCustomerAccounts(int id)
{
	std::vector<Account*> newAccount;
	if (this->accounts.size() > 0)
	{
		for (int i = 0; i < this->accounts.size(); i++)
		{  // if the account is with the same iban
			if (this->accounts[i]->GetOwnerId() != id)
			{   // delete the account
				newAccount.push_back(this->accounts[i]->Clone());
			}
		}
		ClearBank();
		this->accounts = newAccount;
	}
	else
	{
		std::cout << "There are no accounts in the Bank!" << std::endl;
	}
}