//	Philipp Siedler
//	Bjarne Stroustrup's PPP
//	Chapter 10 Exercise 5

#include "std_lib_facilities.h"

const int not_a_reading = -7777;
const int not_a_month = -1;

struct Day {
	vector<double> hour{ vector<double>(24,not_a_reading) };
};

struct Month {
	int month{ not_a_month };
	vector<Day> day{ 32 };
};

struct Year {
	int year;
	vector<Month> month{ 12 };
};

struct Reading {
	int day;
	int hour;
	double temperature;
};

istream& operator>>(istream& is, Reading& r) {
	char ch1;
	if (is >> ch1 && ch1 != '(') {
		is.unget();
		is.clear(ios_base::failbit);
		return is;
	}

	char ch2;
	int d;
	int h;
	double t;
	is >> d >> h >> t >> ch2;
	if (!is || ch2 != ')') error("bad reading");
	r.day = d;
	r.hour = h;
	r.temperature = t;
	return is;
}

void end_of_loop(istream& ist, char term, const string& message) {
	if (ist.fail()) {
		ist.clear();
		char ch;
		if (ist >> ch && ch == term) return;
		error(message);
	}
}

constexpr int implausible_min = -200;
constexpr int implausible_max = 200;

bool is_valid(const Reading& r) {
	if (r.day < 1 || 31 < r.day) return false;
	if (r.hour < 0 || 23 < r.hour) return false;
	if (r.temperature < implausible_min || implausible_max < r.temperature) {
		return false;
	}
	return true;
}

vector<string> month_input_tbl = {
	"jan", "feb", "mar", "apr", "may", "jun", "jul",
	"aug", "sep", "oct", "nov", "dec"
};

int month_to_int(string s) {
	for (int i = 0; i < 12; ++i) {
		if (month_input_tbl[i] == s) return i;
	}
}

vector<string> month_print_tbl = {
	"January", "February", "March", "April", "May", "June", "July",
	"August", "September", "October", "November", "December"
};

string int_to_month(int i) {
	if (i < 0 || 12 <= i) error("bad month index");
	return month_print_tbl[i];
}

istream& operator>>(istream& is, Month& m) {
	char ch = 0;
	if (is >> ch && ch != '{') {
		is.unget();
		is.clear(ios_base::failbit);
		return is;
	}

	string month_marker;
	string mm;
	is >> month_marker >> mm;
	if (!is || month_marker != "month") error("bad start of month");
	m.month = month_to_int(mm);

	int duplicates = 0;
	int invalids = 0;
	for (Reading r; is >> r;) {
		if (is_valid(r)) {
			if (m.day[r.day].hour[r.hour] != not_a_reading) {
				++duplicates;
			}
			m.day[r.day].hour[r.hour] = r.temperature;
		}
		else {
			++invalids;
		}
	}
	if (invalids) error("invalid readings in month", invalids);
	if (duplicates) error("duplicate readings in month", duplicates);
	end_of_loop(is, '}', "bad end of month");
	return is;
}

istream& operator>>(istream& is, Year& y) {
	char ch;
	is >> ch;
	if (ch != '{') {
		is.unget();
		is.clear(ios::failbit);
		return is;
	}

	string year_marker;
	int yy;
	is >> year_marker >> yy;
	if (!is || year_marker != "year") error("bad start of year");
	y.year = yy;

	while (true) {
		Month m;
		if (!(is >> m)) break;
		y.month[m.month] = m;
	}

	end_of_loop(is, '}', "bad end of year");
	return is;
}

ostream& operator<<(ostream& os, Year& y) {
	os << y.year;
	return os;
}

void print_years(ostream& ost, Year& y) {
	ost << y << endl;
}

int main()
try
{
	cout << "Please enter input file name\n";
	string iname;
	cin >> iname;

	ifstream ist{ iname };
	if (!ist) error("can't open input file ", iname);

	ist.exceptions(ist.exceptions() | ios_base::badbit);

	cout << "Please enter output file name\n";
	string oname;
	cin >> oname;
	ofstream ost{ oname };
	if (!ost) error("can't open output file", oname);
	
	vector<Year> ys;
	while (true) {
		Year y;
		if (!(ist >> y)) break;
		ys.push_back(y);
	}

	cout << "read " << ys.size() << " years of readings\n";

	for (Year& y : ys) print_years(ost, y);

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

