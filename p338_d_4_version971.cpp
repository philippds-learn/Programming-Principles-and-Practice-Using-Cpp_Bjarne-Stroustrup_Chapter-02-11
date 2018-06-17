//	Philipp Siedler
//	Bjarne Stroustrup's PPP
//	Chapter 9 Drill 4

#include "std_lib_facilities.h"

class Date {
public:
	enum Month {
		jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
	};

	Date(int y, Month m, int d);
	void add_day(int n);

	int year() const { return y; }
	Month month() const { return m; }
	int day() const { return d; }

private:
	int y;
	Month m;
	int d;
};

Date::Date(int y0, Date::Month m0, int d0) {
	d = d0;
	m = m0;
	y = y0;
}

void Date::add_day(int n) {
	d += n;
}

static ostream & operator<< (ostream & os, const Date::Month & m) {
	switch (m) {
	case Date::jan: os << "January"; break;
	case Date::feb: os << "February"; break;
	case Date::mar: os << "March"; break;
	case Date::apr: os << "April"; break;
	case Date::may: os << "May"; break;
	case Date::jun: os << "June"; break;
	case Date::jul: os << "July"; break;
	case Date::aug: os << "August"; break;
	case Date::sep: os << "September"; break;
	case Date::oct: os << "October"; break;
	case Date::nov: os << "November"; break;
	case Date::dec: os << "December"; break;
	}
	return os;
}


ostream & operator<< (ostream & os, const Date & dd) {
	os << "Year: " << dd.year() << " Month: " << dd.month() << " Day: " << dd.day() << endl;
	return os;
}

int main()
try
{
	Date today{ 1978, Date::jun, 25 };
	Date tomorrow = today;
	tomorrow.add_day(1);

	cout << today;
	cout << tomorrow;
	
	keep_window_open();
}

catch (runtime_error e) {
	cout << e.what() << '\n';
	keep_window_open();
}
catch (...) {
	cout << "Exiting" << '\n';
	keep_window_open();
}