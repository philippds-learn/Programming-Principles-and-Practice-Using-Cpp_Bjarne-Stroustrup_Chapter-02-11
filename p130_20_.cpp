//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 4 Exercise 20

#include "std_lib_facilities.h"

int main()
try
{
	string nameTemp;
	string nameInput;
	int nameCheck = 0;

	int ageTemp;

	vector<string> names;
	vector<int> ages;

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

	cout << "Enter a name to look for\n";
	cin >> nameInput;

	for (int i = 0; i < names.size(); i++) {
		if (names[i] == nameInput) {
			cout << "You entered: " << nameInput << " . Corresponded score is " << ages[i] << "\n";
			nameCheck++;
		}
	}

	if (nameCheck == 0) {
	cout << nameInput << " . Could not be found in the list of names.\n";
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