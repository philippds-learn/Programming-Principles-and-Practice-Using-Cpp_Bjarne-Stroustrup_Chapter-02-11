//	Philipp Siedler
//	Bjarne Stroustrup's PPP
//	Chapter 9 Drill 5

#include "std_lib_facilities.h"

class Date {
public:
	enum Month {
		jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
	};

	Date(int y, Month m, int d) : y(y), m(m), d(d) {};
	void add_day(int n);
	void add_month(int n);
	void add_year(int n);

	int day() const { return d; }
	Month month() const { return m; }
	int year() const { return y; }

private:
	int y;
	Month m;
	int d;
};

void Date::add_day(int n) {
	d += n;
}

void Date::add_month(int n) {
	m = Month(int(m) + 1);
}

void Date::add_year(int n) {
	y += n;
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

/*
static ostream & operator<< (ostream & os, const Date::Month & m) {
	os << int(m);
	return os;
}
*/

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
	tomorrow.add_month(1);

	cout << today;
	cout << tomorrow;

	keep_window_open();
}

catch (runtime_error e) {
	cout << e.what() << "\n";
	keep_window_open();
}
catch (...) {
	cout << "Exiting\n";
	keep_window_open();
}

