//	Philipp Siedler
//	Bjarne Stroustrup's PPP
//	Chapter 11 Exercise 8

#include "std_lib_facilities.h"

void replace_apostrophes(string& _w, vector<string>& _s_words) {
	if (_w == "can't") {
		_w = "cannot";
	}
	if (_w == "won't") {
		_w = "will";
		_s_words.push_back("not");
	}
	if (_w[_w.size() - 1] == 't' &&
		_w[_w.size() - 2] == '\'' &&
		_w[_w.size() - 3] == 'n') {
		string temp = "";
		for (int i = 0; i < _w.size() - 3; i++) {
			temp += _w[i];
		}
		_w = temp;
		_s_words.push_back("not");
	}
}

void process(ifstream& _ist, ofstream& _ost) {
	while (true) {
		//get chars
		char letter;
		vector<char> c_sentence;
		vector<string> s_words;
		if (_ist.eof()) {
			break;
		}
		while (_ist.get(letter)) {
			c_sentence.push_back(letter);
		}

		//transform char vector into strings
		string temp;
		for (int i = 0; i < c_sentence.size(); i++) {
			if(!isspace(c_sentence[i]) && (!ispunct(c_sentence[i]) || c_sentence[i] == '\'' || c_sentence[i] == '-')){
				temp += tolower(c_sentence[i]);
			}
			else if (isspace(c_sentence[i])) {
				replace_apostrophes(temp, s_words);
				s_words.push_back(temp);
				temp = "";
			}

			if (i == c_sentence.size() - 1) {
				replace_apostrophes(temp, s_words);
				s_words.push_back(temp);
				temp = "";
			}
		}

		//sort and output new sentence without duplicate words
		sort(s_words);
		for (int i = 0; i < s_words.size(); i++) {
			if (i == 0) {
				//cout << s_words[i] << endl;
				_ost << s_words[i] << endl;
			}
			if (i > 0 && s_words[i] != s_words[i - 1]) {
				//cout << s_words[i] << endl;
				_ost << s_words[i] << endl;
			}
		}
	}
}

int main()
try
{
	string iname = "input/p409_8_blind_text.txt";
	ifstream ist{ iname };

	string oname = "output/p409_8_blind_text_output.txt";
	ofstream ost{ oname };

	process(ist, ost);
	cout << "Done!" << endl;
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