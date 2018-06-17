//	Philipp Siedler
//	Bjarne Stroustrup's PPP
//	Chapter 11 Exercise 9 IO

#include "std_lib_facilities.h"

int main()
try
{
	//open an istream for binary input from a file:
	cout << "Please enter input file name\n";
	string iname;
	cin >> iname;
	ifstream ifs{ iname.c_str(), ios_base::binary }; //note: stream mode
											 //binary tells the stream not to try anything clever with the bytes

	if (!ifs) error("can't open input file", iname);

	//open an ostream for binary output to a file:
	cout << "Please enter output file name\n";
	string oname;
	cin >> oname;
	ofstream ofs{ oname }; //note: stream mode // oname.c_str(), ios_base::binary
											 //binary tells the stream not to try anything clever with the bytes

	if (!ofs) error("can't open output file", oname);
	vector<int> v;

	//read from binary file:
	for (int x; ifs.read(as_bytes(x), sizeof(int));) { //note: reading bytes
		v.push_back(x);
		//cout << x << endl;
	}

	//...do something...

	//write to binary file:
	for (int x : v) { //char x : v
		ofs.write(as_bytes(x), sizeof(int)); //note: writing bytes
	}

	//return 0;
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