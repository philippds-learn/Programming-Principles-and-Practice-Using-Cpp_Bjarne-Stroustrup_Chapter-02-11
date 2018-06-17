//	Philipp Siedler
//	Bjarne Stroustrup's PPP
//	Chapter 9 Exercise 6

#include "p340_6_my_book_class.h"
using namespace Chrono;

int main()
try
{
	Book myBook(ISBN(), "book1", "author1", Date(2000, Date::jul, 5), false);
	cout << myBook;
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