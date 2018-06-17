//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 4 Drill 6

#include "std_lib_facilities.h"

int main()
{
	cout << "type in doubles to be compared or a '|' to terminate the program:\n";
	vector<double> numbers;
	double x;

	while (cin >> x)
	{
		numbers.push_back(x);
		cout << "you entered: " << x << "\n";
		sort(numbers);
		if (x == numbers[0]){
			cout << "the smallest so far is: " << x << "\n";
		}
		if (x == numbers[numbers.size() - 1]){
			cout << "the largest so far is: " << x << "\n";
		}
		cout << "\n";
	}
}