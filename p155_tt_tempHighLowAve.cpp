//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 5 Try This page 155

#include "std_lib_facilities.h"

/*
First set of doubles to be tested
-16.5, -23.2, -24.0, -25.7, -26.1, -18.6, -9.7, -2.4,
7.5, 12.6, 23.8, 25.3, 28.0, 34.8, 36.7, 41.5,
40.3, 42.6, 39.4, 35.4, 12.6, 6.5, -3.7, -14.3
*/
/*
Second set of doubles to be tested
76.5, 73.5, 71.0, 73.6, 70.1, 73.5, 77.6, 85.3,
88.5, 91.7, 95.9, 99.2, 98.2, 100.6, 106.3, 112.4,
110.2, 103.6, 94.9, 91.7, 88.4, 85.2, 85.4, 87.7
*/

int main(){

	vector<double> temps{ 76.5, 73.5, 71.0, 73.6, 70.1, 73.5, 77.6, 85.3,
		88.5, 91.7, 95.9, 99.2, 98.2, 100.6, 106.3, 112.4,
		110.2, 103.6, 94.9, 91.7, 88.4, 85.2, 85.4, 87.7 };

	double highTemp = 0;
	double lowTemp = 0;
	double sum = 0;

	for (double x : temps) {
		if (x > highTemp) {
			highTemp = x;
		}
		if (x < lowTemp) {
			lowTemp = x;
		}
		sum += x;
	}

	cout << "High temperature: " << highTemp << '\n';
	cout << "Low temperature: " << lowTemp << '\n';
	cout << "Average temperature: " << sum/temps.size() << '\n';

	keep_window_open(".");
}