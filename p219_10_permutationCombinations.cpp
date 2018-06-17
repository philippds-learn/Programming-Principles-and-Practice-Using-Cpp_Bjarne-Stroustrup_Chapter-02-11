//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 6 Exercise 10

#include "std_lib_facilities.h"

int factorial(int _n) {
	int fact = 1;
	while (1 < _n){
		fact *= _n;
		--_n;
		if (fact < 1) {
			error("factorial overflow");
		}
	}
	return fact;
}

int permutations(int _a, int _b) {
	if (_a < _b || _a < 1 || _b < 1) {
		error("bad permutation sizes");
	}
	return factorial(_a) / factorial(_a - _b);
}

int combinations(int _a, int _b)
{
	return permutations(_a, _b) / factorial(_b);
}

int main()
try
{
	int a;
	int b;
	string aCheck;
	string bCheck;
	char answer;
	bool permCheck = false;
	bool combCheck = false;

	cout << "Enter two integer values for permutation and combination: \n";
	cout << "Enter value for a\n";

	if (cin >> a) {}
	else{
		cin.clear();
		cin >> aCheck;
		error("Wrong value for a: ", aCheck);
	}

	cout << "Enter value for b\n";
	if (cin >> b) {}
	else {
		cin.clear();
		cin >> aCheck;
		error("Wrong value for b: ", aCheck);
	}
	if (b > a) {
		error("Value b must be smaller than a, b: ", b);
	}

	cout << "a = " << a << "\n";
	cout << "b = " << b << "\n";

	cout << "Enter 'p' for permutations, 'c' for combinations or 'b' for both:\n";
	cin >> answer;
	if (answer == 'p') {
		permCheck = true;
	}
	else if (answer == 'c') {
		combCheck = true;
	}
	else if (answer == 'b') {
		permCheck = true;
		combCheck = true;
	}
	else {
		error("Bad input", answer);
	}

	if (permCheck) {
		cout << "Permutation: " << permutations(a, b) << "\n";
	}
	if(combCheck){
		cout << "Combination: " << combinations(a, b) << "\n";
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
