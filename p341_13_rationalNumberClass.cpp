//	Philipp Siedler
//	Bjarne Stroustrup's PPP
//	Chapter 9 Exercise 13

#include "std_lib_facilities.h"

//find greatest common denominator
int find_gcd(int a, int b)
{
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
		cout << "a = " << a << endl;
		cout << "b = " << b << endl;
	}
	cout << "final a = " << a << endl;
	return a;
}

class Rational {
private:
	int numerator;
	int denominator;
	double solution;

public:
	Rational();
	Rational(int, int);

	int get_numerator() { return numerator; }
	int get_denominator()  { return denominator; }
	double get_solution() { return solution; }

	void print_solution() { cout << solution << endl; }

	void normalise();
	void convert_to_double();
	
	void operator=(Rational r1);
};

Rational::Rational() {
	numerator = 1;
	denominator = 1;
}

Rational::Rational(int a, int b) {
	numerator = a;
	denominator = b;
}

void Rational::normalise() {
	if (denominator == 0) error("denominator is zero");
	if (denominator < 0) { denominator = -denominator; numerator = -numerator; }
	int n = find_gcd(numerator, denominator);
	if (n > 1) { numerator /= n; denominator /= n; }
}

void Rational::convert_to_double() {
	solution = double(numerator) / double(denominator);
}

void Rational::operator=(Rational r1) {
	numerator = r1.get_numerator();
	denominator = r1.get_denominator();
}

Rational operator+(Rational r1, Rational r2) {
	int a = r1.get_numerator() + r2.get_numerator();
	int b = r1.get_denominator() + r2.get_denominator();
	Rational r(a,b);
	return r;
}

Rational operator-(Rational r1, Rational r2) {
	int a = r1.get_numerator() - r2.get_numerator();
	int b = r1.get_denominator() - r2.get_denominator();
	Rational r(a, b);
	return r;
}

Rational operator*(Rational r1, Rational r2) {
	int a = r1.get_numerator() * r2.get_numerator();
	int b = r1.get_denominator() * r2.get_denominator();
	Rational r(a, b);
	return r;
}

Rational operator/(Rational r1, Rational r2) {
	int a = r1.get_numerator() / r2.get_numerator();
	int b = r1.get_denominator() / r2.get_denominator();
	Rational r(a, b);
	return r;
}

bool operator==(Rational r1, Rational r2) {
	bool a = r1.get_numerator() == r2.get_numerator();
	bool b = r1.get_denominator() == r2.get_denominator();
	if (a && b) {
		return true;
	}
	else {
		return false;
	}
}

bool operator!=(Rational r1, Rational r2) {
	bool a = r1.get_numerator() != r2.get_numerator();
	bool b = r1.get_denominator() != r2.get_denominator();
	if (a && b) {
		return true;
	}
	else {
		return false;
	}
}

int main()
try
{
	Rational myRational(30, 23);
	Rational myRational1(21,4);

	myRational = myRational + myRational1;
	myRational.convert_to_double();
	myRational.print_solution();

	myRational = myRational - myRational1;
	myRational.convert_to_double();
	myRational.print_solution();

	myRational = myRational * myRational1;
	myRational.convert_to_double();
	myRational.print_solution();

	myRational = myRational / myRational1;
	myRational.convert_to_double();
	myRational.print_solution();

	myRational = myRational1;
	myRational.convert_to_double();
	myRational.print_solution();


	if (myRational1 == myRational) {
		cout << "rational numbers are equal" << endl;
	}

	if (myRational1 != myRational) {
		cout << "rational numbers are not equal" << endl;
	}

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