//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 4 Exercise 2

#include "std_lib_facilities.h"

int main() {
	vector<double> temps;
	double temp;
	
	cout << "Enter a double\n";

	//pushing new temperature values into temps vector
	while (cin >> temp)
	{
		temps.push_back(temp);
		cout << "type another double or press n to continue and calculate the median temperature.\n";
	}
	
	//displaying vector size
	cout << "size of vector: " << temps.size() << '\n';

	//sorting temps vector
	sort(temps); //sort(temps.begin(), temps.end());
	
	//calculate median
	double median;
	if (temps.size() % 2 == 0)
		median = (temps[temps.size() / 2 - 1] + temps[temps.size() / 2]) / 2;
	else
		median = temps[temps.size() / 2];
	cout << "Median temperature: " << median << endl;

	keep_window_open("-");
}