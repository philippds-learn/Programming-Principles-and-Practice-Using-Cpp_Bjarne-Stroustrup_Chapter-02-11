//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 4 Exercise 13

#include "std_lib_facilities.h"
#include "math.h"

int main() {

	int max = 100;
	vector<int> seriesNum;

	//fill series of numbers
	for (int i = 2; i < max; i++) {
		seriesNum.push_back(i);
	}

	//check for primes
	for (int j = 2; j < 6; j++) {
		for (int i = 0; i < seriesNum.size() - 1; i++) {
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