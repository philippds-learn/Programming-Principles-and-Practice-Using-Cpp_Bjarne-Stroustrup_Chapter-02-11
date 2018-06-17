//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 9 Drill 2

#include "std_lib_facilities.h"

struct Date {
	int y, m, d;
	Date(int y, int m, int d);
	void add_day(int n);
};

Date::Date(int _y, int _m, int _d) {
	y = _y;
	m = _m;
	d = _d;
}

void Date::add_day(int n) {
	d += n;
}

int main()
try
{
	Date today { 1978, 6, 25 };
	Date tomorrow = today;

	tomorrow.add_day(1);

	cout << "Year: " << today.y << " Month: " << today.m << " Day: " << today.d << "\n";
	cout << "Year: " << tomorrow.y << " Month: " << tomorrow.m << " Day: " << tomorrow.d << "\n";

	keep_window_open();
}

catch(runtime_error e) {
	cout << e.what() << "\n";
	keep_window_open();
}
catch (...) {
	cout << "Exiting\n";
	keep_window_open();
}