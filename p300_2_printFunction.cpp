//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 8 Exercise 2

#include "std_lib_facilities.h"

void print(string& _label, vector<int>& _vecInput) {
	for (int x : _vecInput) {
		cout << _label << " " << x << "\n";
	}
}

int main() {
	vector<int> myVector{ 1, 2, 3, 4, 5 };
	string label = "l";
	print(label, myVector);
	keep_window_open();
}