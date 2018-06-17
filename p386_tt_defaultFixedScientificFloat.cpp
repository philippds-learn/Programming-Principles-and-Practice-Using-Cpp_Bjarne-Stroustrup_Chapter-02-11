//	Philipp Siedler
//	Bjarne Stroustrup's PPP
//	Chapter 11 Try This page 386

#include "std_lib_facilities.h"

double a = 1234567.89;

int main()
try
{
	//cout << setprecision(5) << a << endl; To set precision
	cout << defaultfloat << a << '\t'
		<< fixed << a << '\t' 
		<< scientific << a << '\n';

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