//	Philipp Siedler
//	Bjarne Stroustrup's PPP
//	Chapter 9 Exercise 9

#include "p340_9_my_book_class.h"
using namespace Chrono;

Library my_Library;

void add_books() {
	Book my_Book(ISBN(), "book1", "author1", Date(2000, Date::jul, 5), Genre::biography, false);
	my_Library.add_book(my_Book);
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

/*if (year is not divisible by 4) then (it is a common year)
else if (year is not divisible by 100) then (it is a leap year)
else if (year is not divisible by 400) then (it is a common year)
else (it is a leap year)

common year = 365 days
leap year = 366 days
*/