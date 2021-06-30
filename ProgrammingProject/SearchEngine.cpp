#include "SearchEngine.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "Results.h"
using namespace std;

string SearchEngine::SayHello(string& select) {
	cout << "----------------------------------------" << endl;
	cout << "	Short wave radio finder	" << endl;
	cout << "----------------------------------------" << endl << endl;
	cout << "Select operation:" << endl << "Q - exit program" << endl << "1 - Start new search" << endl << "User:	";
	getline(cin, select);
	return select;
}

void SearchEngine::CollectData(string &WorkingDirectory, string &SearchFreq, string &Location, int& time, int &DayOfWeek) {

	cout << "Please enter location of database file" << endl << "User:	";
	getline(cin, WorkingDirectory);
	cout << "Please enter frequency in format XXXX.XX" << endl << "User:	";
	getline(cin, SearchFreq);
	cout << "Please enter location" << endl << "User:	";
	getline(cin, Location);
	cout << "Please enter time in HHMM 24h format" << endl << "User:	";
	cin >> time;
	cout << "Please select day of week, press:" << endl << "1-	Monday" << endl << "2-	Tuesday" << endl << "3-	Wednesday" << endl;
	cout << "4-	Thursday" << endl << "5-	Friday" << endl << "6-	Saturday" << endl << "7-	Sunday" << endl << "User:	";
	cin >> DayOfWeek;

}

void SearchEngine::Search(string WorkingDirectory, string SearchFreq, string Location, int time, int DayOfWeek, vector<vector<string>> &FoundRecords) {
	ifstream Database(WorkingDirectory);
	string line;
	vector<vector<string>> res;
	int i = 0;
	while (getline(Database, line)) {
		if (line.find(SearchFreq) != string::npos) {			//zawê¿anie wyszukiwania tylko do pasuj¹cych czêstotliwoœci i lokalizacji
			if (line.find(Location) != string::npos) {
				res.push_back(vector<string>());
				res[i].push_back(line);
				i++;
			}
		}
	}
	for (int i = 0; i < res.size(); i++) {
		stringstream ss(res[i][0]);
		while (ss.good()) {
			string substr;
			getline(ss, substr, ',');
			res[i].push_back(substr);
		}
	}

	for (int i = 0; i < res.size(); i++) {
		vector<int> ReadTimePeriod;
		stringstream ss(res[i][3]);
		while (ss.good()) {
			string substr;
			getline(ss, substr, '-');
			ReadTimePeriod.push_back(stoi(substr));	//odczyt ram czasowych z linii z zawê¿onych wyników
		}
		if (ReadTimePeriod[0] < time && time < ReadTimePeriod[1]) {		//sprawdzenie czy podany czas pasuje do tego z wyników
			if (res[i][4].find(DayOfWeek)) {
				FoundRecords.push_back(res[i]);
			}
		}
	}
}
