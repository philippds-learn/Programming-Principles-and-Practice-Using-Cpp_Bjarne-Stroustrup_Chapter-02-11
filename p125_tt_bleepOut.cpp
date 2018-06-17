//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 4 Try This page 125

#include "std_lib_facilities.h"

int main()
{
	string dislikedWords = "shit";
	cout << "Please write a couple of words: ";

	for (string words; cin >> words;)
	{
		if (words == dislikedWords) cout << "bleep\n";
		else cout << words << " ";
	}
	keep_window_open();
}