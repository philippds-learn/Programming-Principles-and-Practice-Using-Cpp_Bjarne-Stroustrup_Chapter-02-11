//	Philipp Siedler
//	Bjarne Stroustrup's PPP
//	Chapter 11 Exercise 7

#include "std_lib_facilities.h"

void replace_apostrophes(string& _w) {
	if (_w == "can't" || _w == "can't ") {
		_w = "cannot ";
	}
	if (_w == "won't" || _w == "won't ") {
		_w = "will not ";
	}
	//in case word with apostrophe is in the end of the sentence
	if (_w[_w.size() - 1] == ' ') {
		if (_w[_w.size() - 2] == 't' &&
			_w[_w.size() - 3] == '\'' &&
			_w[_w.size() - 4] == 'n') {
			string temp = "";
			for (int i = 0; i < _w.size() - 4; i++) {
				temp += _w[i];
			}
			_w = temp + " not ";
		}
	}
	//in case word is in the beginning or in the middle of the sentence
	else {
		if (_w[_w.size() - 1] == 't' &&
			_w[_w.size() - 2] == '\'' &&
			_w[_w.size() - 3] == 'n') {
			string temp = "";
			for (int i = 0; i < _w.size() - 3; i++) {
				temp += _w[i];
			}
			_w = temp + " not ";
		}
	}
}

void calculate() {
	while (true) {
		//init
		cout << "enter a sentence" << endl;
		char quit;
		if (cin >> quit && quit == 'x') {
			break;
		}
		cin.putback(quit);

		//get chars and print them
		char let;
		vector<char> c_sentence;
		vector<string> s_words;
		while (cin.get(let)) {
			if (let == '\n') {
				break;
			}
			else {
				c_sentence.push_back(let);
			}
		}

		//you entered
		cout << "you entered: ";
		for (char l : c_sentence) {
			cout << l;
		}
		cout << "\n";

		//transform char vector into strings
		string temp;
		for (int i = 0; i < c_sentence.size(); i++) {
			if (!isspace(c_sentence[i])) {
				temp += tolower(c_sentence[i]);
			}
			else {
				if (i != c_sentence.size() - 1) {
					temp += tolower(c_sentence[i]);
				}
				replace_apostrophes(temp);
				s_words.push_back(temp);
				temp = "";
			}
			if (i == c_sentence.size() - 1) {
				replace_apostrophes(temp);
				s_words.push_back(temp);
				temp = "";
			}
		}

		//output new sentence
		for (string w : s_words) {
			cout << w;
		}
		cout << "\n";
	}
}

int main()
try
{
	calculate();
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