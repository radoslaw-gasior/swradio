
#include <iostream>
#include <string>
#include <vector>
#include "Results.h"
using namespace std;

void Results::ShowProvidedData(string &SearchFreq, string &Location, int &DayOfWeek, int &time) {
	cout << "----------------------------------------" << endl;
	cout << "	Showing results for	" << endl;
	cout << "----------------------------------------" << endl << endl;
	cout << "Frequency: " << SearchFreq << "	" << "Location: " << Location << endl;
	cout << "Time: " << time << "	" << "Day of week: ";

	switch (DayOfWeek)
	{
	case 1:
		cout << "Monday" << endl << endl;
		break;
	case 2:
		cout << "Tuesday" << endl << endl;
		break;
	case 3:
		cout << "Wednesday" << endl << endl;
		break;
	case 4:
		cout << "Thursday" << endl << endl;
		break;
	case 5:
		cout << "Friday" << endl << endl;
		break;
	case 6:
		cout << "Satruday" << endl << endl;
		break;
	case 7:
		cout << "Sunday" << endl << endl;
		break;
	}

}

void Results::ShowResults(vector<vector<string>> &FoundRecords) {
	cout << "----------------------------------------" << endl;
	cout << "	Matching Results:	" << endl;
	cout << "----------------------------------------" << endl << endl;

	if (FoundRecords.size() == 0) {
		cout << "***No matching results***" << endl;
	}
	else {
		for (int i = 0; i < FoundRecords.size(); i++) {
			int j = i + 1;
			cout << "***STATION " << j << "***" << endl;
			cout << "Station Name:	" << FoundRecords[i][2] << endl;
			cout << "UTC:			" << FoundRecords[i][3] << endl;
			cout << "Days:			" << FoundRecords[i][4] << endl;
			cout << "Language:		" << FoundRecords[i][5] << endl;
			cout << "Power:			" << FoundRecords[i][9] << endl;
			cout << "Program:		" << FoundRecords[i][30] << endl;

		}
	}
}


