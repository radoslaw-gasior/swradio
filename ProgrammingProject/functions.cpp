
/*
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "functions.h"
using namespace std;

string SayHello(string &select) {
	cout << "----------------------------------------" << endl;
	cout << "	Short wave radio finder	" << endl;
	cout << "----------------------------------------" << endl << endl;
	cout << "Select operation:" << endl << "Q - exit program" << endl << "1 - Start new search" << endl << "User:	";
	cin >> select;

	return select;
}

void CollectData(string &WorkingDirectory, string &SearchFreq, string &Location, int &DayOfWeek, int &time) {
	
	cout << "Please enter location of database file" << endl << "User:	";
	//cin >> WorkingDirecotry;
	WorkingDirectory = "C:\\radio\\ILGradio.txt";
	cout << "Please enter frequency in format XXXX.XX" << endl << "User:	";
	//cin >> SearchFreq;
	SearchFreq = "2460.00";
	cout << "Please enter location" << endl << "User:	";
	//cin >> Location;
	Location = "Rio Branco";

	cout << "Please enter time in HHMM 24h format" << endl << "User:	";
	cin >> time;

	cout << "Please select day of week, press:" << endl << "1-	Monday" << endl << "2-	Tuesday" << endl << "3-	Wednesday" << endl;
	cout << "4-	Thursday" << endl << "5-	Friday" << endl << "6-	Saturday" << endl << "7-	Sunday" << endl << "User:	";
	cin >> DayOfWeek;

	Search(WorkingDirectory, SearchFreq, Location, time, DayOfWeek);
}

void Search(string WorkingDirectory, string SearchFreq, string Location, int time, int DayOfWeek) {
	ifstream Database(WorkingDirectory);
	string line;
	vector<vector<string>> res;
	vector<vector<string>> FoundRecords;
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
	Divide(res) = res;

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
				cout << "got it" << endl;
			}
		}
	}
	if (FoundRecords.size() == 0) {			//przenieœæ do results
		cout << "No matching results" << endl;
	}
	// Stwórz obiekt z klasy results i przeka¿ FoundRecords
}

vector<vector<string>> Divide(vector<vector<string>> &res) {	//rozdzielenie linii po przecinkach
	for (int i = 0; i < res.size(); i++) {
		stringstream ss(res[i][0]);
		while (ss.good()) {
			string substr;
			getline(ss, substr, ',');
			res[i].push_back(substr);
		}
	}
	return res;
}
*/