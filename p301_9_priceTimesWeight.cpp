//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 8 Exercise 9

#include "std_lib_facilities.h"

vector<double> price;
vector<double> weight;

class indexCalc {
	vector<double> p;
	vector<double> w;

public:
	indexCalc(vector<double> _p, vector<double> _w) :p(_p), w(_w) { };
	void readPrice();
	void readWeight();
	void calculate();
};

void indexCalc::readPrice() {
	while (cin) {
		char priceChar;
		double priceDouble;
		cin.get(priceChar);
		if (isspace(priceChar)) {
			if (priceChar == '\n') {
				break;
			}
		}
		cin.unget();
		cin >> priceDouble;
		p.push_back(priceDouble);
	}
}

void indexCalc::readWeight() {
	while (p.size() != w.size()) {
		char weightChar;
		double weightDouble;
		cin.get(weightChar);
		if (isspace(weightChar)) {
			if (weightChar == '\n' && p.size() == w.size()) {
				break;
			}
		}
		cin.unget();
		cin >> weightDouble;
		w.push_back(weightDouble);
	}
}

void indexCalc::calculate() {
	double index = 0;
	for (int i = 0; i < p.size(); i++) {
		index += p[i] * w[i];
	}
	cout << index << "\n";
}

int main()
try
{
	indexCalc ic(price, weight);

	cout << "Enter prices\n";
	
	ic.readPrice();

	cout << "Enter weights\n";

	ic.readWeight();
	ic.calculate();

	keep_window_open();
}

catch (runtime_error e) {
	cout << e.what() << "\n";
	keep_window_open();
}

catch (...) {
	cout << "Exiting\n";
	keep_window_open();
}

/*
Enter prices
23 24 25 53 32
Enter weights
3 4 5 3 4
577
Please enter a character to exit
*/