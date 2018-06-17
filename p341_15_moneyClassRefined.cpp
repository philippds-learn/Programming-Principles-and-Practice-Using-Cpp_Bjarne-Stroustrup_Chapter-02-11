//	Philipp Siedler
//	Bjarne Stroustrup's PPP
//	Chapter 9 Exercise 15

#include "std_lib_facilities.h"

enum currency {
	USD, EUR, GBP
};

ostream & operator<<(ostream & os, currency & c) {
	if (c == USD) {
		os << "USD";
		return os;
	}
	if (c == EUR) {
		os << "EUR";
		return os;
	}
	if (c == GBP) {
		os << "GBP";
		return os;
	}
}

class Money {
public:
	long int amount;
	currency cur;

	//constructors
	Money();
	Money(double);
	Money(currency, double);

	//non-modifying operations
	long int get_amount() { return amount; }
	double get_amount_decimal();
	void read_value(bool&, currency&, double&);
	void print() { cout << cur << get_amount_decimal() << endl; }

	//modifying operations
};

Money::Money() {
	amount = 0;
	cur = USD;
}

Money::Money(double a) {
	double temp_d0 = a;
	temp_d0 *= 100;
	int temp_i = (int)temp_d0;
	double difference = temp_d0 - temp_i;
	if (difference >= 0.5) {
		temp_i++;
	}
	amount = temp_i;
	cur = USD;
}

Money::Money(currency c, double a) {
	double temp_d0 = a;
	temp_d0 *= 100;
	int temp_i = (int)temp_d0;
	double difference = temp_d0 - temp_i;
	if (difference >= 0.5) {
		temp_i++;
	}
	amount = temp_i;
	cur = c;
}

double Money::get_amount_decimal() {
	return double(amount) / 100;
}

void read_value(currency & c, double& i) {
	string cur;
	char l;
	double amount;

	while (true) {
		cin >> l;
		if (isalpha(l)) {
			cur += l;
		}
		else {
			if (cur == "USD" || cur == "EUR" || cur == "GBP") {
				if (cur == "USD") {
					c = currency::USD;
				}
				else if (cur == "EUR") {
					c = currency::EUR;
				}
				else if (cur == "GBP") {
					c = currency::GBP;
				}
			}
			else {
				cout << "Invalid currency" << cur << endl;
				break;
			}

			cin.putback(l);
			cin >> amount;

			i = amount;
			break;
		}
	}
}

double EURtoUSD(double d) {
	return d * 1.12;
}

double GBPtoUSD(double d) {
	return d * 1.26;
}

double USDtoEUR(double d) {
	return d * 0.89;
}

double GBPtoEUR(double d) {
	return d * 1.13;
}

double USDtoGBP(double d) {
	return d * 0.78;
}

double EURtoGBP(double d) {
	return d * 0.88;
}

Money operator+(Money & m1, Money & m2) {
	
	switch (m1.cur) {
	case USD:{
		switch (m2.cur) {
		case USD: {return Money(USD, m1.get_amount_decimal() + m2.get_amount_decimal()); }
		case EUR: {return Money(USD, m1.get_amount_decimal() + EURtoUSD(m2.get_amount_decimal())); }
		case GBP: {return Money(USD, m1.get_amount_decimal() + GBPtoUSD(m2.get_amount_decimal())); }
		}
	}
	case EUR:{
		switch (m2.cur) {
		case USD: {return Money(m1.get_amount_decimal() + USDtoEUR(m2.get_amount_decimal())); }
		case EUR: {return Money(m1.get_amount_decimal() + m2.get_amount_decimal()); }
		case GBP: {return Money(m1.get_amount_decimal() + GBPtoEUR(m2.get_amount_decimal())); }
		}
	}
	case GBP:{
		switch (m2.cur) {
		case USD: {return Money(GBP, m1.get_amount_decimal() + USDtoGBP(m2.get_amount_decimal())); }
		case EUR: {return Money(GBP, m1.get_amount_decimal() + EURtoGBP(m2.get_amount_decimal())); }
		case GBP: {return Money(GBP, m1.get_amount_decimal() + m2.get_amount_decimal()); }
		}
	}
	}
	
}


void calculate() {

	double input1;
	currency cur1;
	double input2;
	currency cur2;

	cout << "Enter first set of money as float: " << endl;
	cout << "Supported currencies: EUR, GBP, USD," << endl;
	cout << "Format example: USD 12.235" << endl;
	read_value(cur1, input1);
	Money money1(cur1, input1);
	money1.print();

	cout << "Enter second set of money as float: " << endl;
	cout << "Supported currencies: EUR, GBP, USD," << endl;
	cout << "Format example: USD 12.235" << endl;

	read_value(cur2, input2);
	Money money2(cur2, input2);
	money2.print();

	Money money3 = money1 + money2;
	cout << "money1 + money2 = ";
	money3.print();
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