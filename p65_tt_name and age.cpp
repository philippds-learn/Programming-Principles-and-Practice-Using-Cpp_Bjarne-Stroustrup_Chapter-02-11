//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 3 Try This Page 65

#include "std_lib_facilities.h"

int main()
{
	string first_name;
	double age;

	cout << "Please enter your first name and age\n";
	cin >> first_name;
	cin >> age;
	cout << "Hello, " << first_name << " (age " << age*12 << " month)\n";
	keep_window_open();
}