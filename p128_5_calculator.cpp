//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 4 Exercise 5

#include "std_lib_facilities.h"

int main() {
	
	double value1 = 0.0;
	double value2 = 0.0;
	char operat = ' ';

	cout << "Please enter two double values and an operator in a row with space in between.\n";

	while (cin >> value1 >> value2 >> operat)
	{
		if (operat == '+')
		{
			cout << value1 << " " << operat << " " << value2 << " equals to: " << value1 + value2 << "\n";
		}
		if (operat == '-')
		{
			cout << value1 << " " << operat << " " << value2 << " equals to: " << value1 - value2 << "\n";
		}
		if (operat == '/')
		{
			cout << value1 << " " << operat << " " << value2 << " equals to: " << value1 / value2 << "\n";
		}
		if (operat == '*')
		{
			cout << value1 << " " << operat << " " << value2 << " equals to: " << value1 * value2 << "\n";
		}
	}
	return 0;

	keep_window_open("-");
}