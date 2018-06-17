//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 6 Exercise 4

#include "std_lib_facilities.h"

class nameValue {
public:
	nameValue(string n, int a) : name(n), age(a) { }
	string name;
	int age;
};

int main()
try
{
	vector<nameValue> nameAndAge;

	string nameTemp;
	int ageTemp;

	bool check = true;

	while (check == true) {
		cout << "Enter name and age pairs to be collected, or 'noname' and '0' to end the entry.\n";
		if (cin >> nameTemp >> ageTemp) {
			if (nameTemp == "noname" && ageTemp == 0) {
				check = false;
			}
			else {
				for (int i = 0; i < nameAndAge.size(); i++) {
					if (nameAndAge[i].name == nameTemp) {
						error("This name already exists ", nameTemp);
					}
				}
				nameAndAge.push_back(nameValue(nameTemp, ageTemp));
			}
		}
		else {
			error("Bad input");
		}
	}

	for (int i = 0; i < nameAndAge.size(); i++) {
		cout << "Name: " << nameAndAge[i].name << " Score: " << nameAndAge[i].age << "\n";
	}

	keep_window_open(".");
}

catch (runtime_error e) {
	cout << e.what() << "\n";
	keep_window_open(".");
}
catch (...) {
	cout << "Exiting \n";
	keep_window_open(".");
}