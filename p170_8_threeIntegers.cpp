//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 5 Exercise 8

#include "std_lib_facilities.h"

int main()
try
{
	vector<int> numVec;
	
	int numCount = 0;
	int value;
	int numSum = 0;
	string check;

	cout << "Enter number of integers to be read:\n";
	if(cin >> numCount){}
	else {
		cin.clear();
		cin >> check;
		error("Entered value does not match: ", check);
	}

	cout << "Enter some values to be stored seperated by a blank space "
		"ending with a 'x': \n";
	for (int i = 0; i < numCount; i++) {
		if (cin >> value) {
			numVec.push_back(value);
			numSum += value;
		}
		else {
			cin.clear();
			cin >> check;
			if (check == "x") {
				break;
			}
			else{
				error("Input is no value: ", check);
			}
		}
	}

	if (numVec.size() < numCount) {
		error("The entered number of integers to be read is larger than the vector size.\n");
	}

	for (int i = 0; i < numVec.size(); i++) {
		cout << numVec[i] << "\n";
	}
	cout << "sum = " << numSum << "\n";

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