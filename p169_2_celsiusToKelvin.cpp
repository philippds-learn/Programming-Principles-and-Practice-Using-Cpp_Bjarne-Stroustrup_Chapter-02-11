//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 5 Exercise 2

#include "std_lib_facilities.h"

/*
double ctok(double c) {
	int k = c + 273.15;
	return int
}

int main(){
	double c = 0;
	cin >> d;
	double k = ctok("c");
	Cout << k << '\n';
}
*/

//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 5 Exercise 2

double ctok(double c) {
	int k = c + 273.15;
	return k;
}

int main() {
	double c = 0;
	cin >> c;
	double k = ctok(c);
	cout << k << '\n';

	keep_window_open();
}
