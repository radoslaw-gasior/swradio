#pragma once
#include <string>
#include<vector>
#include "SearchEngine.h"

class Results :public SearchEngine {
public:

	void ShowProvidedData(std::string &SearchFreq, std::string &Location, int &DayOfWeek, int &time);
	void ShowResults(std::vector<std::vector<std::string>> &FoundRecords);
};

