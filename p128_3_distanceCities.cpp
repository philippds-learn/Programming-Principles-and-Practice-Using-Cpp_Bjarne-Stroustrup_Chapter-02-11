//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 4 Exercise 3

#include "std_lib_facilities.h"

int main() {
	vector<double> distances;
	double distance;

	cout << "Enter a double\n";

	//pushing new temperature values into temps vector
	while (cin >> distance)
	{
		distances.push_back(distance);
		cout << "Enter another double or press n to continue and calculate the sum of distances.\n";
	}

	//calculate sum and display
	double sum = 0.0;
	for (double x : distances)
	{
		sum += x;
	}
	cout << "sum of distances is: " << sum << '\n';

	//calculate smallest and largest
	sort(distances);
	cout << "the smallest distance is: " << distances[0] << '\n';
	cout << "and the largest distance is: " << distances[distances.size() - 1] << '\n';

	//calculate mean distance
	cout << "the mean distance is: " << sum / distances.size() << '\n';

	keep_window_open("-");
}