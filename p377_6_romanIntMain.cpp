//	Philipp Siedler
//	Bjarne Stroustrup's PPP
//	Chapter 10 Exercise 6

#include "p377_6_romanIntClass.h"

int main()
try
{
	Roman_int r;
	r.set_values();
	//cout << r;

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