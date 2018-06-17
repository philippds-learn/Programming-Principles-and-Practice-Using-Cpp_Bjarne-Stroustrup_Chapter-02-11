//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 4 Try This page 116

#include "std_lib_facilities.h"

int square(int x)
{
	return x*x;
}

int main()
{
	for (int i = 0; i < 100; i++)
	{
		cout << i << '\t' << square(i) << '\n';
	}
	keep_window_open();
}
