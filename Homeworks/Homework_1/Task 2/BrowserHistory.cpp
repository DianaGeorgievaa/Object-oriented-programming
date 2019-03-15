#include <iostream>
#include "BrowserHistory.h"

BrowserHistory::BrowserHistory() : N(0), WebSitesCount(-1), WebSites(nullptr)
{
}
BrowserHistory::BrowserHistory(int N)
{   
	if (N > 0)
	{
		this->N = N;
		this->WebSites = new HistoryEntry[N];
		this->WebSitesCount = 0;
	}
}

BrowserHistory::~BrowserHistory()
{ 
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
{   
	if (this->WebSitesCount >= this->N)
	{
		std::cout << "Error!The memory reached its limit!" << std::endl;
		return;
	}
	else
	{
	    WebSites[WebSitesCount] = w;
	    WebSitesCount++;
	}
}
void BrowserHistory::AddWebSite()
{   
	if (this->WebSitesCount >= this->N)
	{
		std::cout << "Error!The memory reached its limit!" << std::endl;
		return;
	}
	else
	{  
		int lengthURL;
		std::cout << "Please, choose a positive number for the length of the URL" << std::endl;
		std::cin >> lengthURL;
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
		else
		{
			std::cout << "Please,enter suitable length!" << std::endl; 
		}
	}
}
void BrowserHistory::PrintAllWebSites()const
{    
	for (int i = 0; i < this->WebSitesCount; i++)
	{  	std::cout << "URL:" << WebSites[i].GetURL() << std::endl;
		std::cout << "Month:" << WebSites[i].GetMonth() << std::endl;
	}
}

int BrowserHistory::VisitedSites(int month)
{   
	int counter = 0; 
	for (int i = 0; i < this->WebSitesCount; i++)
	{   
		if (this->WebSites[i].GetMonth() == month)
		counter++;
	}
	return counter;
}

void BrowserHistory::DeleteTheLastWebsite()
{
	WebSitesCount--; 
	HistoryEntry* sites = new HistoryEntry[WebSitesCount];
	for (int i = 0; i < this->WebSitesCount; i++)
	{
		sites[i].SetMonth(this->WebSites[i].GetMonth());
		sites[i].SetURL(this->WebSites[i].GetURL());
	}
	this->WebSites = sites;
}

int BrowserHistory::MonthWithMostVisits()
{
	int min_visited = 1;
	int max_visited = 0;
	int month;
	for (int i = 0; i < this->WebSitesCount; i++)
	{
		int num_sites = VisitedSites(this->WebSites[i].month);
		min_visited = num_sites;
		if (min_visited > max_visited)
		{
			max_visited = min_visited;
			month = this->WebSites[i].month;
		}
	}

	return month;
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
