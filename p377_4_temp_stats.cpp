//	Philipp Siedler
//	Bjarne Stroustrup's PPP
//	Chapter 10 Exercise 4

#include "std_lib_facilities.h"

struct Reading {
	int hour;
	double temperature;
	char suffix;
	Reading(int h, double t, char s) :hour(h), temperature(t), suffix(s) {}
};

ostream& operator<<(ostream& os, Reading& _temps) {
	os << _temps.hour << " " << _temps.temperature << " " << _temps.suffix << endl;
	return os;
}

struct Stats {
	double mean;
	double median;
};

ostream& operator<<(ostream& os, Stats _stats) {
	os << "mean: " << _stats.mean << " median: " << _stats.median << endl;
	return os;
}

vector<Reading> temps;

string iname = "raw_temps.txt";
ifstream ist(iname);

void read_file(vector<Reading>& _temps, string _file_name) {
	if (!ist) { error("Could not open file", _file_name); }
	cout << "Reading file." << endl;
	int h;
	double t;
	char s;
	while (ist >> h >> t >> s) {
		if (s == 'c') {
			t = (t * (9.0 / 5.0)) + 32;
			s = 'f';
		}
		temps.push_back(Reading{ h, t, s });
	}
	cout << "Done!" << endl;
}

Stats calculate_stats(vector<Reading>& _temps) {
	cout << "Calculating mean and median." << endl;
	double sum = 0;
	double mean;
	double median;
	int size = int(_temps.size());


	for (int i = 0; i < size; i++) {
		sum += _temps[i].temperature;
	}
	mean = sum / size;

	vector<double> sorted_temps;
	for (int i = 0; i < size; i++) {
		sorted_temps.push_back(_temps[i].temperature);
	}
	sort(sorted_temps);

	if (size % 2 == 0) {
		median = (sorted_temps[size / 2] + sorted_temps[(size / 2) - 1]) / 2;
	}
	else {
		median = sorted_temps[(size - 1) / 2];
	}
	return Stats{ mean, median };
}

int main()
try
{
	read_file(temps, iname);
	cout << calculate_stats(temps);

	for (Reading i : temps) {
		cout << i;
	}

	keep_window_open();

}
catch (runtime_error e) {
	cout << e.what() << endl;
	keep_window_open();
}
catch (...) {
	cout << "Exiting" << endl;
	keep_window_open();
}