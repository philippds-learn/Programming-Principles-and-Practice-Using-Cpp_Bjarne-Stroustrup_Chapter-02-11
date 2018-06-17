//	Philipp Siedler
//	Bjarne Stroustrup's PPP
//	Chapter 11 Exercise 13

#include "std_lib_facilities.h"

int main()
try
{
	cout << "enter name for input file" << endl;
	string iname = "input/";
	string itemp;
	cin >> itemp;
	iname += itemp;
	ifstream ifs{ iname };
	if (!ifs) { cout << "could not open input file." << endl; }

	cout << "enter name for output file" << endl;
	string oname = "output/";
	string otemp;
	cin >> otemp;
	oname += otemp;
	ofstream ofs{ oname };
	if (!ofs) { cout << "could not open output file." << endl; }

	string word;
	vector<string> words;

	for (char ch; ifs.get(ch);) {
		if (isspace(ch)) {
			words.push_back(word);
			word = "";
			word += ch;
			words.push_back(word);
			word = "";
		}
		else {
			word += ch;
		}
	}
	words.push_back(word);

	for (int i = 1; i < words.size() + 1; i++) {
		ofs << words[words.size() - i];
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