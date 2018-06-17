//	Philipp Siedler
//	Bjarne Stroustrup's PPP
//	Chapter 11 Try This page 388

#include "std_lib_facilities.h"

int main()
try
{
	int width = 25;
	cout << setw(width) << "last name" << ", "
		<< setw(width) << "first name" << ", "
		<< setw(width) << "number" << ", "
		<< setw(width) << "email" << endl;
	cout << setw(width) << "Siedler" << ", "
		<< setw(width) << "Philipp" << ", "
		<< setw(width) << "07490091166" << ", "
		<< setw(width) << "p.d.siedler@gmail.com" << endl;

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