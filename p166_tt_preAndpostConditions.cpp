//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 5 Try This page 166

#include "std_lib_facilities.h"

int area(int length, int width) {
	if (length <= 0 || width <= 0) {
		error("area() pre-condition");
	}

	int a = length * width;

	if (a <= 0) {
		error("area() post-condition");
	}
	return a;
}

int main()
try
{

	int area1;
	area1 = area(60000, 60000);
	cout << area1;

	keep_window_open("x");
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