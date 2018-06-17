//	Philipp Siedler
//	Bjarne Stroustrup's PPP
//	Chapter 11 Drill 8

#include "std_lib_facilities.h"

/*
input: 1234 1234 1234 1234

output:
decimal			1234
octadecimal     668
hexadecimal     4660
hexadecimal     4660

Explanation:
Input was transformed into hexadecimal and octadecimal and then casted to an integer, therefor integer value.
*/

void set_age(int& _a, int& _ao, int& _ah, int& _ah1) {
	while (true) {
		cout << "enter your age" << endl;
		if (cin >> _a >> oct >> _ao >> hex >> _ah >> _ah1) {
			break;
		}
		else {
			cout << "enter intger age" << endl;
			cin.clear();
		}
	}
}

int main()
try
{
	int age;
	int age_oct;
	int age_hex;
	int age_hex1;

	set_age(age, age_oct, age_hex, age_hex1);

	int width = 12;
	cout << setw(width) << "decimal\t" << age << endl;
	cout << setw(width) << "octadecimal\t" << age_oct << endl;
	cout << setw(width) << "hexadecimal\t" << age_hex << endl;
	cout << setw(width) << "hexadecimal\t" << age_hex1 << endl;
	
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