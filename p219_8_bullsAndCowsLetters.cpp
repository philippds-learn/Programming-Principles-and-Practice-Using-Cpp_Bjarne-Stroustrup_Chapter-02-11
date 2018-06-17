//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 6 Exercise 8

#include "std_lib_facilities.h"

vector<char> randomCharGen(int _seed, int _num) {
	vector <char> chosen;
	int counter = 0;
	vector <char> alphabet = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
	'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
	't', 'u', 'v', 'w', 'x', 'y', 'z' };

	srand(_seed);
	while (chosen.size() < _num) {
		char temp = alphabet[rand() % alphabet.size()];
		if (chosen.size() == 0) {
			chosen.push_back(temp);
		}
		else{
			for (int j = 0; j < chosen.size(); j++) {
				if (temp == chosen[j]) {
					counter++;
				}
			}
			if (counter == 0) {
				chosen.push_back(temp);
			}
			else {
				counter = 0;
			}
		}
	}
	return chosen;
}

int main()
try
{
	vector <char> randomChars;
	vector <char> charGuess;
	char charGuessTemp;
	int charGuessCheck;

	int bulls = 0;
	int cows = 0;

	int charNums = 4;
	int seed;
	string seedCheck;

	string answer = "noAnswer";

	while (randomChars.size() < charNums) {
		cout << "Enter seed value between 0 and 100\n";
		if (cin >> seed && seed <= 100 && seed >= 0) {}
		else {
			cin.clear();
			cin >> seedCheck;
			error("Seed value is wrong: ", seedCheck);
		}
		randomChars = randomCharGen(seed, charNums);

		for (int i = 0; i < randomChars.size(); i++) {
			cout << randomChars[i] << "\n";
		}

		while (bulls != charNums) {
			bulls = 0;
			cows = 0;

			cout << "Enter 4 different letters\n";
			if (cin) {
				while (charGuess.size() < charNums) {
					if (cin >> charGuessTemp) {
						charGuess.push_back(charGuessTemp);
					}
					else {
						cin.clear();
						cin >> charGuessCheck;
						error("Entered wrong guess", charGuessCheck);
					}
				}
			}

			//COMPARING GUESS AND RANDOM LETTERS
			for (int i = 0; i < charNums; i++) {
				for (int j = 0; j < charNums; j++) {
					if (charGuess[i] == randomChars[j] && i == j) {
						bulls++;
					}
					else if (charGuess[i] == randomChars[j] && i != j) {
						cows++;
					}
				}
			}
			cout << "Bulls: " << bulls << " Cows: " << cows << "\n";
			charGuess.clear();
		}

		cout << "You win!\n";
		cout << "Play again? Type y for yes and n for no: ";
		cin >> answer;

		if (answer == "noAnswer") {
			error("Wrong Answer.");
		}
		else if (answer == "y") {
			randomChars.clear();
			bulls = 0;
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
