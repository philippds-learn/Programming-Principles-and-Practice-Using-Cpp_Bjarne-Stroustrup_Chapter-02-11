//	Philipp Siedler
//	Bjarne Stroustrup's PPP
//	Chapter 11 Exercise 12

#include "std_lib_facilities.h"

void reverseWord(string& w) {
	string temp;
	for (int i = 1; i < w.size() + 1; i++) {
		temp += w[w.size() - i];
	}
	w = temp;
}

void readWriteFile() {
	string iname = "input/p409_12_blind_text.txt";
	ifstream ifs{ iname };
	string oname = "output/p409_12_blind_text_out.txt";
	ofstream ofs{ oname };

	while (true) {
		if (ifs.eof()) {
			break;
		}
		string temp;
		string tempReverse;
		char ch;
		if (getline(ifs,temp)) {
			cout << temp << endl;
			string word;
			for (int i = 0; i < temp.size(); i++) {
				if (isalpha(temp[i])) {
					word += temp[i];
				}
				else {
					if (word.size() != 0) {
						reverseWord(word);
						tempReverse += word;
						word = "";
					}
					tempReverse += temp[i];
				}
				if (i == temp.size() - 1) {
					tempReverse += '\n';
				}
			}
		}
		ofs << tempReverse;		
	}
}

int main()
try
{
	readWriteFile();
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