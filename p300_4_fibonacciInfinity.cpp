//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 8 Exercise 4

#include "std_lib_facilities.h"

vector<int> myVec;
string label = "l";

void print(string& _label, vector<int>& _vecInput) {
	for (int x : _vecInput) {
		cout << _label << " " << x << "\n";
	}
}

void fibonacci(int x, int y, vector<int>& v) {
	v.push_back(x);
	v.push_back(y);
	while(true){
		int temp;
		if (x > 0 && y > 0 && x + y > 0) {
			v.push_back(x + y);
			temp = y;
			y = x + y;
			x = temp;
		}
		else {
			break;
		}
	}
}

int main() 
try
{
	fibonacci(1, 2, myVec);
	print(label, myVec);

	cout << "The maximum number of the fibonacci sequence is: " << &myVec[myVec.size() - 1] << "\n";

	keep_window_open();

}

catch (runtime_error e) {
	cout << e.what() << "\n";
	keep_window_open(".");
}
catch (...) {
	cout << "Extiting" << "\n";
	keep_window_open(".");
}