//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 3 Exercise 2

#include "std_lib_facilities.h"

int main()
{
	int mile;
	cout << "enter miles\n";
	cin >> mile;
	cout << mile << "miles are " << mile*1.609 << " km\n";
	keep_window_open();
}