//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 5 Try This page 146

#include "std_lib_facilities.h"

int area(int length, int width) {
	if (length <= 0 || width <= 0) {
		return -1;}
	return length * width;
}

int framed_area(int x, int y) {
	constexpr int frame_width = 2;
	if (x - frame_width <= 0 || y - frame_width <= 0) {
		error("non-positive area() argument called by framed_area()");
	}
	return area(x - frame_width, y - frame_width);
}


double f(int x, int y, int z) {
	int area1 = area(x, y);
	if (area1 <= 0) {
		error("non-positive area");
	}
	cout << "area1 = " << area1 << '\n';

	if (x > 2 && y > 2 && z > 2) {
		int area2 = framed_area(3, z);
		int area3 = framed_area(y, z);
		double ratio = double(area1) / double(area3);

		cout << "area2 = " << area2 << '\n';
		cout << "area3 = " << area3 << '\n';
		cout << "ratio = " << ratio << '\n';
		return 0;
	}
	else {
		error("Input for x, y and z must be larger than frame width");
		return -1;
	}

}


int main()
try
{
	f(3, 3, 3);
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