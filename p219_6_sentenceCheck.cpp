//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 6 Exercise 6

#include "std_lib_facilities.h"

//word vector setup
vector<string> nouns;
vector<string> verbs;
vector<string> conjunctions;

//initialize word vectors
void init(){
	nouns.push_back("birds");
	nouns.push_back("fish");
	nouns.push_back("C++");

	verbs.push_back("rules");
	verbs.push_back("fly");
	verbs.push_back("swim");

	conjunctions.push_back("and");
	conjunctions.push_back("or");
	conjunctions.push_back("but");
}

bool isNounString(string w) {
	for (int i = 0; i < nouns.size(); i++) {
		if (w == nouns[i]) {
			return true;
		}
	}
	return false;
}

bool isVerbString(string w) {
	for (int i = 0; i < verbs.size(); i++) {
		if (w == verbs[i]) {
			return true;
		}
	}
	return false;
}

bool isConjunctionString(string w) {
	for (int i = 0; i < conjunctions.size(); i++) {
		if (w == conjunctions[i]) {
			return true;
		}
	}
	return false;
}

bool sentences() {
	string w;
	cin >> w;
	if (!isNounString(w)) {
		return false;
	}

	string w1;
	cin >> w1;
	if (!isVerbString(w1)) {
		if (w1[w1.size() - 1] == '.') {
			return true;
		}
		else {
			return false;
		}
	}

	string w2;
	cin >> w2;
	if (!isConjunctionString(w2)) {
		return false;
	}
	return sentences();
}

int main()
try
{
	init();
	cout << "Enter sentece to be checked or x to exit:\n";

	while (true) {
		char exit;
		if (cin >> exit && exit == 'x') {
			break;
		}
		else {
			cin.putback(exit);
			bool check = sentences();
			if (check) {
				cout << "OK!\n";
				cout << "x for exit or continue:" << endl;
			}
			else {
				cout << "Not OK!\n";
				cout << "Try again:\n";
			}
		}

	}


	/*
	while (cin) {


	}
	*/

	keep_window_open(".");
}

catch (runtime_error e) {
	cout << e.what() << "\n";
	keep_window_open(".");
}
catch (...) {
	cout << "Exiting!\n";
	keep_window_open(".");
}