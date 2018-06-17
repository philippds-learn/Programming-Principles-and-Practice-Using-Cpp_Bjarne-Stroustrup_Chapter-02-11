//	Philipp Siedler
//	Bjarne Stroustrup's PPP
//	Chapter 10 Exercise 8

#include "std_lib_facilities.h"

string read_file(string& _input) {
	ifstream ist{ _input };
	string result;
	if (!ist) error("can't open input file ", _input);
	ist.exceptions(ist.exceptions() | ios_base::badbit);

	ist >> result;
	return result;
}

void write_file(string& _output, string& _input_1, string& _input_2) {
	ofstream ost{ _output };
	if (!ost) error("can't open output file", _output);

	ost << read_file(_input_1) + read_file(_input_2);
}

void calculate() {
	string input_1 = "ch10_8_input_1.txt";
	string input_2 = "ch10_8_input_2.txt";
	string output = "ch10_8_output_1+2.txt";

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