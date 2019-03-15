#include <iostream>
#include"Bank.h"
#include"Customer.h"
#include "CurrentAccount.h"
#include"PrivilegeAccount.h"
#include"SavingsAccount.h"
int main()
{
	    Bank bank("DSK", "Plovdiv ul. pirin 13");
		int choice;
		while (true)
		{
			std::cout << "******************************************************" << std::endl;
			std::cout << "Choose 1 to LIST the customers!" << std::endl;
			std::cout << "Choose 2 to ADD a customer!" << std::endl;
			std::cout << "Choose 3 to DELETE a customer!" << std::endl;
			std::cout << "Choose 4 to LIST all accounts!" << std::endl;
			std::cout << "Choose 5 to LIST the customer accounts!" << std::endl;
			std::cout << "Choose 6 to ADD new account!" << std::endl;
			std::cout << "Choose 7 to DELETE account!" << std::endl;
			std::cout << "Choose 8 to WITHDRAW from account!" << std::endl;
			std::cout << "Choose 9 to DEPOSIT to account!" << std::endl;
			std::cout << "Choose 10 to TRANSFER!" << std::endl;
			std::cout << "Choose 11 to DISPLAY INFO for the Bank!" << std::endl;
			std::cout << "Choose 12 to QUIT!" << std::endl;
			std::cout << "******************************************************" << std::endl;
			std::cout << "Please, choose 1-12! " << std::endl;
			std::cin >> choice;
			switch (choice)
			{
			case 1:
				bank.ListCustomers();
				break;
			case 2:
			{
				int id;
				std::string name;
				std::string address;
				std::cout << "Please, enter the ID of the new customer: ";
				std::cin >> id;
				std::cout << "Please, enter the Name of the new customer: ";
				std::cin >> name;
				std::cout << "Please, enter the Address of the new customer: ";
				std::cin >> address;
				bank.AddCustomer(id, name, address);
				break;
			}
			case 3:
			{
				int id;
				std::cout << "Please,enter the ID : ";
				std::cin >> id;
				bank.DeleteCustomer(id);
				break;
			}
			case 4:
				bank.ListAccounts();
				break;
			case 5:
			{
				int id;
				std::cout << "Please,enter the ID: ";
				std::cin >> id;
				bank.ListCustomerAccount(id);
				break;
			}
			case 6:
			{
				int accountChoice;
				std::string iban;
				double amount;
				int id;
				std::cout << "Choose 1 for Current Account!" << std::endl;
				std::cout << "Choose 2 for Privilege Account!" << std::endl;
				std::cout << "Choose 3 for Saving Account!" << std::endl;
				std::cout << "Please,enter your choice: ";
				std::cin >> accountChoice;
				std::cout << std::endl;
				std::cout << "Please,enter IBAN: ";
				std::cin >> iban;
				std::cout << "Please,enter amount: ";
				std::cin >> amount;
				std::cout << "Please, enter the ID: ";
				std::cin >> id;
				if (accountChoice == 1)
				{
					bank.AddAccount("current", iban, id, amount);
				}
				else if (accountChoice == 2)
				{
					bank.AddAccount("privilege", iban, id, amount);
				}
				else if (accountChoice == 3)
				{
					bank.AddAccount("saving", iban, id, amount);
				}
				else
				{
					std::cout << "Error! Your choice should be between 1 and 3!" << std::endl;
				}
				break;
			}
			case 7:
			{
				std::string iban;
				std::cout << "Please, enter the Iban of the account that you want to Delete: ";
				std::cin >> iban;
				bank.DeleteAccount(iban);
				break;
			}
			case 8:
			{
				std::string iban;
				double sum;
				std::cout << "Please, enter Iban of the account that you want to withdraw from: ";
				std::cin >> iban;
				std::cout << "Please, enter the sum that you want to withdraw: ";
				std::cin >> sum;
				bank.WithdrawFromAccount(iban, sum);
				break;
			}
			case 9:
			{
				std::string iban;
				double sum;
				std::cout << "Please,enter iban of the account that you want to Deposit: ";
				std::cin >> iban;
				std::cout << "Please,enter sum that you want to Deposit: ";
				std::cin >> sum;
				bank.DepositToAccount(iban, sum);
				break;
			}
			case 10:
			{
				std::string fromIban;
				std::string toIban;
				double amount;
				std::cout << "Please, enter the Iban of the account that you want to transfer from: ";
				std::cin >> fromIban;
				std::cout << "Please, enter the Iban of the account that you want to transfer to: ";
				std::cin >> toIban;
				std::cout << "Please, enter the sum that you want to transfer: ";
				std::cin >> amount;
				bank.Transfer(fromIban, toIban, amount);
				break;
			}
			case 11:
				bank.Display();
				break;
			case 12: exit(0);
				break;
			default:
				std::cout << "Your choice is invalid!" << std::endl;
				break;
			}
		}

		return 0;
}
