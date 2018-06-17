//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 3 Exercise 8

#include "std_lib_facilities.h"

int main()
{
	cout << "enter an integer to test if it is odd or even: ";
	int valueToTest;
	cin >> valueToTest;

	if (valueToTest % 2 == 1)
	{
		cout << valueToTest << " is an odd number\n";
	}
	else
	{
		cout << valueToTest << " is an even number\n";
	}
		
	keep_window_open();
}