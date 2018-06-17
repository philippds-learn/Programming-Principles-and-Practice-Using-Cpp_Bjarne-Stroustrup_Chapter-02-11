//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 8 Exercise 13

#include "std_lib_facilities.h"

struct stringVec
{
	vector<string> vs;
	vector<int> letterCount;
	vector<int> letterCountsorted;
	string longest;
	string shortest;
	string first;
	string last;

public:
	stringVec(vector<string>& _vs) :vs(_vs) {};
	void stringToInt();
	void stringSort();
	void print();
};

void stringVec::stringToInt() {
	for (string x : vs) {
		letterCount.push_back(x.size());
	}
}

void stringVec::stringSort() {
	//longest & shortest
	letterCountsorted = letterCount;
	sort(letterCountsorted);
	int min = letterCountsorted[0];
	int max = letterCountsorted[letterCountsorted.size() - 1];
	int maxIndex;
	int minIndex;
	for (int i = 0; i < letterCountsorted.size(); i++) {
		if (max == letterCount[i]) {
			maxIndex = i;
		}
		if (min == letterCount[i]) {
			minIndex = i;
		}
	}
	longest = vs[maxIndex];
	shortest = vs[minIndex];
	//lexicographical first & last 
	sort(vs);
	first = vs[0];
	last = vs[vs.size() - 1];
}

void stringVec::print() {
	
	for (int x : letterCount) {
		cout << x << "\n";
	}
	cout << "longest: " << longest << "\n";
	cout << "shortest: " << shortest << "\n";
	cout << "first: " << first << "\n";
	cout << "last: " << last << "\n";
}

int main()
try
{
	vector<string> myVec{ "hello", "how", "are", "you", "my", "name", "is" };
	stringVec a(myVec);

	a.stringToInt();

	a.stringSort();

	a.print();

	keep_window_open();

}

catch (runtime_error e) {
	cout << e.what() << "\n";
	keep_window_open();
}
catch (...) {
	cout << "Exiting\n";
	keep_window_open();
}