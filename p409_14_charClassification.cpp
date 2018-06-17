//	Philipp Siedler
//	Bjarne Stroustrup's PPP
//	Chapter 11 Exercise 14

#include "std_lib_facilities.h"

int main()
try
{
	cout << "enter name for input file" << endl;
	string iname = "input/";
	string itemp;
	cin >> itemp;
	iname += itemp;
	ifstream ifs{ iname };
	if (!ifs) { cout << "could not open input file." << endl; }

	int letters = 0;
	int pointComma = 0;
	int wss = 0;

	for (char ch; ifs.get(ch);) {
		if (isspace(ch)) {
			wss++;
		}
		else if (ch == ',' || ch == '.') {
			pointComma++;
		}
		else {
			letters++;
		}
	}

	cout << "Letters: " << letters << endl;
	cout << "Point's & Comma's: " << pointComma << endl;
	cout << "Whitespaces: " << wss << endl;

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

/*
<pre><strong>Output:</strong>
enter name for input file
p409_14_blind_text.txt
Letters: 1106
Point's & Comma's: 63
Whitespaces: 199
</pre>
*/