//	Philipp Siedler
//	Bjarne Stroustrup's PPP
//	Chapter 11 Exercise 9 Write

#include "std_lib_facilities.h"

int main()
try
{
	//open an istream for binary input from a file:
	cout << "Please enter input file name\n";
	string iname = "output/";
	string in;
	cin >> in;
	iname += in;	
	ifstream ifs{ iname }; //note: stream mode
											 //binary tells the stream not to try anything clever with the bytes

	if (!ifs) error("can't open input file", iname);

	//open an ostream for binary output to a file:
	cout << "Please enter output file name\n";
	string oname = "output/";
	string on;
	cin >> on;
	oname += on;
	ofstream ofs{ oname }; //note: stream mode
											 //binary tells the stream not to try anything clever with the bytes

	vector<int> v;
	for (int x; ifs >> x;) { //note: reading bytes
		v.push_back(x);
	}

	for (int x : v) { //char x : v
		ofs.write(as_bytes(x), sizeof(int)); //note: writing bytes
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