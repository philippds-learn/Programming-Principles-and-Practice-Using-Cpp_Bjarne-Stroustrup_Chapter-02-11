//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 8 Exercise 11

#include "std_lib_facilities.h"

vector<int> myVec{ 5,2,1,6,4 };

struct extremes
{
	vector<int> v;
	int min;
	int max;
	double mean;
	int median;
public:
	extremes(vector<int>& _v) :v(_v) {};
	void calc();
	void print();
};

void extremes::calc() {
	sort(v);
	//max
	max = v[0];
	//min
	min = v[v.size() - 1];
	//mean
	double additionIndex = 0;
	for (int x : v) {
		additionIndex += x;
	}
	mean = additionIndex / v.size();
	//median
	if (v.size() % 2 == 0)
	{
		median = (v[v.size() / 2 - 1] + v[v.size() / 2]) / 2;
	}
	else
	{
		median = v[v.size() / 2];
	}
}

void extremes::print() {
	cout << "min: " << min << "\n";
	cout << "max: " << max << "\n";
	cout << "mean: " << mean << "\n";
	cout << "median: " << median << "\n";
}

int main()
try
{
	extremes e(myVec);
	e.calc();
	e.print();
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

/*
min: 6
max: 1
mean: 3.6
median: 4
Please enter a character to exit
*/