//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 4 Exercise 16

#include "std_lib_facilities.h"

int main()
try
{
	vector<int> seriesNum;
	int singleNum;
	int counterTemp = 0;
	int countHighest = 0;
	int indexHighest = 0;

	string noNum = " ";
	bool check1 = true;

	cout << "Enter a series of numbers equal or larger to 1, enter 0 to end the series" << "\n";

	while (check1 == true) {
		cout << "Enter number for series\n";
		cin.clear();

		if (cin >> singleNum) {
			if (singleNum > 0) {
				seriesNum.push_back(singleNum);
			}
			else if (singleNum == 0) {
				check1 = false;
				break;
				cout << "test";
			}
			
		}
		else {
			cin.clear();
			cin >> noNum;
			error("Entry was not a number", noNum);
		}
	}

	sort(seriesNum);

	for (int i = 0; i < seriesNum.size(); i++) {
		cout << seriesNum[i] << " ";
	}

	for (int i = 1; i < seriesNum.size(); i++) {
		if (seriesNum[i] == seriesNum[i - 1]) {
			counterTemp++;
		}
		else {
			counterTemp = 0;
		}
		if (counterTemp > countHighest) {
			indexHighest = i-1;
			countHighest = counterTemp;
			
		}
	}

	cout << "The Mode of numSeries is: " << seriesNum[indexHighest] << " counted " << countHighest+1 << " times\n";

	keep_window_open(".");
}

catch (runtime_error e) {
	cout << e.what() << "\n";
	keep_window_open(".");
}
catch(...) {
	cout << "Exiting!\n";
	keep_window_open(".");
}
