//	Philipp Siedler
//	Bjarne Stroustrup's PPP
//	Chapter 10 Exercise 1

#include "std_lib_facilities.h"


int result = 0;
string iname = "input/num.txt";
ifstream ist(iname);

void read_file() {
	int temp;
	if (!ist) { error("File could not be read: ", iname); }
	while (ist >> temp) {
		result += temp;
	}
}

int main()
try
{
	read_file();
	cout << result << endl;
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