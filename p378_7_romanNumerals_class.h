#pragma once
//	Philipp Siedler
//	Bjarne Stroustrup's PPP
//	Chapter 10 Exercise 7

#include "std_lib_facilities.h"

vector<char> roman_chars = {
	'N', 'I', 'V', 'X', 'L', 'C', 'D', 'M'
};

int roman_char_value(char ch) {
	switch (ch) {
	case 'N':
		return 0;
	case 'I':
		return 1;
	case 'V':
		return 5;
	case 'X':
		return 10;
	case 'L':
		return 50;
	case 'C':
		return 100;
	case 'D':
		return 500;
	case 'M':
		return 1000;
	default:
		return -1;
	}
}

class Roman_int {
private:
	string roman_string;
	int roman_int;
public:

	Roman_int() {};
	Roman_int(int _roman_int);
	Roman_int(string _roman_string);

	void set_values();
	void set_values(int);
	string get_string() { return roman_string; }
	int get_int() { return roman_int; }
};

//DEFAULT OVERLOAD------

Roman_int::Roman_int(int _roman_int) {
	roman_int = _roman_int;
}

Roman_int::Roman_int(string _roman_string) {
	roman_string = _roman_string;
}

//DEFAULT OVERLOAD------END


//OPERATOR OVERLOAD-------

ostream& operator<<(ostream& os, Roman_int& _roman_int) {
	os << "Roman_int conversion:\n"
		<< _roman_int.get_string()
		<< " equals " << _roman_int.get_int() << endl;
	return os;
}

Roman_int operator+(Roman_int& r1, Roman_int& r2) {
	Roman_int result(r1.get_int() + r2.get_int());
	return result;
}

Roman_int operator-(Roman_int& r1, Roman_int& r2) {
	Roman_int result(r1.get_int() - r2.get_int());
	return result;
}

Roman_int operator-(Roman_int& r1) {
	Roman_int result(-r1.get_int());
	return result;
}

Roman_int operator*(Roman_int& r1, Roman_int& r2) {
	Roman_int result(r1.get_int() * r2.get_int());
	return result;
}

Roman_int operator/(Roman_int& r1, Roman_int& r2) {
	Roman_int result(r1.get_int() / r2.get_int());
	return result;
}

Roman_int operator%(Roman_int& r1, Roman_int& r2) {
	Roman_int result(r1.get_int() % r2.get_int());
	return result;
}

bool operator==(Roman_int& r1, Roman_int& r2) {
	if (r1.get_int() == r2.get_int()) {
		return true;
	}
	else {
		return false;
	}
}

bool operator!=(Roman_int& r1, Roman_int& r2) {
	if (r1.get_int() != r2.get_int()) {
		return true;
	}
	else {
		return false;
	}
}

bool operator<(Roman_int& r1, Roman_int& r2) {
	if (r1.get_int() < r2.get_int()) {
		return true;
	}
	else {
		return false;
	}
}

bool operator>(Roman_int& r1, Roman_int& r2) {
	if (r1.get_int() > r2.get_int()) {
		return true;
	}
	else {
		return false;
	}
}

bool operator<=(Roman_int& r1, Roman_int& r2) {
	if (r1.get_int() <= r2.get_int()) {
		return true;
	}
	else {
		return false;
	}
}

bool operator>=(Roman_int& r1, Roman_int& r2) {
	if (r1.get_int() >= r2.get_int()) {
		return true;
	}
	else {
		return false;
	}
}

//OPERATOR OVERLOAD-------END


//READ------

bool read_roman_string(string& _value) {
	string _value_temp;
	if (cin >> _value_temp) {
		_value = _value_temp;
		return true;
	}
	else {
		return false;
	}
}

//CHECK VALIDITY------

bool check_string_validity(string& _value) {
	if (_value.size() == 1) {
		cout << "Checking validity of roman char... ";
	}
	else {
		cout << "Checking validity of roman string... ";
	}

	int size = int(_value.size());
	vector<int> invalid_index;

	for (int i = 0; i < size; i++) {
		int check = 0;
		for (int j = 0; j < roman_chars.size(); j++) {
			if (roman_chars[j] == _value[i]) {
				check++;
			}
		}
		if (check == 0) {
			invalid_index.push_back(i);
		}
	}

	if (invalid_index.size() != 0) {
		cout << "Invalid char: ";
		for (int i = 0; i < invalid_index.size(); i++) {
			cout << _value[invalid_index[i]] << " ";
		}
		cout << endl;
		return false;
	}
	else {
		if (_value.size() == 1) {
			cout << "Valid roman char." << endl;
			return true;
		}
		else {
			cout << "Valid roman string." << endl;
			return true;
		}
	}
}

bool check_char_validity(char& _value) {
	cout << "Checking validity of roman char... ";

	int check = 0;
	for (int j = 0; j < roman_chars.size(); j++) {
		if (roman_chars[j] == _value) {
			check++;
		}
	}
	if (check == 0) {
		cout << "Invalid char: " << _value << endl;
		return false;
	}
	else {
		cout << "Valid roman char." << endl;
	}
}

//CHECK COUNT------

bool check_char_count(string& _value) {
	cout << "Checking number of roman chars... ";

	int size = _value.size();
	vector<int> counter(roman_chars.size(), 0);

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < roman_chars.size(); j++) {
			if (_value[i] == roman_chars[j]) {
				counter[j]++;
			}
		}
	}

	int check = 0;
	for (int i = 0; i < roman_chars.size(); i++) {
		if (counter[i] > 1 && (roman_chars[i] == 'V' || roman_chars[i] == 'L' || roman_chars[i] == 'D')) {
			cout << "Invalid number of " << roman_chars[i] << "." << endl;
			check++;
		}
		else if (counter[i] > 3 && (roman_chars[i] == 'I' || roman_chars[i] == 'X' || roman_chars[i] == 'C' || roman_chars[i] == 'M')) {
			cout << "Invalid number of " << roman_chars[i] << "." << endl;
			check++;
		}
	}
	if (check == 0) {
		if (_value.size() == 1) {
			cout << "It is a single char." << endl;
		}
		else {
			cout << "Valid number of chars." << endl;
		}
		return true;
	}
	else {
		return false;
	}
}

//STRING TO INT-------

void decompose_roman_string(string& _value, int& _digit) {
	cout << "Decomposing roman string... ";

	int resulting_val = 0;
	int size = _value.size();
	int check = 0;

	//fill vector
	vector<int> value_ints;
	for (int i = 0; i < size; i++) {
		value_ints.push_back(roman_char_value(_value[i]));
	}

	/*
	I placed before V or X indicates one less, so four is IV (one less than five) and nine is IX (one less than ten)
	X placed before L or C indicates ten less, so forty is XL (ten less than fifty) and ninety is XC (ten less than a hundred)
	C placed before D or M indicates a hundred less, so four hundred is CD (a hundred less than five hundred) and nine hundred is CM (a hundred less than a thousand)
	*/

	if (size == 1) {
		resulting_val = value_ints[0];
	}
	else {
		for (int i = 0; i < size; i++) {
			if (_value[i] == 'I' && (_value[i + 1] == 'V' || _value[i + 1] == 'X')) {
				if (i == 0 && size == 2) {
					resulting_val += (value_ints[i + 1] - value_ints[i]);
					i++;
				}
				else if ((value_ints[i + 1] - value_ints[i]) < resulting_val) {
					resulting_val += (value_ints[i + 1] - value_ints[i]);
					i++;
				}
				else {
					cout << "Number not existing." << endl;
					check = 1;
				}
			}
			else if (_value[i] == 'X' && (_value[i + 1] == 'L' || _value[i + 1] == 'C')) {
				if (i == 0 && size == 2) {
					resulting_val += (value_ints[i + 1] - value_ints[i]);
					i++;
				}
				else if ((value_ints[i + 1] - value_ints[i]) < resulting_val) {
					resulting_val += (value_ints[i + 1] - value_ints[i]);
					i++;
				}
				else {
					cout << "Number not existing." << endl;
					check = 1;
				}
			}
			else if (_value[i] == 'C' && (_value[i + 1] == 'D' || _value[i + 1] == 'M')) {
				if (i == 0 && size == 2) {
					resulting_val += (value_ints[i + 1] - value_ints[i]);
					i++;
				}
				else if ((value_ints[i + 1] - value_ints[i]) < resulting_val) {
					resulting_val += (value_ints[i + 1] - value_ints[i]);
					i++;
				}
				else {
					cout << "Number not existing." << endl;
					check = 1;
				}
			}
			else {
				resulting_val += value_ints[i];
			}
		}
	}

	if (check == 0) {
		cout << "resulting value = " << resulting_val << endl;
		_digit = resulting_val;
	}
}

//SET VALUES------

void Roman_int::set_values() {
	//while (true) {
	cout << "Enter roman string or char:" << endl;
	//read roman string from user
	if (read_roman_string(roman_string)) {
		if (roman_string == "p") {
			//break;
		}
		//check if valid roman chars
		//check if valid count of chars
		else if (check_string_validity(roman_string) && check_char_count(roman_string)) {
			//decompose roman string
			decompose_roman_string(roman_string, roman_int);
			cout << "Roman_int conversion:\n"
				<< get_string()
				<< " equals " << get_int() << endl;
		}
	}
	//}
}

void Roman_int::set_values(int _val) {
	roman_int = _val;
}

istream& operator>>(istream& is, Roman_int& _roman_int) {
	// throw exception if is.bad()
	is.exceptions(is.exceptions() | ios_base::badbit);

	string s;
	char ch;

	// add characters to s until space, newline, eof or invalid character
	while (is.get(ch)) {
		if (check_char_validity(ch)) s += ch;
		else {
			is.putback(ch);
			break;
		}
	}

	// s consists only of valid characters - is it a valid Roman numeral?
	int val;
	decompose_roman_string(s, val);
	_roman_int.set_values(val);
	return is;
}
