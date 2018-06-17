//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 3 Try This Page 68

#include "std_lib_facilities.h"
#define Res 10

int main()
{
	cout << "Please enter a integer value\n";
	int n;

	cin >> n;
	cout << "n ==" << n
		<< "\nn + 1 ==" << n + 1
		<< "\nthree times n ==" << 3 * n
		<< "\ntwice n ==" << n + n
		<< "\nn squared ==" << n*n
		<< "\nhalf of n ==" << n / 2
		<< "\nsquare root of n ==" << sqrt(n)
		<< "\nremainder of n " << n % 2
		<< "\nmodulor of n and 2 ==" << n % 2
		<< "\nmodulor of n and 3 ==" << n % 3
		<< '\n';
	keep_window_open();
}