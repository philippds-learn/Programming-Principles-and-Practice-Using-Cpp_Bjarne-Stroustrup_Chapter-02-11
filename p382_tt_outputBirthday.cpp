//	Philipp Siedler
//	Bjarne Stroustrup's PPP
//	Chapter 11 Try This page 382

#include "std_lib_facilities.h"

int main()
try
{
	int my_birth_year = 1988;
	int my_age = 28;

	cout << "My birth year:" << endl;
	cout << my_birth_year << "\t(decimal)\n"
		<< hex << my_birth_year << "\t(hexadecimal)\n"
		<< oct << my_birth_year << "\t(octal)\n";

	cout << "My age:" << endl;
	cout << dec << my_age << "\t(decimal)\n"
		<< hex << my_age << "\t(hexadecimal)\n"
		<< oct << my_age << "\t(octal)\n";

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