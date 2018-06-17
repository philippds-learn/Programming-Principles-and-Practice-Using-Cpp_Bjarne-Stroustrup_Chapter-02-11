//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 6 Exercise 9

#include "std_lib_facilities.h"

class Token {
public:
	char intChar;
	Token(char iCh)
		:intChar(iCh) { }
};

class Token_stream {
public:
	Token_stream();
	Token get();
	void putback(Token t);
private:
	bool full;
	Token buffer;
};

Token_stream::Token_stream()
	:full(false), buffer(0)
{
}

void Token_stream::putback(Token t)
{
	if (full) error("putback() into a full buffer");
	buffer = t;
	full = true;
}


Token Token_stream::get()
{
	if (full) {
		full = false;
		return buffer;
	}

	char iCh;
	cin >> iCh;

	switch (iCh) {
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	case 'x':
	{
		//cin.putback(iCh);
		return Token(iCh);
	}
	default:
		error("Bad token");
	}
}

Token_stream ts;

int main()
try
{
	cout << "Enter 1-4 integer values\n";
	vector<int> intFromChar;
	int intAdded = 0;
	bool check = true;
	
	while (check) {
		if (intFromChar.size() < 4) {
			Token t = ts.get();
			if (t.intChar == 'x') break; // 'x' for quit
			intFromChar.push_back(t.intChar - '0');
		}
		else{
			check = false;
		}
	}
	
	cout << "Num size: " << intFromChar.size() << "\n";

	for (int i = 0; i < intFromChar.size(); i++) {
		int result = pow(10, intFromChar.size() - i) / 10;
		intFromChar[i] = intFromChar[i] * result;
	}

	for (int i = 0; i < intFromChar.size(); i++) {
		intAdded += intFromChar[i];
	}

	if (intFromChar.size() == 1) {
		cout << intAdded << " is "
		<< intFromChar[0] << " ones\n";
	}

	if (intFromChar.size() == 2) {
		cout << intAdded << " is "
		<< intFromChar[0] << " tens and "
		<< intFromChar[1] << " ones\n";
	}

	if (intFromChar.size() == 3) {
		cout << intAdded << " is "
		<< intFromChar[0] << " hundreds and "
		<< intFromChar[1] << " tens and "
		<< intFromChar[2] << " ones\n";
	}

	if (intFromChar.size() == 4) {
		cout << intAdded << " is "
		<< intFromChar[0] << " thousands and "
		<< intFromChar[1] << " hundreds and "
		<< intFromChar[2] << " tens and "
		<< intFromChar[3] << " ones\n";
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
