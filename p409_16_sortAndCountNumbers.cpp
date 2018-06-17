//	Philipp Siedler
//	Bjarne Stroustrup's PPP
//	Chapter 11 Exercise 16

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

	vector<double> nums;
	for (double d; ifs >> d;) {
		nums.push_back(d);
	}

	sort(nums);

	for (int i = 0; i < nums.size(); i++) {
		cout << i << " " << nums[i] << endl;
	}

	int count = 1;

	for (int i = 1; i < nums.size(); i++) {
		if (nums[i] == nums[i - 1]) {
			count++;
		}
		else {
			ofs << nums[i - 1];
			if (count > 1) {
				ofs << " " << count << endl;
				count = 1;
			}
			else {
				ofs << endl;
			}
		}
		if (i == nums.size() - 1 && nums[i] == nums[i - 1]) {
			if (count == 1) {
				count++;
			}
			ofs << nums[i];
			ofs << " " << count << endl;
			ofs << endl;
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

</pre>
*/