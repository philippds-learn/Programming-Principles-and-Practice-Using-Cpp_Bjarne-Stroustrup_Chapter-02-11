//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 4 Drill 5

#include "std_lib_facilities.h"

int main()
{
	cout << "type in two doubles or a '|' to terminate the program:\n";
	double x1;
	double x2;
	double difference;
	while (cin >> x1 >> x2)
	{
		if (x1 < x2){
			cout << "the smaller number is x1: " << x1 << "\n";
			cout << "the larger number is x2: " << x2 << "\n";
			difference = x2 - x1;
			if (difference <= 1.0 / 100){
				cout << "the numbers are almost equal" << "\n";
			}
		}
		else if (x1 == x2){
			cout << "the numbers are equal" << "\n";
		}
		else{
			cout << "the larger number is x1: " << x1 << "\n";
			cout << "the smaller number is x2: " << x2 << "\n";
			difference = x1 - x2;
			if (difference <= 1.0 / 100){
				cout << "the numbers are almost equal" << "\n";
			}
		}
	}
	return 0;
}