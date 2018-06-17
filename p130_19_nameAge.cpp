//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 4 Exercise 19

#include "std_lib_facilities.h"

int main()
try
{
	string nameTemp;
	int ageTemp;
	
	vector<string> names;
	vector<int> ages;
	
	bool check = true;

	while (check == true) {
		cout << "Enter name and age pairs to be collected, or 'noname' and '0' to end the entry.\n";

		if(cin >> nameTemp >> ageTemp){
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
	for (int i = 0; i < names.size(); i++) {
		cout << "Name: " << names[i] << " Score: " << ages[i] << "\n";
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