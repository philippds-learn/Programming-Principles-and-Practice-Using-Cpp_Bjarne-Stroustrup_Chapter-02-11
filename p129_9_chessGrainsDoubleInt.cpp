//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 4 Exercise 9

#include "std_lib_facilities.h"

int main() {

	cout << "Grains on chess board as integers: \n\n";
	int squareNumi = 1;
	int grainCounti = 1;
	int sumGrainCounti = 0;

	for (int i = 1; i < 65; i++) {
		squareNumi = i;
		grainCounti *= 2;
		sumGrainCounti += grainCounti;

		cout << "Square number: " << squareNumi << " / Grain number on square: " << grainCounti << " / Total grain number: " << sumGrainCounti << '\n';
	}

	cout << "\n\nGrains on chess board as integers: \n\n";
	double squareNumd = 1;
	double grainCountd = 1;
	double sumGrainCountd = 0;

	for (int i = 1; i < 65; i++) {
		squareNumd = i;
		grainCountd *= 2;
		sumGrainCountd += grainCountd;

		cout << "Square number: " << squareNumd << " / Grain number on square: " << grainCountd << " / Total grain number: " << sumGrainCountd << '\n';
	}

	keep_window_open(".");

}