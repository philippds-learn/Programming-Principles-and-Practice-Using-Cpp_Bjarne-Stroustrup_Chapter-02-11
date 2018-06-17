//	Philipp Siedler
//	Bjarne Stroustrup's PPP
//	Chapter 11 Drill 5

#include "std_lib_facilities.h"

int age = 28;

int main()
try
{
	int width = 12;
	cout << setw(width) << "decimal\t" << dec << age << endl;
	cout << setw(width) << "hexadecimal\t" << hex << age << endl;
	cout << setw(width) << "octadecimal\t" << oct << age << endl;

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