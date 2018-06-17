//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 4 Try This page 111

#include "std_lib_facilities.h"

int main()
{
	char character = 'a';
	while (character != 'z'+1)
	{
		int integer = character;
		cout << character << '\t' << integer << '\n';
		++character;
	}
keep_window_open();
}