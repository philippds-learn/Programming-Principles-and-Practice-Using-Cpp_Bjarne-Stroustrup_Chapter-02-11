//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 3 Exercise 5

#include "std_lib_facilities.h"

int main()
{
	double val1, val2;
	cout << "enter one float value ";
	cin >> val1;
	cout << "enter another float value ";
	cin >> val2;
	cout << val1 << ", " << val2 << "\n";

	if (val1 < val2)
		cout << "val1 " << val1 << " is smaller than val2 " << val2 << "\n";
	else
		cout << "val1 " << val1 << " is larger than val2 " << val2 << "\n";

	cout << "the sum of val1 and val2 is " << val1 + val2 << "\n";
	cout << "the difference of val1 minus val2 is " << val1 - val2 << "\n";
	cout << "the product of val1 and val2 is " << val1 * val2 << "\n";
	cout << "the ratio of val1 to val2 is " << val1 / val2 << "\n";

	keep_window_open();
}