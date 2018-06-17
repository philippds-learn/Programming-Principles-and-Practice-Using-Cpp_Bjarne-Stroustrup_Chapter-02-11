//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 8 Exercise 12.1

#include "std_lib_facilities.h"

vector<string> alphabet{ "a","b","c","d",
						"e","f","g","h",
						"a","b","c","d",
						"e","f","g","h" };

void print_until_ss(vector<string>& v, string quit, int quitNum) {
	int quitCount = 0;
	for (string s : v) {
		if (s == quit && quitCount < quitNum) {
			quitCount++;
			cout << s << "\n";
		}
		else if(quitCount == quitNum) {
			return;
		}
		else {
			cout << s << "\n";
		}
	}
}

int main()
try
{
	print_until_ss(alphabet, "c", 2);
	keep_window_open();
}

catch (runtime_error e) {
	cout << e.what() << "\n";
	keep_window_open();
}
catch (...) {
	cout << "Exiting\n";
	keep_window_open();
}