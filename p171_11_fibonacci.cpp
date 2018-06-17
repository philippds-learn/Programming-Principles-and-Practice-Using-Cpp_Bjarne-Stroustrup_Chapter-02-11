//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 5 Exercise 11

#include "std_lib_facilities.h"

int main()
try
{
	vector<int> fibonacciNum{ 0,1 };
	bool fibBool = true;
	int counter = 0;

	while(fibBool){
		int nextFibNum = fibonacciNum[counter] + fibonacciNum[counter + 1];
		
		if (nextFibNum >= 0) {
			fibonacciNum.push_back(nextFibNum);
		}
		else {
			fibBool = false;
		}
		counter++;
	}

	for (int i = 0; i < fibonacciNum.size(); i++) {
		cout << fibonacciNum[i] << "\n";
	}

	cout << fibonacciNum.size() << " fibonacci integers fit into a int vector\n";
	cout << "The largest number in the int vector is: " << fibonacciNum[fibonacciNum.size() - 1] << "\n";

	keep_window_open(".");
}

catch (runtime_error e) {
	cout << e.what() << "\n";
	keep_window_open(".");
}
catch (...) {
	cout << "Extiting" << "\n";
	keep_window_open(".");
}