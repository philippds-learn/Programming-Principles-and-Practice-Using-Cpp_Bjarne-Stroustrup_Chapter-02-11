//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 6 Exercise 7

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

class Token {
public:
	char kind;        // what kind of token
	int value;     // for numbers: a value 
	Token(char ch)    // make a Token from a char
		:kind(ch), value(0) { }
	Token(char ch, double val)     // make a Token from a char and a double
		:kind(ch), value(val) { }
};

//------------------------------------------------------------------------------

class Token_stream {
public:
	Token_stream();   // make a Token_stream that reads from cin
	Token get();      // get a Token (get() is defined elsewhere)
	void putback(Token t);    // put a Token back
private:
	bool full;        // is there a Token in the buffer?
	Token buffer;     // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
	:full(false), buffer(0)    // no Token in buffer
{
}

//------------------------------------------------------------------------------

Token Token_stream::get()
{
	if (full) {       // do we already have a Token ready?
					  // remove token from buffer
		full = false;
		return buffer;
	}

	char ch;
	cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

	switch (ch) {
	case '=':    // for "print"
	case 'x':    // for "quit"
	case '&': case '^': case '|':
		return Token(ch);        // let each character represent itself
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	{
		cin.putback(ch);         // put digit back into the input stream
		int val;
		cin >> val;              // read a floating-point number
		return Token('8', val);   // let '8' represent "a number"
	}
	default:
		error("Bad token");
	}
}

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
	if (full) error("putback() into a full buffer");
	buffer = t;       // copy t to buffer
	full = true;      // buffer is now full
}

//------------------------------------------------------------------------------

Token_stream ts;        // provides get() and putback() 

						//------------------------------------------------------------------------------

int or ();    // declaration so that primary() can call expression()

			  //------------------------------------------------------------------------------

			  // deal with numbers and parentheses
			  /*
			  int prefix()
			  {
			  Token t = ts.get();
			  switch (t.kind) {

			  case '!':     // handle '!' expression
			  {
			  int d = or();
			  t = ts.get();
			  if (t.kind == '8') {
			  d != d;
			  return d;
			  }
			  return d;
			  }

			  case '~':     // handle '~' expression
			  {
			  int d = or();
			  t = ts.get();
			  if (t.kind == '8') {
			  d = ~d;
			  return d;
			  }
			  return d;
			  }

			  case '8':            // we use '8' to represent a number
			  return t.value;  // return the number's value

			  default:
			  error("primary expected");
			  }
			  }
			  */

int primary()
{
	Token t = ts.get();
	switch (t.kind) {

	case '(':     // handle '(' expression ')'
	{
		int d = or ();
		t = ts.get();
		if (t.kind != ')') error("')' expected)"); //ERROR 3/5: "if (t.kind != ')') error("')' expected)", missing );
		return d;
	}

	case '{':     // handle '(' expression ')'
	{
		int d = or ();
		t = ts.get();
		if (t.kind != '}') error("'}' expected)"); //ERROR 3/5: "if (t.kind != ')') error("')' expected)", missing );
		return d;
	}

	case '8':            // we use '8' to represent a number
		return t.value;  // return the number's value

	default:
		error("primary expected");
	}
}

//------------------------------------------------------------------------------

// deal with &
int and()
{
	int left = primary();
	Token t = ts.get();        // get the next token from token stream

	while (true) {
		if (t.kind == '&') {
			left &= primary();
			t = ts.get();
			break;
		}
		else {
			ts.putback(t);     // put t back into the token stream
			return left;
		}
	}
}

//------------------------------------------------------------------------------

// deal with ^
int exclusiveOr()
{
	int left = and ();      // read and evaluate a Term //ERROR 4/5: "double left = term(;" mssing )
	Token t = ts.get();        // get the next token from token stream

	while (true) {
		if (t.kind == '^') {
			left ^= and ();    // evaluate Term and add
			t = ts.get();
			break;
		}
		else {
			ts.putback(t);     // put t back into the token stream
			return left;       // finally: no more + or -: return the answer
		}
	}
}

// deal with |
int or ()
{
	int left = exclusiveOr();      // read and evaluate a Term //ERROR 4/5: "double left = term(;" mssing )
	Token t = ts.get();        // get the next token from token stream

	while (true) {
		if (t.kind == '|') {
			left |= exclusiveOr();    // evaluate Term and add
			t = ts.get();
			break;
		}
		else {
			ts.putback(t);     // put t back into the token stream
			return left;       // finally: no more + or -: return the answer
		}
	}
}

//------------------------------------------------------------------------------

int main()
try
{
	cout << "Welcome to a bitwise-logical-expression calculator.\n";
	cout << "Please enter expressions using integer-point numbers.\n";
	cout << "Currently available prefixes: '!', '~', operators are: '&', '^', '|'.\n";
	cout << "Use '=' to get result or 'x' to quit the program.\n";

	int val = 0;

	while (cin) {
		Token t = ts.get();

		if (t.kind == 'x') break; // 'x' for quit
		if (t.kind == '=') {  // '=' for "print now"
			cout << "=" << val << '\n';
			cout << "Nothing\n";
		}
		else {
			ts.putback(t);
			cout << "Putback\n";
		}

		val = or ();
	}

	keep_window_open(".");
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "Oops: unknown exception!\n";
	keep_window_open();
	return 2;
}

//------------------------------------------------------------------------------