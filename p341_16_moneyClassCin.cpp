//	Philipp Siedler
//	Bjarne Stroustrup's PPP
//	Chapter 9 Exercise 16

#include "std_lib_facilities.h"

enum currency {
	USD, EUR, GBP
};

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
	case USD: {
		switch (m2.cur) {
		case USD: {return Money(USD, m1.get_amount_decimal() + m2.get_amount_decimal()); }
		case EUR: {return Money(USD, m1.get_amount_decimal() + EURtoUSD(m2.get_amount_decimal())); }
		case GBP: {return Money(USD, m1.get_amount_decimal() + GBPtoUSD(m2.get_amount_decimal())); }
		}
	}
	case EUR: {
		switch (m2.cur) {
		case USD: {return Money(m1.get_amount_decimal() + USDtoEUR(m2.get_amount_decimal())); }
		case EUR: {return Money(m1.get_amount_decimal() + m2.get_amount_decimal()); }
		case GBP: {return Money(m1.get_amount_decimal() + GBPtoEUR(m2.get_amount_decimal())); }
		}
	}
	case GBP: {
		switch (m2.cur) {
		case USD: {return Money(GBP, m1.get_amount_decimal() + USDtoGBP(m2.get_amount_decimal())); }
		case EUR: {return Money(GBP, m1.get_amount_decimal() + EURtoGBP(m2.get_amount_decimal())); }
		case GBP: {return Money(GBP, m1.get_amount_decimal() + m2.get_amount_decimal()); }
		}
	}
	}

}

istream & operator>>(istream & is, Money & m) {
	string cur;
	char l;
	double amount;

	while (true) {
		is >> l;
		if (isalpha(l)) {
			cur += l;
		}
		else {
			if (cur == "USD" || cur == "EUR" || cur == "GBP") {
				if (cur == "USD") {
					m.cur = currency::USD;
				}
				else if (cur == "EUR") {
					m.cur = currency::EUR;
				}
				else if (cur == "GBP") {
					m.cur = currency::GBP;
				}
			}
			else {
				cout << "Invalid currency" << cur << endl;
				break;
			}

			is.putback(l);
			is >> amount;

			m = Money(m.cur, amount);
			break;
		}
	}

	return is;
}


ostream & operator<<(ostream & os, Money & m) {
	switch (m.cur) {
	case(USD):
	{
		os << "USD " << m.get_amount_decimal();
		return os;
	}
	case(EUR):
	{
		os << "EUR " << m.get_amount_decimal();
		return os;
	}
	case(GBP):
	{
		os << "GBP " << m.get_amount_decimal();
		return os;
	}
	}
}


void calculate() {

	cout << "Enter first set of money as float: " << endl;
	cout << "Supported currencies: EUR, GBP, USD," << endl;
	cout << "Format example: USD 12.235" << endl;
	Money money1;
	cin >> money1;

	cout << "Enter second set of money as float: " << endl;
	cout << "Supported currencies: EUR, GBP, USD," << endl;
	cout << "Format example: USD 12.235" << endl;
	Money money2;
	cin >> money2;
	
	Money money3 = money1 + money2;
	cout << money1 << " + " << money2 << " = ";
	cout << money3 << endl;;
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