#include <iostream>
#include "SearchEngine.h"
#include"Results.h"

int main() {
	
	SearchEngine NewSearch;
	Results R1;

	NewSearch.SayHello(NewSearch.operation);
	if (NewSearch.operation == "q") {
		return 0;
	}
	if (NewSearch.operation == "1") {
		R1.CollectData(NewSearch.WorkingDirectory, NewSearch.SearchFreq, NewSearch.Location, NewSearch.time, NewSearch.DayOfWeek);
		NewSearch.Search(NewSearch.WorkingDirectory, NewSearch.SearchFreq, NewSearch.Location, NewSearch.time, NewSearch.DayOfWeek, R1.FoundRecords);
		R1.ShowProvidedData(NewSearch.SearchFreq, NewSearch.Location, NewSearch.DayOfWeek, NewSearch.time );
		R1.ShowResults(R1.FoundRecords);
	}
	return 0;
}

