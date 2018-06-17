//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 4 Exercise 7

#include "std_lib_facilities.h"

vector<string> numbers;

void initNumbers() {
	numbers.push_back("zero");
	numbers.push_back("one");
	numbers.push_back("two");
	numbers.push_back("three");
	numbers.push_back("four");
	numbers.push_back("five");
	numbers.push_back("six");
	numbers.push_back("seven");
	numbers.push_back("eight");
	numbers.push_back("nine");
}

int getNum() {
	int vali = numbers.size();
	string vals;

	// getInt
	if (cin >> vali) {
		if (vali <= 10) {
			return vali;
		}
		else {
			error("Entered integer is too high. You entered: ", vali);
		}
	}

	cin.clear();
	// getString
	string s = "noNumber";
	cin >> vals;
	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i] == vals) {
			return i;
			s = vals;
		}
	}
	if (s == "noNumber") {
		error("Illegal entered number. You entered: ", vals);
	}
}

int main() 
try{

	initNumbers();
	int value1 = 0;
	int value2 = 0;
	char operat = ' ';

	while (cin) {


		cout << "Enter two intgeres followed by a operator seperated by spaces.\n";
		//cout << "Enter one integer as digit or written out: \n";
		value1 = getNum();

		//cout << "Enter another integer as digit or written out: \n";
		value2 = getNum();

		//cout << "Enter an ooperator: \n";
		cin >> operat;

		if (operat == '+') {
			cout << value1 << " " << operat << " " << value2 << " equals to: " << value1 + value2 << "\n";
		}
		if (operat == '-') {
			cout << value1 << " " << operat << " " << value2 << " equals to: " << value1 - value2 << "\n";
		}
		if (operat == '/') {
			cout << value1 << " " << operat << " " << value2 << " equals to: " << value1 / value2 << "\n";
		}
		if (operat == '*')
		{
			cout << value1 << " " << operat << " " << value2 << " equals to: " << value1 * value2 << "\n";
		}
	}

	keep_window_open(".");
}

catch (runtime_error e) {	// this code is to produce error messages; it will be described in Chapter 5
	cout << e.what() << '\n';
	keep_window_open(".");	// For some Windows(tm) setups
}
catch (...) {	// this code is to produce error messages; it will be described in Chapter 5
	cout << "exiting\n";
	keep_window_open(".");	// For some Windows(tm) setups
}