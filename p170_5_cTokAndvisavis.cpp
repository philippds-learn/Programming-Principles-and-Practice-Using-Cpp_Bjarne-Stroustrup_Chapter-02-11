//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 5 Exercise 5

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

double ktoc(double k) {

	double lowestTempinK = 0;
	double highestTempinK = 330.95;
	double kelvin = 273.15;

	if (lowestTempinK >= k) {
		error("Temperature is unrealisticly low: ", k);
	}
	if (highestTempinK <= k) {
		error("Temperature is unrealisticly high: ", k);
	}

	double c = k - kelvin;

	if (c >= (lowestTempinK - kelvin) && c <= (highestTempinK - kelvin)) {
		return c;
	}
	else {
		error("post-condition ktoc()");
	}
}

int main()
try
{
	double value = 0;
	string unit;
	string s;

	cout << "Enter temperature with a c for celsius or k for kelvin, to be converted vis a vis: \n";

	if (cin >> value >> unit) {
		if(unit == "c"){
			double k = ctok(value);
			cout << value << " celsius are " << k << " kelvin" << '\n';
		}
		else if(unit == "k") {
			double c = ktoc(value);
			cout << value << " kelvin are " << c << " celsius" << '\n';
		}
		else {
			error("unit entered does not exist: ", unit);
		}
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