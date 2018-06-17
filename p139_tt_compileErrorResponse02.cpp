//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 5 Try This page 139

#include "std_lib_facilities.h"

int area(int length, int width) {
	return length * width;
}

int main()
try
{
	//int x0 = arena(7);
	//int x1 = area(7);
	//int x2 = area("seven",2);
	keep_window_open();
}

catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}

catch (...) {
	cerr << "Unknown exception!\n";
	keep_window_open();
	return 2;
}