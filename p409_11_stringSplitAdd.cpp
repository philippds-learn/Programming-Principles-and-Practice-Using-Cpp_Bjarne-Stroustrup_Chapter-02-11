//	Philipp Siedler
//	Bjarne Stroustrup's PPP
//	Chapter 11 Exercise 11

#include "std_lib_facilities.h"

vector<string> split(const string& s, const string& w) {
	vector<string> tempVec;
	string temp;	
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == w[0] && w.size() > 1) {
			int count = 1;
			for (int j = 1; j < w.size(); j++) {
				if (s[i + j] == w[j]) {
					count++;
				}
			}
			if (count == w.size()) {
				tempVec.push_back(temp);
				temp = "";
				i += count - 1;
			}
			else if(!isspace(s[i])){
				temp += s[i];
			}
		}
		else if(s[i] == w[0] && w.size() == 1){
			tempVec.push_back(temp);
			temp = "";
		}
		else if (isspace(s[i]) && temp != "") {
			tempVec.push_back(temp);
			temp = "";
		}
		else if(!isspace(s[i])) {
			
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
	string temp = "Hello World, how arowe you today?";
	string add = "o";
	myVec = split(temp, add);

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