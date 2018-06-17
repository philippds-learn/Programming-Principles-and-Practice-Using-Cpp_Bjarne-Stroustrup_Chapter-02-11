//	Philipp Siedler
//	Bjarne Stroustrup's PPP
//	Chapter 9 Exercise 14

#include "std_lib_facilities.h"

class Money {
private:
	long int amount;
public:
	//constructors
	Money(double);
	
	//non-modifying operations
	long int get_amount() { return amount; }
	double get_amount_decimal();
	void print() { cout << get_amount_decimal() << endl; }

	//modifying operations
};

Money::Money(double a) {
	double temp_d0 = a;
	temp_d0 *= 100;
	int temp_i = (int)temp_d0;
	double difference = temp_d0 - temp_i;

	if (difference >= 0.5) {
		temp_i++;
	}

	amount = temp_i;
}

double Money::get_amount_decimal() {
	return double(amount) / 100;
}

void read_value(string& c, double& i) {
	string check;
	double input;

	if (cin >> input) {
		i = input;
	}
	else {
		cin.clear();
		cin >> check;
		c = check;
		if (check != "x") {
			cout << "Invalid input: " << check << endl;
		}
	}
}

void calculate() {
	while (true) {
		string check;
		double input;
		cout << "Enter dollar amount as float: " << endl;
		read_value(check, input);
		if (check == "x") {
			break;
		}
		else {
			Money dollar(input);
			dollar.print();
		}
	}
}

int main()
try
{
	calculate();
	keep_window_open();
}

catch (runtime_error e) {
	cout << e.what() << endl;
	keep_window_open();
}
catch (...) {
	cout << "Exiting" << endl;
	keep_window_open();
}