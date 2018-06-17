//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 4 Exercise 21

#include "std_lib_facilities.h"

int main()
try
{
	vector<string> names;
	string nameTemp;
	
	vector<int> ages;
	int ageTemp;
	int ageInput;
	int ageCheck = 0;

	bool check = true;

	while (check == true) {
		cout << "Enter name and age pairs to be collected, or 'noname' and '0' to end the entry.\n";

		if (cin >> nameTemp >> ageTemp) {
			if (nameTemp == "noname" && ageTemp == 0) {
				check = false;
			}
			else {
				for (int i = 0; i < names.size(); i++) {
					if (names[i] == nameTemp) {
						error("This name already exists ", nameTemp);
					}
				}
				names.push_back(nameTemp);
				ages.push_back(ageTemp);
			}
		}
		else {
			error("Bad input");
		}
	}

	cout << "Enter a integer to look for\n";
	cin >> ageInput;

	for (int i = 0; i < ages.size(); i++) {
		if (ages[i] == ageInput) {
			cout << "You entered: " << ageInput << " . Corresponded name is " << names[i] << "\n";
			ageCheck++;
		}
	}

	if (ageCheck == 0) {
		cout << ageInput << " . Could not be found in the list of ages.\n";
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