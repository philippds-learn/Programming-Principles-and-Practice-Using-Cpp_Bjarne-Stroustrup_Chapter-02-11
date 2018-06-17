//	Philipp Siedler
//	Bjarne Stroustrup's PPP
//	Chapter 11 Exercise 10

#include "std_lib_facilities.h"

vector<string> split(const string& s) {
	vector<string> tempVec;
	string temp;

	for (int i = 0; i < s.size(); i++) {
		if (isspace(s[i])) {
			tempVec.push_back(temp);
			temp = "";
		}
		else {
			temp += s[i];
		}
		if (i == s.size() - 1) {
			tempVec.push_back(temp);
		}
	}
	return tempVec;
}

int main()
try
{
	vector<string> myVec;
	string temp = "Hello World, how are you today?";
	myVec = split(temp);	

	for (int i = 0; i < myVec.size(); i++) {
		cout << myVec[i] << endl;
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