#ifndef BROWSERHISTORY_H
#define BROWSERHISTORY_H

class BrowserHistory
{
public:
	struct HistoryEntry
	{
		int month;
		char* URL;
		int GetMonth()const;
		const char* GetURL()const;
		HistoryEntry();
		HistoryEntry(int month, const char*URL);
		void SetMonth(int month);
		void SetURL(const char*URL);
	};
	BrowserHistory();// constructor
	BrowserHistory(int N);// constructor with one argument
	~BrowserHistory();// destructor
	BrowserHistory(const BrowserHistory& w);// copy constructor
	void AddWebSite(const HistoryEntry &w);// for adding new website
	void AddWebSite();
	void PrintAllWebSites()const;// print
	int VisitedSites(int month); // the number of visited sites in one month
	void DeleteTheLastWebsite();// deletes the last added website
	int MonthWithMostVisits();// finds the month with the most visits
	BrowserHistory operator=(const BrowserHistory & w);// operator =
	BrowserHistory operator+(const BrowserHistory & w);//for the concatenation

private:
	HistoryEntry * WebSites;// dynamic array with the websites
	unsigned int WebSitesCount;// the current number of websites 
	unsigned int N; //the  max number of websites
};
#endif