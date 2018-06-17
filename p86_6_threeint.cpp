//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 3 Exercise 6

#include "std_lib_facilities.h"

int main()
{
	int val1, val2, val3;
	int smallest = 0, medium = 0, largest = 0;
	cout << "enter tree integer value ";
	cin >> val1 >> val2 >> val3;
	cout << "you entered three values: " << "val1: " << val1 << ", val2: " << val2 << ", val3: " << val3 << "\n";

	if (val1 <= val2 && val1 <= val3)
	{
		smallest = val1;
		if (val2 <= val3)
		{
			medium = val2;
			largest = val3;
		}
		else
		{
			medium = val3;
			largest = val2;
		}
	}
	
	if (val2 <= val1 && val2 <= val3)
	{
		smallest = val2;
		if (val1 <= val3)
		{
			medium = val1;
			largest = val3;
		}
		else
		{
			medium = val3;
			largest = val1;
		}
	}

	if (val3 <= val2 && val3 <= val1)
	{
		smallest = val3;
		if (val1 <= val3)
		{
			medium = val1;
			largest = val2;
		}
		else
		{
			medium = val2;
			largest = val1;
		}
	}
	
	cout << smallest << ", " << medium << ", " << largest << "\n";
	keep_window_open();
}