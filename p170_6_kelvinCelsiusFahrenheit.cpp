//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 5 Exercise 6

#include "std_lib_facilities.h"

double ctoftok(double c) {

	//celsius to fahrenheit to kelvin

	double lowestTempinC = -273.15;
	double highestTempinC = 57.8;
	double kelvin = 273.15;

	if (lowestTempinC >= c) {
		error("Temperature is unrealisticly low: ", c);
	}
	if (highestTempinC <= c) {
		error("Temperature is unrealisticly high: ", c);
	}

	double f = 9.0 / 5 * c + 32;
	double k = c + kelvin;

	cout << "celsius: " << c << ", fahrenheit: " << f << ", kelvin: " << k << "\n";
	return 0;
}

int main()
try
{
	double value = 0;
	string s;

	cout << "Enter temperature in celsius degree to get fahrenheit and kelvin: \n";

	if (cin >> value) {
		ctoftok(value);
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