//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 3 Try This Page 81

#include "std_lib_facilities.h"

int main()
{
	cout << "Enter a value.\n";
	double d = 0;
	while (cin >> d){
		int i = d;
		char c = i;
		int i2 = c;
		cout << "d == " << d
			<< " i == " << i
			<< " i2 == " << i2
			<< " char(" << c << ")\n";
	}
	keep_window_open(".");
}