//	Philipp Siedler
//	Bjarne Stroustrup's PPP
//	Chapter 11 Try This page 384

#include "std_lib_facilities.h"

int a, b, c, d;

int main()
try
{
	//user input: 1234 1234 1234 1234
	//cin.unsetf(ios::dec); To reset cin
	cin >> a >> hex >> b >> oct >> c >> d;
	cout << a << '\t' << b << '\t' << c << '\t' << d << '\n';

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