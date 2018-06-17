//	Philipp Siedler
//	Bjarne Stroustrup's PPP
//	Chapter 11 Drill 1

#include "std_lib_facilities.h"

int birth_year = 1988;

int main()
try
{
	
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