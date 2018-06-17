//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 9 Drill 1

#include "std_lib_facilities.h"

struct Date {
	int y;
	int m;
	int d;
};

void init_day(Date& dd, int y, int m, int d) {
	dd.y = y;
	dd.m = m;
	dd.d = d;
}

void add_day(Date& dd, int n) {
	dd.d += n;
}

int main()
try
{
	Date today;
	Date tomorrow;

	init_day(today, 2005, 12, 24);
	tomorrow = today;
	add_day(tomorrow, 1);

	cout << "Year: " << today.y << " Month: " << today.m << " Day: " << today.d << "\n";
	cout << "Year: " << tomorrow.y << " Month: " << tomorrow.m << " Day: " << tomorrow.d << "\n";

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