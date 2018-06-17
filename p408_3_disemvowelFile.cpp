//	Philipp Siedler
//	Bjarne Stroustrup's PPP
//	Chapter 11 Exercise 3

#include "std_lib_facilities.h"

class disemvowel {
public:
	void input_text();
	void disemvowel_text();
	void print_text();
	void output_text();

private:
	string text;
	string text_dis;
	vector<char> mutation{ 'a','e','i','o','u' };
};

void disemvowel::input_text() {
	string iname = "input/p408_3_blind_text.txt";
	ifstream ist{ iname };
	
	string text_temp;
	while (true) {
		string temp;
		getline(ist, temp);
		if (!ist.eof()) {
			text_temp += (temp + "\n");
		}
		else {
			text_temp += temp;
			break;
		}
	}

	text = text_temp;
}

void disemvowel::disemvowel_text() {
	for (int i = 0; i < text.size(); i++) {
		bool check = true;
		for (int j = 0; j < mutation.size(); j++) {
			if (text[i] == mutation[j]) {
				check = false;
			}
		}
		if (check) {
			text_dis += text[i];
		}
	}
}

void disemvowel::print_text() {
	cout << text_dis << endl;
}

void disemvowel::output_text() {
	string oname = "output/p408_3_blind_text_output.txt";
	ofstream ost{ oname };
	ost << text_dis;
}

int main()
try
{
	disemvowel d;
	d.input_text();
	d.disemvowel_text();
	d.print_text();
	d.output_text();

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