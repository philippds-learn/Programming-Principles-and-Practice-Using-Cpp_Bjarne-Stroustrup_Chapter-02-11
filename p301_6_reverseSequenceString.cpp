//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 8 Exercise 6

#include "std_lib_facilities.h"

vector<string> myVec{ "a","b","c","d","e","f","g","h","i","j" };
vector<string> myVecRev;

class Rev {
public:
	vector<string> v;
	vector<string> vr;

	Rev(vector<string>& _v, vector<string>& _vr) :v(_v), vr(_vr) {};
	void reverse();
	void reverseSame();
	void printV(string);
	void printVR(string);
};

void Rev::reverse() {
	for (int i = 0; i < v.size(); i++) {
		vr.push_back(v[(v.size() - 1) - i]);
	}
}

void Rev::reverseSame() {
	for (int i = 0; i < v.size() / 2; i++) {
		string temp;
		temp = v[i];
		v[i] = v[(v.size() - 1) - i];
		v[(v.size() - 1) - i] = temp;
	}
}

void Rev::printV(string label) {
	for (string x : v) {
		cout << label << " " << x << "\n";
	}
}

void Rev::printVR(string label) {
	for (string x : vr) {
		cout << label << " " << x << "\n";
	}
}

int main()
try
{
	string label = "l";

	Rev rev(myVec, myVecRev);

	cout << "First version:\n";

	rev.reverse();
	rev.printV(label);
	rev.printVR(label);

	cout << "Second version:\n";

	rev.reverseSame();
	rev.printV(label);

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