#include <iostream>
#include "BrowserHistory.h"

//constructor without arguments
BrowserHistory::BrowserHistory() : N(0), WebSitesCount(-1), WebSites(nullptr)
{
}
//constructor with one argument
BrowserHistory::BrowserHistory(int N)
{   // if the number of websites is >0
	if (N > 0)
	{
		this->N = N;
		// allocation memory
		this->WebSites = new HistoryEntry[N];
		this->WebSitesCount = 0;
	}
}

//destructor
BrowserHistory::~BrowserHistory()
{  
	//delite the allocated memory
	delete[]this->WebSites;
}

BrowserHistory::BrowserHistory(const BrowserHistory & w)
{
	this->N = w.N;
	this->WebSitesCount = w.WebSitesCount;
	this->WebSites = new HistoryEntry[this->N];
	for (int i = 0; i < this->WebSitesCount; i++)
	{
		this->WebSites[i].SetMonth(w.WebSites[i].GetMonth());
		this->WebSites[i].SetURL(w.WebSites[i].GetURL());
	}
}

void BrowserHistory::AddWebSite(const HistoryEntry& w)
{   // if there is not more space
	if (this->WebSitesCount >= this->N)
	{
		std::cout << "Error!The memory reached its limit!" << std::endl;
		return;
	}
	else
	//if there is space, add the new website
	{
		WebSites[WebSitesCount] = w;
	//the number of websites gets bigger
	    WebSitesCount++;
	}
}
void BrowserHistory::AddWebSite()
{   // if there is not space for new website
	if (this->WebSitesCount >= this->N)
	{
		std::cout << "Error!The memory reached its limit!" << std::endl;
		return;
	}
	else
	{  // for the length of the URL
		int lengthURL;
		std::cout << "Please, choose a positive number for the length of the URL" << std::endl;
		std::cin >> lengthURL;
		// if the entered length is correct
		if (lengthURL > 0)
		{
			int month;
			char* URL = new char[lengthURL];
			std::cout << "Please,choose a month:";
			std::cin >> month;
			std::cout << std::endl;
			std::cout << "Please, enter URL:";
			std::cin >> URL;
			WebSites[WebSitesCount].SetMonth(month);
			WebSites[WebSitesCount].SetURL(URL);
			WebSitesCount++;
		}
		// if the entered length is not correct
		else
		{
			std::cout << "Please,enter suitable length!" << std::endl; 
		}
	}
}
void BrowserHistory::PrintAllWebSites()const
{    
	for (int i = 0; i < this->WebSitesCount; i++)
	{   // print the URL and the month
		std::cout << "URL:" << WebSites[i].GetURL() << std::endl;
		std::cout << "Month:" << WebSites[i].GetMonth() << std::endl;
	}
}

int BrowserHistory::VisitedSites(int month)
{   
	int counter = 0; // counter for the visits 
	for (int i = 0; i < this->WebSitesCount; i++)
	{   // if the month is the month that we need
		if (this->WebSites[i].GetMonth() == month)
	   // the visits ++
		counter++;
	}
	return counter;
}

void BrowserHistory::DeleteTheLastWebsite()
{
	WebSitesCount--; // the number of websites becomes smaller with 1
	HistoryEntry* sites = new HistoryEntry[WebSitesCount];// new array with lenght smaller than the first
	for (int i = 0; i < this->WebSitesCount; i++)
	{
		sites[i].SetMonth(this->WebSites[i].GetMonth());
		sites[i].SetURL(this->WebSites[i].GetURL());
	}
	// the old array becomes the new
	this->WebSites = sites;
}

int BrowserHistory::MonthWithMostVisits()
{
	int min_visited = 1;
	int max_visited = 0;
	int month;
	for (int i = 0; i < this->WebSitesCount; i++)
	{
		int num_sites = VisitedSites(this->WebSites[i].month); // get number of the websites by month
		min_visited = num_sites;
		if (min_visited > max_visited)
		{
			max_visited = min_visited;
			month = this->WebSites[i].month;
		}
	}

	return month; // returns the month with the most visits
}

BrowserHistory BrowserHistory::operator=(const BrowserHistory & w)
{
	if (this != &w)
	{
		delete[] this->WebSites;
		this->N = w.N;
		this->WebSitesCount = w.WebSitesCount;
		this->WebSites = new HistoryEntry[this->N];
		for (int i = 0; i < this->WebSitesCount; i++)
		{
			this->WebSites[i].SetMonth(w.WebSites[i].GetMonth());
			this->WebSites[i].SetURL(w.WebSites[i].GetURL());
		}
	}
	return *this;
}

BrowserHistory BrowserHistory::operator+(const BrowserHistory & w)
{
	int lenOfBrowser = this->WebSitesCount + w.WebSitesCount;
	BrowserHistory browser(lenOfBrowser);
	for (int i = 0; i < this->WebSitesCount; i++)
	{
		browser.AddWebSite(this->WebSites[i]);
	}
	for (int j = 0; j < w.WebSitesCount; j++)
	{
		browser.AddWebSite(w.WebSites[j]);
	}
	return browser;
}


int BrowserHistory::HistoryEntry::GetMonth() const
{
	return this->month;
}

const char * BrowserHistory::HistoryEntry::GetURL() const
{
	return this->URL;
}

BrowserHistory::HistoryEntry::HistoryEntry() :month(0)
{
}

BrowserHistory::HistoryEntry::HistoryEntry(int month, const char * URL)
{
	SetMonth(month);
	SetURL(URL);
}

void BrowserHistory::HistoryEntry::SetMonth(int month)
{
	if (month > 0 && month <= 12)
	{
		this->month = month;
	}
	else
	{
		std::cout << "Invalid month!" << std::endl;
		this->month = 0;
		return;
	}
}

void BrowserHistory::HistoryEntry::SetURL(const char * URL)
{
	int l = strlen(URL);
	this->URL = new char[l + 1];
	int i = 0;
	while (URL[i] != 0 && i <= l - 1)
	{
		this->URL[i] = URL[i];
		i++;
	}
	this->URL[i] = 0;
}