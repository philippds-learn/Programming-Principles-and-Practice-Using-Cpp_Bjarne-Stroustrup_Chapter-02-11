//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 7 Exercise 11.1

#include "std_lib_facilities.h"

vector<string> dayName;
vector<int> dayVal(7, 0);

void init_dayName() {
	dayName = { "Monday", "monday", "Mon",
		"Tuesday", "tuesday", "Tue",
		"Wednesday", "wednesday", "Wed",
		"Thursday", "thursday", "Thu",
		"Friday", "friday", "Fri",
		"Saturday", "saturday", "Sat",
		"Sunday", "sunday", "Sun" };
}


void calculate() {
	string day;
	int value;
	string falsevalue;
	bool check = true;

	cout << "Enter pairs of week-days and values seperated by blank space or exit "
		 << "and 0 to end entry: \n";

	while (check) {
		if (cin >> day >> value) {
			for (int i = 0; i < dayName.size(); i++) {
				if (day == dayName[i]) {
					dayVal[i / 3] += value;
				}
			}
			if (day == "exit" && value == 0) {
				check = false;
			}
		}
		else {
			cin.clear();
			cin >> falsevalue;
			error("Entered value illegal: ", falsevalue);
		}
	}

	for (int i = 0; i < dayVal.size(); i++) {
		cout << dayName[i * 3] << ": " << dayVal[i] << "\n";
	}
}


int main()
try
{
	init_dayName();
	calculate();
	keep_window_open(".");
}

catch (runtime_error e) {
	cout << e.what() << "\n";
	keep_window_open(".");
}
catch (...) {
	cout << "Extiting" << "\n";
	keep_window_open(".");
}

/*
Enter pairs of week-days and values seperated by blank space or exitand 0 to end entry:
Monday 10
Tuesday 30
Friday 60
exit 0
Monday: 10
Tuesday: 30
Wednesday: 0
Thursday: 0
Friday: 60
Saturday: 0
Sunday: 0
Please enter . to exit
*/
