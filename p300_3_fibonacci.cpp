//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 8 Exercise 3

#include "std_lib_facilities.h"

void print(string& _label, vector<int>& _vecInput) {
	for (int x : _vecInput) {
		cout << _label << " " << x << "\n";
	}
}

void fibonacci(int x, int y, vector<int>& v, int n) {
	v.push_back(x);
	v.push_back(y);
	for (int i = 0; i < n; i++) {
		int temp;
		v.push_back(x + y);
		temp = y;
		y = x + y;
		x = temp;
	}
}

int main()
try
{
	vector<int> myVec;
	string label = "l";
	int num = 20;

	fibonacci(1, 2, myVec, num);

	print(label, myVec);

	keep_window_open();

}

catch (runtime_error e) {
	cout << e.what() << "\n";
	keep_window_open();	
}

catch(...) {
	cout << "Exiting\n";
	keep_window_open();
}