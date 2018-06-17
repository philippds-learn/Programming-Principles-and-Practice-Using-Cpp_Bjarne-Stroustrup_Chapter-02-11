//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 4 Exercise 12

#include "std_lib_facilities.h"

int main() {

	
	int max = 100;
	vector<int> seriesNum;
	vector<int> primeNum;

	cout << "Enter max for prime number generator: \n";
	cin >> max;

	for (int i = 2; i < max; i++) {
		int count = 0;
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				count++;
			}
		}
		if (count == 0) {
			primeNum.push_back(i);
		}
	}

	for (int i = 0; i < primeNum.size(); i++) {
		cout << primeNum[i] << "\n";
	}

	keep_window_open(".");

}