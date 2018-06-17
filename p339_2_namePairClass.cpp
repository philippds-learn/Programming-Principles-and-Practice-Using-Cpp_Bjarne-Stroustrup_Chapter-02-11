//	Philipp Siedler
//	Bjarne Stroustrup's PPP
//	Chapter 9 Exercise 2

#include "std_lib_facilities.h"

class Name_pairs {
private:
	vector<string> names;
	vector<int> ages;
public:
	void read_name();
	void read_age();
	void sort_names_ages();
	void print();
};

void Name_pairs::read_name() {
	string nameTemp;
	string nameChecked;

	while (true) {
		cout << "Enter name: " << endl;
		cin >> nameTemp;

		if (nameTemp == "print") {
			cin.clear();
			break;
		}

		for (int i = 0; i < nameTemp.size(); i++) {
			if (isalpha(nameTemp[i])) {
				nameChecked += nameTemp[i];
			}
			else {
				cout << "no valid name was entered: " << nameTemp << endl;
				nameChecked = "reset";
			}
		}

		if (nameChecked == "reset") {
			cin.clear();
		}
		else {
			names.push_back(nameTemp);
			read_age();
		}
	}
};

void Name_pairs::read_age() {
	int ageTemp;
	string wrongEntry;

	while (cin) {
		cout << "Enter corresponding age: " << endl;
		if (cin >> ageTemp) {
			ages.push_back(ageTemp);
			break;
		}
		else {
			cin.clear();
			cin >> wrongEntry;
			cout << "no valid age entered: " << wrongEntry << endl;
		}
	}
};

void Name_pairs::print() {
	for (int i = 0; i < names.size(); i++) {
		cout << names[i] << " " << ages[i] << endl;
	}
};

void Name_pairs::sort_names_ages() {
	vector<string> sorted_names = names;
	vector<int> sorted_ages = ages;
	vector<int> index;
	sort(sorted_names);

	for (int i = 0; i < sorted_names.size(); i++) {
		for (int j = 0; j < sorted_names.size(); j++) {
			if (names[i] == sorted_names[j]) {
				index.push_back(j);
			}
		}
	}

	names = sorted_names;

	for (int i = 0; i < sorted_names.size(); i++) {
		ages[i] = sorted_ages[index[i]];
	}

};

void calculate() {
	cout << "Enter name and age pairs as prompted.\n"
			"Enter 'print' instead of a name to print your name age pairs:\n\n";
	Name_pairs np;
	np.read_name();
	np.sort_names_ages();
	np.print();
};

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
catch(...){
	cout << "Exiting\n";
	keep_window_open();
}
