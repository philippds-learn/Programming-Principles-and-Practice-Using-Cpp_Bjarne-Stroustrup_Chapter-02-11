//	Philipp Siedler
//	Bjarne Stroustrup's PPP
//	Chapter 9 Exercise 8

#include "p340_8_my_book_class.h"
using namespace Chrono;

void add_books() {
	Book my_Book(ISBN(), "book1", "author1", Date(2000, Date::jul, 5), Genre::biography, false);
}

int main()
try
{
	add_books();
	Patron examplePatron("Phil", 100);
	cout << examplePatron;
	keep_window_open();
}
catch (runtime_error e) {
	cout << e.what() << endl;
	keep_window_open();
}
catch (...) {
	cout << "Exiting" << endl;
	keep_window_open();
}
