//	Philipp Siedler
//	Bjarne Stroustrup's PPP
//	Chapter 11 Drill 3

#include "std_lib_facilities.h"

int birth_year = 1988;

int main()
try
{
	cout <<  "decimal " << dec << birth_year << endl;
	cout <<  "hexadecimal " << hex << birth_year << endl;
	cout <<  "octadecimal " << oct << birth_year << endl;

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