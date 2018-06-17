//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 8 Exercise 13

#include "std_lib_facilities.h"

class test {
	string label;
public:
	test(string _l) :label(_l) {};
	void print(const int); //can be used if the value is just localy used in the print function
};

void test::print(const int n) {
	cout << label << n << "\n";
}

int main()
try
{
	const int n = 2;
	test myTest("o ");
	myTest.print(n);

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