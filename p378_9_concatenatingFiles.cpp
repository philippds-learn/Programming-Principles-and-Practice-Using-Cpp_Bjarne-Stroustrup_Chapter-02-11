//	Philipp Siedler
//	Bjarne Stroustrup's PPP
//	Chapter 10 Exercise 9

#include "std_lib_facilities.h"

void read_file(string& _input, ofstream& _ost) {
	ifstream ist{ _input };
	string result;
	if (!ist) error("can't open input file ", _input);
	ist.exceptions(ist.exceptions() | ios_base::badbit);
	ist >> result;

	while (true) {
		_ost << result << endl;
		if (ist.eof()) {
			break;
		}
		else {
			ist >> result;
		}
	}
}

void write_file(string& _output, string& _input_1, string& _input_2) {
	ofstream ost{ _output };
	if (!ost) error("can't open output file", _output);

	read_file(_input_1, ost);
	read_file(_input_2, ost);
}

void calculate() {
	string input_1 = "input/ch10_9_input_1.txt";
	string input_2 = "input/ch10_9_input_2.txt";
	string output = "output/ch10_9_output_1+2.txt";
	
	cout << "Combining files " << input_1 << " & " << input_2 << "...";
	write_file(output, input_1, input_2);
	cout << " Done!" << endl;
	cout << output << " successfully written." << endl;
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