//	Philipp Siedler
//	Bjarne Stroustrup's PPP
//	Chapter 11 Exercise 4

#include "std_lib_facilities.h"

void convert() {
	char quit;
	int val;
	char prefix_zero;
	char prefix_x;

	while (cin) {
		if (cin >> quit && quit == 'x') {
			break;
		}
		else {
			cin.putback(quit);
			cin >> prefix_zero;
			if (prefix_zero == '0') {
				if (cin >> prefix_x && prefix_x == 'x') {
					cin.putback(prefix_x);
					cin.putback(prefix_zero);
					cin >> hex >> val;
					cout << setw(4) << "0x" << hex << val
						<< " hexadecimal\tconverts to\t"
						<< dec << val << " decimal" << endl;
				}
				else {
					cin.putback(prefix_x);
					cin.putback(prefix_zero);
					cin >> oct >> val;
					cout << setw(3) << "0" << oct << val
						<< " octal\t\tconverts to\t"
						<< dec << val << " decimal" << endl;
				}
			}
			else {
				cin.putback(prefix_zero);
				cin >> dec >> val;
				cout << setw(6) << val
					<< " decimal\t\tconverts to\t"
					<< val << " decimal" << endl;
			}
		}
	}
}

void calculate() {
	cout << "enter hexadecimals e.: 0x43, octals e.: 0123 or decimals e.: 65" << endl;
	convert();
}

int main()
try
{
	calculate();
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