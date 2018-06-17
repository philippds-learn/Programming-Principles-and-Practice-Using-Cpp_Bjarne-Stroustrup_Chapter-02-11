//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 4 Drill 1

#include "std_lib_facilities.h"

int main()
{
	cout << "type in two integers or a '|' to terminate the program:\n";
	int x1;
	int x2;

	while (cin >> x1 >> x2)
	{
		if (x1 == '|')
		{
			return 0;
		}
		else
			cout << x1 << ", " << x2 << "\n";		
	}

	keep_window_open(".");
}