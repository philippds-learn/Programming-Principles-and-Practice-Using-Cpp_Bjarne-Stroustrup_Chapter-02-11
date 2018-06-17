//	Philipp Siedler
//	Bjarne Stroustrup's PPP
//	Chapter 11 Exercise 15

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

	int width = 20;
	int counter = 0;

	for (double d; ifs >> d;) {
		ofs << setw(width) << scientific << d;
		counter++;
		if (counter == 4) {
			ofs << endl;
			counter = 0;
		}
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

/*
<pre><strong>Output:</strong>
enter name for input file
p409_15_random_num.txt
enter name for output file
p409_15_random_num_out.txt
5.800000e+01        3.200000e+01        5.000000e+01        8.000000e+01
5.400000e+01        1.300000e+01        2.400000e+01        8.200000e+01
5.200000e+01        1.700000e+01        1.700000e+01        8.000000e+00
8.700000e+01        1.200000e+01        3.500000e+01        4.200000e+01
8.800000e+01        7.200000e+01        4.600000e+01        9.100000e+01
6.900000e+01        6.000000e+01        8.400000e+01        5.500000e+01
9.900000e+01        2.100000e+01        6.000000e+00        2.500000e+01
5.300000e+01        1.300000e+01        7.500000e+01        8.300000e+01
9.400000e+01        2.000000e+00        7.100000e+01        3.500000e+01
8.500000e+01        5.000000e+01        7.100000e+01        9.900000e+01
6.000000e+01        4.700000e+01        6.800000e+01        2.900000e+01
1.000000e+02        5.400000e+01        4.500000e+01        6.600000e+01
4.000000e+00        9.800000e+01        5.700000e+01        1.300000e+01
2.300000e+01        3.000000e+00        8.000000e+00        9.000000e+00
4.700000e+01        6.700000e+01        1.700000e+01        5.200000e+01
5.000000e+00        6.000000e+01        7.300000e+01        2.800000e+01
1.800000e+01        4.500000e+01        5.000000e+00        7.000000e+00
9.900000e+01        7.800000e+01        7.800000e+01        1.700000e+01
3.000000e+00        8.700000e+01        3.700000e+01        3.300000e+01
8.300000e+01        9.200000e+01        8.300000e+01        9.900000e+01
4.500000e+01        7.500000e+01        2.800000e+01        7.300000e+01
6.600000e+01        4.400000e+01        1.100000e+01        7.300000e+01
9.000000e+00        2.400000e+01        2.900000e+01        3.900000e+01
5.200000e+01        9.900000e+01        2.400000e+01        9.500000e+01
8.000000e+00        9.100000e+01        9.000000e+01        9.900000e+01
</pre>
*/