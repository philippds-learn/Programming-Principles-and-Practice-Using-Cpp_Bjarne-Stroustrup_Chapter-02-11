//	Philipp Siedler
//	Bjarne Stroustrup's PPP
//	Chapter 11 Exercise 1

#include "std_lib_facilities.h"

void to_lower_case_out() {
	string iname = "input/p408_1_blind_text.txt";
	ifstream ifs{ iname };

	string temp;
	getline(ifs, temp);

	for (char& x : temp) {
		x = tolower(x);
	}

	string oname = "output/p408_1_blind_text_out.txt";
	ofstream ofs{ oname };
	ofs << temp;
}

int main()
try
{
	to_lower_case_out();
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