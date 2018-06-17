//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 8 Exercise 12.0

#include "std_lib_facilities.h"

vector<string> alphabet{ "a","b","c","d",
						"e","f","g","h",
						"i","j","k","l",
						"m","n","o","p",
						"q","r","s","t",
						"u","v","w","x",
						"y","z" };

void print_until_s(vector<string>& v, string quit) {
	for (string s : v) {
		if (s == quit) return;
		cout << s << "\n";
	}
}

int main()
try
{
	print_until_s(alphabet, "k");
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

/*
a
b
c
d
e
f
g
h
i
j
Please enter a character to exit
*/