//	Philipp Siedler
//	Bjarne Stroustrup's PPP
//	Chapter 11 Drill 9

#include "std_lib_facilities.h"

/*
input: 1234567.89

output:
defaultfloat    1.23457e+06
fixed     1234567.890000
scientific     1.234568e+06

Explanation:
Most accurate is fixed. defaultfloat and scientific actually lose data.
*/

void print_num(double _num) {
	int width = 12;
	cout << setw(width) << "defaultfloat\t" << defaultfloat << _num << endl;
	cout << setw(width) << "fixed\t" << fixed <<_num << endl;
	cout << setw(width) << "scientific\t" << scientific << _num << endl;
}

int main()
try
{
	double num = 1234567.89;

	print_num(num);

	keep_window_open();
}
catch (runtime_error e) {
	cout << e.what() << endl;
	keep_window_open();
}
catch (...) {
	cout << "Exiting" << endl;
	keep_window_open();
}