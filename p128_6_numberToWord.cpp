//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 4 Exercise 6

#include "std_lib_facilities.h"

vector<string> numbers;

void initNumbers(){
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

void getNum() {
	int vali = numbers.size();
	string vals;
	
	// getInt
	if (cin >> vali) {
		if (vali <= 10) {
			cout << numbers[vali] << "\n";
			return;
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
			cout << i << "\n";
			s = vals;
		}
	}
	if(s == "noNumber") {
			error("Illegal entered number. You entered: \n", vals);
	}
}


int main()
try
{
	initNumbers();

	cout << "Please enter a number as integer between 0 and 9 or string as 'zero' to 'nine'\n";

	while (cin){
		getNum();
	}

	keep_window_open(".");
}

catch (runtime_error e) {
	cout << e.what() << '\n';
	keep_window_open(".");
}
catch (...) {
	cout << "exiting\n";
	keep_window_open(".");
}

