//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 3 Exercise 7

#include "std_lib_facilities.h"

int main()
{
	string word1 = " ", word2 = " ", word3 = " ";
	string smallest = " ", medium = " ", largest = " ";
	cout << "enter word 1, word 2, word 3 devided by space ";
	cin >> word1 >> word2 >> word3;

	cout << "you entered three words: " << "word1: " << word1 << ", word2: " << word2 << ", word3: " << word3 << "\n";

	if (word1 <= word2 && word1 <= word3)
	{
		smallest = word1;
		if (word2 <= word3)
		{
			medium = word2;
			largest = word3;
		}
		else
		{
			medium = word3;
			largest = word2;
		}
	}
		
	if(word2 <= word1 && word2 <= word3)
	{
		smallest = word2;
		if (word1 <= word3)
		{
			medium = word1;
			largest = word3;
		}
		else
		{
			medium = word3;
			largest = word1;
		}

	}

	if(word3 <= word2 && word3 <= word1)
	{
		smallest = word3;
		if (word1 <= word3)
		{
			medium = word1;
			largest = word2;
		}
		else
		{
			medium = word2;
			largest = word1;
		}
	}

	cout << smallest << ", " << medium << ", " << largest << "\n";

	keep_window_open();
}