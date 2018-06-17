//	Philipp Siedler
//	Bjarne Stroustrup's PPP
//	Chapter 11 Exercise 5

#include "std_lib_facilities.h"

void calculate() {
	while (cin) {
		string word;
		char quit;
		cout << "enter string or char to decompose and classifie" << endl;
		if (cin >> quit && quit == 'x') {
			break;
		}
		cin.putback(quit);
		if (cin >> word) {
			for (char c : word) {
				if (isspace(c)) {
					cout << c << " is a space." << endl;
				}
				if (isalpha(c)) {
					cout << c << " is a letter." << endl;
				}
				if (isdigit(c)) {
					cout << c << " is a decimal digit." << endl;
				}
				if (isxdigit(c)) {
					cout << c << " is a hexadecimal digit." << endl;
				}
				if (isupper(c)) {
					cout << c << " is an upper case letter." << endl;
				}
				if (islower(c)) {
					cout << c << " is an lower case letter." << endl;
				}
				if (isalnum(c)) {
					cout << c << " is a letter or a decimal digit." << endl;
				}
				if (iscntrl(c)) {
					cout << c << " is a control character." << endl;
				}
				if (ispunct(c)) {
					cout << c << " is not a letter, digit, whitespace or invisible control character." << endl;
				}
				if (isprint(c)) {
					cout << c << " is printable." << endl;
				}
				if (isgraph(c)) {
					cout << c << " is isalpha(c) or isdigit(c) or ispunct(c)." << endl;
				}
			}
		}
		else {
			cin.clear();
			cout << "enter a valid string or x to quit" << endl;
		}
	}
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