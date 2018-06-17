//	Philipp Siedler
//	Bjarne Stroustrup's PPP
//	Chapter 10 Exercise 2

#include "std_lib_facilities.h"

struct Reading {
	int hour;
	double temperature;
};

ostream& operator<<(ostream& os, Reading& _temps) {
	os << _temps.hour << " " << _temps.temperature << endl;
	return os;
}

vector<Reading> temps;

string oname = "output/raw_temps.txt";
ofstream ost(oname);

void fill_vector(vector<Reading>& _temps) {
	cout << "Generating Data." << endl;
	int h;
	double t;
	int temp_hour = 0;
	for (int i = 0; i < 50; i++) {
		if (!(i % 24)) {
			temp_hour = 0;
		}
		h = temp_hour;
		t = randint(90);
		_temps.push_back(Reading{ h, t });
		temp_hour++;
	}
}


void write_file(vector<Reading>& _temps) {
	cout << "Writing File." << endl;
	for (int i = 0; i < temps.size(); i++) {
		ost << _temps[i];
	}
	cout << "Done!" << endl;
}

int main()
try
{

	fill_vector(temps);
	write_file(temps);

	keep_window_open();
}
catch(runtime_error e) {
	cout << e.what() << endl;
	keep_window_open();
}
catch (...) {
	cout << "Exiting" << endl;
	keep_window_open();
}