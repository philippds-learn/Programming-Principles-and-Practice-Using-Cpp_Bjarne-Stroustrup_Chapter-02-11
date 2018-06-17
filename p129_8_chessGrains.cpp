//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 4 Exercise 8

#include "std_lib_facilities.h"

int main() {

	int squareNum = 1;
	int grainCount = 1;
	int sumGrainCount = 0;

	for (int i = 1; i < 65; i++) {
		squareNum = i;
		grainCount *= 2;
		sumGrainCount += grainCount;

		cout << "Square number: " << squareNum << " / Grain number on square: " << grainCount << " / Total grain number: " << sumGrainCount << '\n';
	}

	keep_window_open(".");
}