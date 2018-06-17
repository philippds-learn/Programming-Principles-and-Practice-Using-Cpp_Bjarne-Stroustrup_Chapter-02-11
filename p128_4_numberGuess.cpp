//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 4 Exercise 4

#include "std_lib_facilities.h"

int main() {

	int max = 100;
	int min = 0;
	int check = 0;
	string answer = " ";


	while (check == 0) {
		cout << "Is your number smaller, larger or equal to " << (max + min) / 2 <<"? Enter s for smaller, l for larger or e for equal.\n";
		cin >> answer;
		if (answer == "s") {
			max = (max + min) / 2;
		}
		else if (answer == "l") {
			min = (max + min) / 2;
		}
		else if (answer == "e") {
			cout << "Your number is: " << (max + min) / 2 << "\n";
			check = 1;
		}
	}
	keep_window_open();
}





