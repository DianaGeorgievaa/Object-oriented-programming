#include <iostream>
#include "BrowserHistory.h"

int main()
{
	BrowserHistory::HistoryEntry website1(1,"www.google.com");
	BrowserHistory::HistoryEntry website2(2,"www.facebook.com");
	BrowserHistory::HistoryEntry website3(1, "www.twitter.com");
	BrowserHistory::HistoryEntry website4(2, "www.instagram.com");
	BrowserHistory::HistoryEntry website5(3, "www.zamunda.com");

	BrowserHistory browser(3);
	browser.AddWebSite(website1);
	browser.AddWebSite(website2);
	browser.AddWebSite(website3);
	std::cout << "All websites:" << std::endl;
	browser.PrintAllWebSites();
	std::cout<<"*************************************************************"<<std::endl;
	BrowserHistory browser1(3);
	browser1.AddWebSite(website4);
	browser1.AddWebSite(website5);
	std::cout << "Concatenation:" << std::endl;
	BrowserHistory browser2 = browser + browser1; 
	browser2.PrintAllWebSites();
	std::cout<<"*************************************************************"<<std::endl;
	browser1.AddWebSite();
	std::cout << "*************************************************************" << std::endl;
	int month; 
	std::cout << "Please, enter a month in order to find the visited sites in it: ";
	std::cin >> month;
	std::cout << "The number of sites visited in " << month << " month" << " is: " << browser.VisitedSites(month)<< std:: endl;
	std::cout << "**************************************************************" << std::endl;

	std::cout << "The month with the most visited websites is:" << browser.MonthWithMostVisits ()<< std::endl;
	std::cout << "***************************************************************" << std::endl;
	std::cout << "Delete the last visited website:" << std::endl;
	browser.DeleteTheLastWebsite();
	browser.PrintAllWebSites();

	return 0;
}
