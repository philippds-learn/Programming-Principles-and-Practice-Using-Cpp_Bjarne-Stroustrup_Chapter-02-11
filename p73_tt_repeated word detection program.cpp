//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 3 Try This Page 73

#include "std_lib_facilities.h"

int main()
{
	cout << "Enter a series of words, they can even repeat themselfs.\n";
	string previous = " ";
	string current;
	while (cin >> current){
		if (previous == current)
			cout << "repeated word: " << current << '\n';
		previous = current;
	}
}