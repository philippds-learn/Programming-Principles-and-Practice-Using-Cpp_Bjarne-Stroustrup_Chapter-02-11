//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 4 Drill 9

#include "std_lib_facilities.h"

int main()
{
	cout << "Enter a double followed by m(meter) in(inch) ft(feet) or cm(centimeter or a '|' to terminate the program:\n";
	vector<double> numbers;
	double x;
	double y;
	string unit;

	while (cin >> x >> unit)
	{
		if (unit == "m")
		{
			y = x;
		}

		else if (unit == "in")
		{
			y = (x * 2.54)/100;
		}

		else if (unit == "ft")
		{
			y = ((x / 12)*2.54)/100;
		}

		else if (unit == "cm")
		{
			y = x/100;
		}

		else
		{
			cout << "I dont know what " << unit << " for a unit is, enter a valid unit \n";
			continue;
		}

		cout << "you entered: " << x << " " << unit << "\n\n";

		numbers.push_back(y);

		double sum = 0;
		for (int i = 0; i < numbers.size(); i++)
		{
			sum += numbers[i];
		}
		cout << "the sum of all numbers in m is: " << sum << " m\n";
		sort(numbers);
		cout << "the smallest so far is: " << numbers[0] << " " << "m\n";	
		cout << "the largest so far is: " << numbers[numbers.size()-1] << " " << "m\n";
		cout << "you have entered: " << numbers.size() << " values\n";
		for (int i = 0; i < numbers.size(); i++)
		{
			cout << numbers[i] << ", ";
		}
		cout << "\n";
	}
}