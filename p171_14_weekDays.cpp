//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 5 Exercise 14

#include "std_lib_facilities.h"

int main()
try
{
	vector<string> dayVec = { "Monday", "monday", "Mon",
							"Tuesday", "tuesday", "Tue",
							"Wednesday", "wednesday", "Wed",
							"Thursday", "thursday", "Thu",
							"Friday", "friday", "Fri",
							"Saturday", "saturday", "Sat",
							"Sunday", "sunday", "Sun" };
	vector<int> dayVal = { 0,0,0,0,0,0,0 };
	string day;
	int value;
	string falsevalue;
	bool check = true;

	cout << "Enter pairs of week-days and values seperated by blank space: \n";
	cout << "Enter exit 0 to end entry.\n";

	while(check){
		if(cin >> day >> value){
			for(int i = 0; i < dayVec.size(); i++){
				if (day == dayVec[i]) {
					dayVal[i / 3] += value;
				}
			}
			if (day == "exit" && value == 0) {
				break;
				check = true;
			}
		}
		else {
			cin.clear();
			cin >> falsevalue;
			error("Entered value illegal: ", falsevalue);
		}
	}
	
	for (int i = 0; i < dayVal.size(); i++) {
		cout << dayVec[i*3] << ": " << dayVal[i] << "\n";
	}
	
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
