//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 4 Exercise 14

#include "std_lib_facilities.h"
#include "math.h"

int main()
try
{
	int max = 100;
	string s;
	vector<int> seriesNum;

	cout << "Enter a maximum value for the prime number generator: \n";
	if (cin >> max){}
	else {
		cin.clear();
		cin >> s;
		error("Bad input for maximum", s);
	}

	//fill series of numbers
	for (int i = 2; i < max; i++) {
		seriesNum.push_back(i);
	}

	//check for primes
	for (int j = 2; j < 6; j++) {
		for (int i = 0; i < seriesNum.size(); i++) {
			if (seriesNum[i] % j == 0 && seriesNum[i] != j) {
				seriesNum[i] = 0;
			}
		}
	}

	//print primes
	for (int i = 0; i < seriesNum.size(); i++) {
		if (seriesNum[i] != 0) {
			cout << seriesNum[i] << "\n";
		}
	}

	keep_window_open(".");
}

catch (runtime_error e) {
	cout << e.what() << "\n";
	keep_window_open(".");
}
catch (...) {
	cout << "Exiting.\n";
	keep_window_open(".");
}