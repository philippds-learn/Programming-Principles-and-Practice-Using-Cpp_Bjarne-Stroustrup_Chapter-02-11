//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 8 Exercise 5

#include "std_lib_facilities.h"

vector<int> myVec{ 0,1,2,3,4,5,6,7,8,9 };
vector<int> myVecRev;

class Rev {


public:
	vector<int> v;
	vector<int> vr;

	Rev(vector<int>& _v, vector<int>& _vr) :v(_v), vr(_vr) {};
	void reverse();
	void reverseSame();
	void printV(string&);
	void printVR(string&);
};

void Rev::reverse() {
	for (int i = 0; i < v.size(); i++) {
		vr.push_back(v[(v.size() - 1) - i]);
	}
}

void Rev::reverseSame() {
	for (int i = 0; i < v.size() / 2; i++) {
		int temp;
		temp = v[i];
		v[i] = v[(v.size() - 1) - i];
		v[(v.size() - 1) - i] = temp;
	}
}

void Rev::printV(string& _label) {
	for (int x : v) {
		cout << _label << " " << x << "\n";
	}
}

void Rev::printVR(string& _label) {
	for (int x : vr) {
		cout << _label << " " << x << "\n";
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