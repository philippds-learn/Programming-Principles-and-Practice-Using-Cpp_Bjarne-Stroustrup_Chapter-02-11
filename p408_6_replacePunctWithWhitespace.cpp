//	Philipp Siedler
//	Bjarne Stroustrup's PPP
//	Chapter 11 Exercise 6

#include "std_lib_facilities.h"

void calculate() {
	while (cin) {
		string s;
		string s_mod;
		char quit;
		cout << "enter string and I will replace punctuation with a whitespace" << endl;
		if (cin >> quit && quit == 'x') {
			break;
		}
		cin.putback(quit);
		if (getline(cin, s)) {
			for (char c : s) {
				if (!ispunct(c)) {
					s_mod += c;
				}
				else {
					s_mod += " ";
				}
			}
			cout << s_mod << endl;
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