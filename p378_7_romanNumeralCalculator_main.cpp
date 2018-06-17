//	Philipp Siedler
//	Bjarne Stroustrup's PPP
//	Chapter 10 Exercise 7

#include "p378_7_romanNumerals_class.h"

const char let = '#';
const char quitProg = 'Q';
const char print = ';';
const char number = '8';
const char name = 'a';
const char constant = 'O';
const char reset = 'R';
const char help = 'H';

struct Token {
	char kind;
	Roman_int value;
	string name;
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, Roman_int val) :kind(ch), value(val) { }
	Token(char ch, string val) :kind(ch), name(val) { } //Error 1: Line missing
};

class Token_stream {
	bool full;
	Token buffer;
public:
	Token_stream() :full(0), buffer(0) { }
	Token get();
	void unget(Token t) { buffer = t; full = true; }
	void ignore(char);
};

Token Token_stream::get()
{
	if (full) {
		full = false;
		return buffer;
	}

	char ch;
	cin.get(ch);

	while (isspace(ch)) {
		if (ch == '\n') return Token(print); // if newline detected, return print Token
		cin.get(ch);
	}

	switch (ch) {
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case '=':
	case 'k':
	case ',':
	{
		return Token(ch);
	}
	case '#':
	{
		return Token(let);
	}
	case 'N':
	case 'I':
	case 'V':
	case 'X':
	case 'L':
	case 'C':
	case 'D':
	case 'M':
	{
		cin.unget();
		Roman_int val;
		cin >> val;
		return Token(number, val);
	}
	default:
	{
		if (isalpha(ch) || ch == '_') { //is ch a letter?
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_')) { //reads chars, strings or digits
				s += ch;
			}
			cin.unget(); //puts the most recently read character back into the stream
			if (s == "quit") return Token(quitProg);
			if (s == "const") return Token(constant);
			if (s == "reset") return Token(reset);
			if (s == "help" || s == "Help") return Token(help);
			return Token(name, s);
		}
		error("Bad token");
		return Token(' ');
	}
	}
}

void Token_stream::ignore(char c)
{
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;
	char ch;
	while (cin >> ch) {
		if (ch == c) return;
	}
}

struct Variable {
	string name;
	Roman_int value;
	bool immutable;
	Variable(string n, Roman_int v, bool i) :name(n), value(v), immutable(i) { }
};

class Symbol_table {
public:
	vector<Variable> var_table;
	Roman_int get(string);
	void set(string, Roman_int);
	bool is_declared(string);
	Roman_int declare(char);
	bool is_immutable(string);
};

Token_stream ts;
Roman_int expression();
Roman_int primary();

Roman_int Symbol_table::get(string s)
{
	for (int i = 0; i < var_table.size(); ++i) {
		if (var_table[i].name == s) {
			return var_table[i].value;
		}
	}
	error("get: undefined name ", s);
	return 0.0;
}

void Symbol_table::set(string s, Roman_int d)
{
	for (int i = 0; i <= var_table.size(); ++i) {
		if (var_table[i].name == s) {
			var_table[i].value = d;
			return;
		}
	}
	error("set: undefined name ", s);
}

bool Symbol_table::is_declared(string s)
{
	for (int i = 0; i < var_table.size(); ++i) {
		if (var_table[i].name == s) return true;
	}
	return false;
}

Roman_int Symbol_table::declare(char kind)
{
	Token t = ts.get();
	if (t.kind != name) {
		error("name expected in declaration");
	}

	string name = t.name;
	if (kind == let || kind == constant) {
		if (is_declared(name)) error(name, " declared twice");
	}
	else if (kind == reset) {
		if (!is_declared(name))
			error(name, " has not been declared");
		if (is_immutable(name))
			error(name, " is a constant");
	}
	else {
		error("unknown statement");
	}

	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", name);
	Roman_int d = expression();
	if (is_declared(name))
		set(name, d);
	else
		var_table.push_back(Variable(name, d, (kind == constant)));
	return d;
}

bool Symbol_table::is_immutable(string s)
{
	for (int i = 0; i<int(var_table.size()); ++i)
		if (var_table[i].name == s && var_table[i].immutable) return true;
	return false;
}

Symbol_table st;

Roman_int primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{
		Roman_int d = expression();
		t = ts.get();
		if (t.kind != ')') error("')' expected");
		return d;
	}
	case '-':
	{
		return -primary();
	}
	case '+':
	{
		return primary();
	}
	case number:
	{
		return t.value;
	}
	case name:
	{
		return st.get(t.name);
	}
	default:
	{
		error("primary expected");
	}
	}
}

Roman_int term()
{
	Roman_int left = primary();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '*':
		{
			left = left * primary();
			break;
		}
		case '/':
		{
			Roman_int d = primary();
			if (d == Roman_int(0)) error("divide by zero");
			left = left / d;
			break;
		}
		case '%':
		{
			Roman_int i1 = left;
			Roman_int i2 = primary();
			if (i2 == Roman_int(0)) error("%: divide by zero");
			left = i1 % i2;
			break;
		}
		default: {
			ts.unget(t);
			return left;
		}
		}
	}
}

Roman_int expression()
{
	Roman_int left = term();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '+':
		{
			left = left + term();
			break;
		}
		case '-':
		{
			left = left - term();
			break;
		}
		default:
		{
			ts.unget(t);
			return left;
		}
		}
	}
}

Roman_int statement()
{
	Token t = ts.get();
	Roman_int d;
	if (t.kind == let || t.kind == reset || t.kind == constant) {
		d = st.declare(t.kind);
	}
	else {
		ts.unget(t);
		d = expression();
	}
	t = ts.get();
	if (t.kind != print) {
		error("Missing terminator");
	}

	return d;
}

void clean_up_mess()
{
	ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

void calculate()
{
	cout << "Welcome to my calculator.\n"
		<< "Just hit enter or ; at the end of your function to calculate.\n"
		<< "Enter help or Help for help or quit to exit the program.\n";
	while (true) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) {
			t = ts.get();
		}
		if (t.kind == help) {
			cout << "You can use / *-+operators.\n"
				<< "Declaring variables using #, for example: # x = 5.\n";
		}
		else {
			if (t.kind == quitProg) {
				return;
			}
			ts.unget(t);
			cout << result << statement() << endl;
		}
	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

int main()
try {
	calculate();
	return 0;
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	char c;
	while (cin >> c&& c != ';');
	return 1;
}
catch (...) {
	cerr << "exception\n";
	char c;
	while (cin >> c && c != ';');
	return 2;
}