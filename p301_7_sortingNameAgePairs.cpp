//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 8 Exercise 7

#include "std_lib_facilities.h"

vector<string> names;
vector<int> ages;

class NameAge {
	vector<string> n;
	vector<int> a;
public:
	NameAge(vector<string>& _n, vector<int>& _a) :n(_n), a(_a) {};
	void readNames();
	void readAges();
	void print();
	void sortVectors();
};

void NameAge::readNames() {
	while (cin) {
		char letter;
		cin.get(letter);
		if (isalpha(letter)) {
			string name;
			name += letter;
			while (cin.get(letter) && isalpha(letter)) {
				name += letter;
			}
			n.push_back(name);
		}
		if (isspace(letter)) {
			if (letter == '\n') {
				break;
			}
		}
	}
}

void NameAge::readAges() {

	while (n.size() != a.size()) {
		char ageChar;
		int ageInt;
		cin.get(ageChar);
		if (isspace(ageChar)) {
			if (ageChar == '\n' && n.size() == a.size()) {
				break;
			}
		}
		cin.unget();
		cin >> ageInt;
		a.push_back(ageInt);
	}
}

void NameAge::print() {
	for (int i = 0; i < n.size(); i++) {
		cout << n[i] << " " << a[i] << "\n";
	}
}

void NameAge::sortVectors() {
	vector<string> tempNames = n;
	vector<int> tempAges = a;
	vector<int> index;

	sort(tempNames.begin(), tempNames.end());

	for (int i = 0; i < n.size(); i++) {
		for (int j = 0; j < n.size(); j++) {
			if (tempNames[i] == n[j]) {
				index.push_back(j);
			}
		}
	}

	for (int i = 0; i < n.size(); i++) {
		a[i] = tempAges[index[i]];
	}
	n = tempNames;
}

int main()
try
{
	NameAge na(names, ages);

	cout << "Enter name(s)\n";

	na.readNames();

	cout << "Promt ages in order of names:\n";

	na.readAges();

	na.sortVectors();

	na.print();

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