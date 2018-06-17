//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 8 Drill 2

#include "std_lib_facilities.h"

void swap_v(int a, int b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void swap_r(int& a, int& b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}

/* Nope.
void swap_cr(const int& a,const int& b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}
*/

int main() {
	//int x = 7;
	//int y = 9;
	//swap_v(x, y); Nope.
	//swap_r(x, y); Success!
	//cout << "x: " << x << " y: " << y << "\n";

	//swap_v(7, 9);
	//cout << "x: " << x << " y: " << y << "\n";
	//swap_r(7, 9); Nope.

	//const int cx = 7;
	//const int cy = 9;
	//swap_v(cx, cy); Nope.
	//swap_r(cx, cy); //Nope.
	//cout << "cx: " << cx << " cy: " << cy << "\n";

	//swap_v(7.7, 9.9); Nope.
	//swap_r(7.7, 9.9); Nope.

	//double dx = 7.7;
	//double dy = 9.9;
	//swap_v(dx, dy); Nope.
	//swap_r(dx, dy); Nope.
	//cout << "dx: " << dx << " dy: " << dy << "\n";

	keep_window_open(".");
}