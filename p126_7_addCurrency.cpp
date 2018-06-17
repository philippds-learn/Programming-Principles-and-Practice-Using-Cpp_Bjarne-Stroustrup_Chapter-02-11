//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 4 Drill 7

#include "std_lib_facilities.h"

int main()
{
	cout << "Enter a double value followed by m(meter) in(inch) ft(feet) or cm(centimeter or a '|' to terminate the program:\n";
	vector<double> numbers;
	double x;
	double y;
	string unit;

	while (cin >> x >> unit)
	{
		if (unit == "m")
		{
			y = x * 100;
		}

		else if (unit == "in")
		{
			y = x * 2.54;
		}

		else if (unit == "ft")
		{
			y = (x / 12)*2.54;
		}

		else if (unit == "cm")
		{
			y = x;
		}

		numbers.push_back(y);
		cout << "you entered: " << x << " " << unit << "\n";
		sort(numbers);
		if (y == numbers[0]){
			cout << "the smallest so far is: " << x << " " << unit << "\n";
		}
		if (y == numbers[numbers.size() - 1]){
			cout << "the largest so far is: " << x << " " << unit << "\n";
		}
		cout << "\n";
	}
}