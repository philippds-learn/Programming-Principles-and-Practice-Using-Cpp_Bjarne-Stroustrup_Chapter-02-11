//	Philipp Siedler
//	Bjarne Stroustrup's PPP
//	Chapter 11 Exercise 9 Read

#include "std_lib_facilities.h"

int main()
try
{
	//open an istream for binary input from a file:
	cout << "Please enter input file name\n";

	string in;
	string iname = "input/";
	cin >> in;
	iname += in;
	
	ifstream ifs{ iname, ios_base::binary }; //note: stream mode
	//binary tells the stream not to try anything clever with the bytes
	
	if (!ifs) error("can't open input file", iname);
	else {
		cout << "file opened" << endl;
	}

	//open an ostream for binary input from a file:
	cout << "Please enter output file name\n";

	string out;
	string oname = "output/";
	cin >> out;
	oname += out;

	ofstream ofs{ oname };
	
	vector<int> v;

	//read from binary file:
	for (int x; ifs.read(as_bytes(x), sizeof(int));) { //note: reading bytes
		v.push_back(x);
	}
		
	//cout binary file:
	for (int x : v) {
		cout << x << endl;
		ofs << x << endl;
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