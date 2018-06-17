//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 3 Exercise 9

#include "std_lib_facilities.h"

int main()
{
	cout << "enter a spelled out integer to be converted to the number: ";
	int toBeSpelled = -1;
	string inputNumber;

	while (cin >> inputNumber)
	{
		if (inputNumber == "zero") toBeSpelled = 0;
		else if (inputNumber == "one") toBeSpelled = 1;
		else if (inputNumber == "two") toBeSpelled = 2;
		else if (inputNumber == "three") toBeSpelled = 3;
		else if (inputNumber == "four") toBeSpelled = 4;
		else if (inputNumber == "Quit" || inputNumber == "quit") return 0;
		if (toBeSpelled != -1)
			cout << "you entered number " << toBeSpelled << '\n';
		else
			cout << "I dont know that number\n";
		cout << "Please enter another number or \"Quit\"\n";
		toBeSpelled = -1;
	}
	return 0;

	keep_window_open();
}