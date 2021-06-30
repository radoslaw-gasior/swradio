#pragma once
#include <string>
#include <vector>

class SearchEngine {
public:
	std::string operation;
	std::string WorkingDirectory;
	std::string SearchFreq;
	std::string Location;
	std::vector<std::vector<std::string>> FoundRecords;
	int DayOfWeek;
	int time;

	std::string SayHello(std::string& select);
	void CollectData(std::string &WorkingDirectory, std::string &SearchFreq, std::string &Location, int& time, int &DayOfWeek);
	void Search(std::string WorkingDirectory, std::string SearchFreq, std::string Location, int time, int DayOfWeek, std::vector<std::vector<std::string>> &FoundRecords);

};

