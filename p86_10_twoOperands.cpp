//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 3 Exercise 10

#include "std_lib_facilities.h"

int main()
{
	string operation;
	double val1 = 0;
	double val2 = 0;
	double solution = 0;
	cout << "enter an operator and two values divided by space: ";

	while (cin >> operation >> val1 >> val2)
	{
		if (operation == "+") solution = val1 + val2;
		else if (operation == "-") solution = val1 - val2;
		else if (operation == "*") solution = val1 * val2;
		else if (operation == "/") solution = val1 / val2;
		cout << solution;
	}
	keep_window_open();
}