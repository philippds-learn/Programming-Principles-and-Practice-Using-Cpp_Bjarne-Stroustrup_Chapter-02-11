//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 8 Exercise 10

#include "std_lib_facilities.h"

vector<int> myVec{ 1, 2, 5, 4, 1, 8, 2, 3, 4, 9 };

void maxv(vector<int>& v) {
	sort(v);
	cout << v[v.size() - 1] << "\n";
}

int main()
try
{
	maxv(myVec);

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