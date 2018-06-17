//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 5 Exercise 4

#include "std_lib_facilities.h"

double ctok(double c) {

	double lowestTempinC = -273.15;
	double highestTempinC = 57.8;
	double kelvin = 273.15;

	if (lowestTempinC >= c) {
		error("Temperature is unrealisticly low: ", c);
	}
	if (highestTempinC <= c) {
		error("Temperature is unrealisticly high: ", c);
	}

	double k = c + kelvin;

	if (k >= (lowestTempinC + kelvin) && k <= (highestTempinC + kelvin)) {
		return k;
	}
	else {
		error("post-condition ctok()");
	}
}

int main()
try
{
	double c = 0;
	string s;
	cout << "Enter temperature in celsius to be converted to kelvin: \n";

	if (cin >> c) {
		double k = ctok(c);
		cout << k << '\n';
	}
	else {
		cin.clear();
		cin >> s;
		error("Illegal input entered: ", s);
	}

	keep_window_open();
}
catch (runtime_error e) {
	cout << e.what() << "\n";
	keep_window_open(".");
}
catch (...) {
	cout << "Exiting \n";
	keep_window_open(".");
}