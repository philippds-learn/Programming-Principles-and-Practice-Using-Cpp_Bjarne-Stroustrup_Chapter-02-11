//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 5 Exercise 13

#include "std_lib_facilities.h"

int main()
try
{
	int seed;
	string checkSeed;

	int rndNum;
	int rndNumCount = 4;
	vector<int> rndNums;

	int guess;
	int bulls = 0;
	int cows = 0;
	vector<int> guessVec;

	string answer = "noAnswer";
	
	while (rndNums.size() < rndNumCount) {
		cout << "Enter seed\n";
		if (cin >> seed) {}
		else {
			cin.clear();
			cin >> checkSeed;
			error("Entered seed is not a number: ", checkSeed);
		}

		for (int i = 0; i < rndNumCount;) {
			if (i == 0) {
				rndNum = (rand() % 100) / 10;
				rndNums.push_back(rndNum);
				i++;
			}
			else {
				rndNum = (rand() % 100) / 10;
				if (rndNum != rndNums[i - 1]) {
					rndNums.push_back(rndNum);
					i++;
				}
			}
		}

		for (int i = 0; i < rndNums.size(); i++) {
			cout << "rnd num: " << rndNums[i] << "\n";
		}
	
		cout << "Enter 4 different digit number each ranging from 0 to 9 (for example 4567):\n";
		while (bulls != rndNumCount) {
			bulls = 0;
			cows = 0;
			if (cin >> guess) {
				if (guess / 1000 >= 1 && guess / 1000 < 10) {
	
					guessVec.push_back(guess / 1000 % 10);
					guessVec.push_back(guess / 100 % 10);
					guessVec.push_back(guess / 10 % 10);
					guessVec.push_back(guess / 1 % 10);

					for (int i = 0; i < guessVec.size() - 1; i++) {
						if (guessVec[i] == guessVec[i + 1]) {
							error("Enter 4 different numbers.");
						}
					}

					for (int i = 0; i < guessVec.size(); i++) {
						for (int j = 0; j < guessVec.size(); j++) {
							if (rndNums[j] == guessVec[i] && i == j) {
								bulls++;
							}
							else if (rndNums[j] == guessVec[i]) {
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

		cout << "Play again? Press y or n: \n";
		cin >> answer;

		if (answer == "y") {
			rndNums.clear();
			bulls = 0;
			//break;
		}
		else {
			break;
		}
	}

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
