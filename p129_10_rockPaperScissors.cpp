//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 4 Exercise 10

#include "std_lib_facilities.h"

int main()
try
{
	int rndNum;
	string illegalRndInput;
	string moveCheck = "noCorrectMove";
	string exit;
	string yourMove;
	int computerMoveIndex;
	bool again = true;

	vector<string> Move;

	Move.push_back("Rock");
	Move.push_back("Paper");
	Move.push_back("Scissors");

	while (again == true) {

		cout << "Enter a random integer to calculate the computers next move: \n";

		while(cin){
			if (cin >> rndNum) {
				computerMoveIndex = rndNum % 3;
				break;
			}
			else {
				cin.clear();
				cin >> illegalRndInput;
				error("Illegal input for random integer: ", illegalRndInput);
			}
		}
		
		cout << computerMoveIndex << "\n";

		cin.clear();
		cout << "Enter your own move: Rock, Paper or Scissors: \n";

		if (cin >> yourMove) {
			for (int i = 0; i < Move.size(); i++) {
				if (Move[i] == yourMove) {
					moveCheck = "moveCorrect";
					cout << "Your move: " << yourMove << "\n";
					cout << "Computer move: " << Move[computerMoveIndex] << "\n";
					switch (i) {
					case 0:
						if (computerMoveIndex == 0) {
							cout << "Its a tie!\n";
						}
						else if (computerMoveIndex == 1) {
							cout << "Computer wins!\n";
						}
						else if (computerMoveIndex == 2) {
							cout << "You win!\n";
						}
						break;

					case 1:
						if (computerMoveIndex == 0) {
							cout << "You win!\n";
						}
						else if (computerMoveIndex == 1) {
							cout << "Its a tie!\n";
						}
						else if (computerMoveIndex == 2) {
							cout << "Computer wins!\n";
						}
						break;

					case 2:
						if (computerMoveIndex == 0) {
							cout << "Computer wins!\n";
						}
						else if (computerMoveIndex == 1) {
							cout << "You win!\n";
						}
						else if (computerMoveIndex == 2) {
							cout << "Its a tie!\n";
						}
						break;
					}
				}
			}
			if (moveCheck != "moveCorrect"){
				error("Illegal input for your move: ", yourMove);
			}
		}

		cout << "Play again? y for yes n for no: \n";
		string answer;
		cin >> answer;

		if (answer == "n") {
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
	cout << "exiting\n";
	keep_window_open(".");
}
