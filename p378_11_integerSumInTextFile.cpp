//	Philipp Siedler
//	Bjarne Stroustrup's PPP
//	Chapter 10 Exercise 11

#include "std_lib_facilities.h"

void read(ifstream& _ist, double& _sum) {
	char in;

	while (true) {
		if (_ist.eof()) {
			break;
		}
		else {
			_ist >> in;
			if (isdigit(in)) {
				_ist.unget();
				double d;
				_ist >> d;
				_sum += d;
			}
		}
	}
}

void calculate() {
	double sum = 0;
	ifstream ist{ "input/ch10_11_in.txt" };
	read(ist, sum);
	cout << sum << endl;
}

int main()
try {

	calculate();
	keep_window_open();
}
catch (exception& e) {
	cout << e.what() << endl;
	keep_window_open();
}
catch (...) {
	cout << "Exiting" << endl;
	keep_window_open();
}