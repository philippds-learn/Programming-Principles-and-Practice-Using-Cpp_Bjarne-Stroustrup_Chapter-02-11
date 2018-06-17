//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 4 Try This page 113

#include "std_lib_facilities.h"

int main()
{
	for (char character = 'A'; character != 'Z' + 1; character++)
	{
		int integer = character;
		cout << character << '\t' << integer << '\n';
	}
	keep_window_open();
}
