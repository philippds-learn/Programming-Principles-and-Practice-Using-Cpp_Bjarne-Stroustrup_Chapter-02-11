//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 7 Exercise 4

#include "std_lib_facilities.h"

const char let = '#';
const char exitprog = 'E';
const char print = ';';
const char number = '8';
const char name = 'a';
const char sqroot = 'S';
const char power = 'P';
const char constant = 'C';
const char reset = 'R';

struct Token {
	char kind;
	double value;
	string name;
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, double val) :kind(ch), value(val) { }
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
		full = false; return buffer;
	}
	char ch;
	cin >> ch;
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
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{
		cin.unget();
		double val;
		cin >> val;
		return Token(number, val);
	}
	default:
	{
		if (isalpha(ch) || ch == '_') { //is ch a letter?
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_')) { //reads chars, strings or digits
				s += ch; //Error 2: s = ch;
			}
			cin.unget(); //puts the most recently read character back into the stream
			if (s == "exit") return Token(exitprog); //Error 2: if (s == "quit") return Token(name);
			if (s == "sqrt") return Token(sqroot);
			if (s == "pow") return Token(power);
			if (s == "const") return Token(constant);
			if (s == "reset") return Token(reset);
			return Token(name, s);
		}
		error("Bad token");
		return Token(' '); //Line missing
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
	double value;
	bool immutable;
	Variable(string n, double v, bool i) :name(n), value(v), immutable(i) { }
};

class Symbol_table {
public:
	vector<Variable> var_table;
	double get(string);
	void set(string, double);
	bool is_declared(string);
	double declare(char);
	bool is_immutable(string);
};

Token_stream ts;
double expression();

double Symbol_table::get(string s)
{
	for (int i = 0; i < var_table.size(); ++i) {
		if (var_table[i].name == s) {
			return var_table[i].value;
		}
	}
	error("get: undefined name ", s);
	return 0.0; //Line missing
}

void Symbol_table::set(string s, double d)
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

double Symbol_table::declare(char kind)
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
	double d = expression();
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

double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{
		double d = expression();
		t = ts.get();
		if (t.kind != ')') error("')' expected"); //Error 3: if (t.kind != ')') error("'(' expected");
		return d; //Line missing
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
	case sqroot:
	{
		t = ts.get();
		if (t.kind != '(') {
			error("'(' expected");
		}
		ts.unget(t);
		double d = primary();
		if (d < 0.0) {
			error("negative square root");
		}
		return sqrt(d);
	}
	case power:
	{
		t = ts.get();
		if (t.kind != '(') {
			error("'(' expected");
		}

		double x = expression();

		t = ts.get();
		if (t.kind != ',') {
			error("',' expected");
		}

		int n = int(expression());

		t = ts.get();
		if (t.kind == ')') {
			return pow(x, n);
		}
		else {
			error("Expected ')'");
		}
	}
	case name:
	{
		return st.get(t.name);
	}
	default:
	{
		error("primary expected");
		return 0.0; //Line missing
	}
	}
}

double term()
{
	double left = primary();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case 'k':
		{
			left *= 1000;
			break;
		}
		case '*':
		{
			left *= primary();
			break;
		}
		case '/':
		{
			double d = primary();
			if (d == 0) error("divide by zero");
			left /= d;
			break;
		}
		default: {
			ts.unget(t);
			return left;
		}
		}
	}
}

double expression()
{
	double left = term();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '+':
		{
			left += term();
			break;
		}
		case '-':
		{
			left -= term();
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

double statement()
{
	Token t = ts.get();
	double d;
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
	while (true) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) {
			t = ts.get();
		}
		if (t.kind == exitprog) {
			return;
		}
		ts.unget(t);
		cout << result << statement() << endl;
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