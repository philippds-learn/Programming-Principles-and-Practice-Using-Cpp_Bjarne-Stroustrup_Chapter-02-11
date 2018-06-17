//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 5 Exercise 12

#include "std_lib_facilities.h"

int main()
try
{
	int guess;
	int bulls = 0;
	int cows = 0;

	vector<int> guessVec;
	vector<int> numToBeguessed{ 1,2,3,4 };

	cout << "Enter 4 different digit number each ranging from 0 to 9 (for example 4567):\n";
	while (bulls != 4) {
		bulls = 0;
		cows = 0;
		if (cin >> guess) {
			if (guess / 1000 >= 1 && guess / 1000 < 10) {
			
				guessVec.push_back(guess / 1000 % 10);
				guessVec.push_back(guess / 100 % 10);
				guessVec.push_back(guess / 10 % 10);
				guessVec.push_back(guess / 1 % 10);
			
				for (int i = 0; i < guessVec.size()-1; i++) {
					if (guessVec[i] == guessVec[i + 1]){
						error("Enter 4 different numbers.");
					}
				}

				for (int i = 0; i < guessVec.size(); i++) {
					for (int j = 0; j < guessVec.size(); j++) {
						if (numToBeguessed[j] == guessVec[i] && i == j) {
							bulls++;
						}
						else if (numToBeguessed[j] == guessVec[i]) {
							cows++;
						}
					}
				}
			}
			else {
				error("Enter a 4 digit number.");
			}
		}
		else {
		error("Enter a number.");
		}

		cout << "Bulls: " << bulls << " Cows: " << cows << "\n";
		guessVec.clear();
	}

	cout << "You win!\n";

	keep_window_open(".");
}

catch (runtime_error e) {
	cout << e.what() << "\n";
	keep_window_open(".");
}
catch (...) {
	cout << "Extiting" << "\n";
	keep_window_open(".");
}