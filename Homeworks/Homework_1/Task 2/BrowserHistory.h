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
	BrowserHistory();
	BrowserHistory(int N);
	~BrowserHistory();
	BrowserHistory(const BrowserHistory& w);
	void AddWebSite(const HistoryEntry &w);
	void AddWebSite();
	void PrintAllWebSites()const;
	int VisitedSites(int month); 
	void DeleteTheLastWebsite();
	int MonthWithMostVisits();
	BrowserHistory operator=(const BrowserHistory & w);
	BrowserHistory operator+(const BrowserHistory & w);

private:
	HistoryEntry * WebSites;
	unsigned int WebSitesCount;
	unsigned int N; 
};
#endif
