//	Philipp Siedler
//	Bjarne Stroustrup's PPP
//	Chapter 11 Exercise 2

#include "std_lib_facilities.h"

void lower_case(string& _text) {
	for (char& x : _text) {
		x = tolower(x);
	}
}

void input(vector<string>& _text, string _word) {
	string iname = "input/p408_2_blind_text.txt";
	ifstream ifs{ iname };

	string temp;

	while (getline(ifs, temp)) {
		lower_case(temp);
		_text.push_back(temp);
	}
}

vector<int> find_word(vector<string>& _text, string _word) {
	vector<int> index;
	int count = 0;

	for (string t : _text) {
		for (int i = 0; i < t.size(); i++) {
			string temp;
			if (t[i] == _word[0]) {
				for (int j = 0; j < _word.size(); j++){
					temp += t[i + j];
				}
			}
			if (temp.size() == _word.size()) {
				if (temp == _word) {
					cout << count << " " << t << endl;
					index.push_back(count);
					count++;
				}
			}
		}
	}

	return index;
}

void output(vector<string>& _text, vector<int> _index) {
	string oname = "output/p408_2_blind_text_out.txt";
	ofstream ofs{ oname };

	string temp;
	for (int i = 0; i < _index.size(); i++){
		temp += (to_string(_index[i]) + " " + _text[_index[i]] + "\n");
		
	}

	ofs << temp;
}

int main()
try
{
	vector<string> text;
	vector<int> index;
	string word = "lorem";

	input(text, word);
	index = find_word(text, word);
	output(text, index);

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