//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 4 Exercise 18

#include "std_lib_facilities.h"

int main()
try
{
	float a, b, c, x1, x2, determinant, realNum, imagineNum;

	cout << "Enter a value for 'a', 'b' and 'c' to solve a quadratic equation.\n";

	if(cin >> a >> b >> c){}
	else {
		error("Bad input for a, b or c");
	}

	determinant = pow(b, 2) - 4 * a * c;

	if (determinant > 0) {
		x1 = (-b + sqrt(determinant)) / (2 * a);
		x2 = (-b - sqrt(determinant)) / (2 * a);

		cout << "Roots are real and different.\n";
		cout << "x1 = " << x1 << "\n";
		cout << "x2 = " << x2 << "\n";
	}

	else if (determinant == 0) {
		x1 = (-b + sqrt(determinant)) / (2 * a);

		cout << "Roots are real and same.\n";
		cout << "x1 = x2 " << x1 << "\n";
	}

	else {
		realNum = -b / (2 * a);
		imagineNum = sqrt(-determinant) / (2 * a);

		cout << "Roots are complex and different.\n";
		cout << "imagined part + real part: x1 = " << realNum + imagineNum << "\n";
		cout << "imagined part - real part: x2 = " << realNum - imagineNum << "\n";
	}

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