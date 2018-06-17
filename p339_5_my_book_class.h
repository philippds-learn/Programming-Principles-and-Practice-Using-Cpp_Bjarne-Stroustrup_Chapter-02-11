#include "std_lib_facilities.h"
#include "Chrono.h"
using namespace Chrono;

//BOOK CLASS------
struct ISBN {
	int n0, n1, n2;
	char x;
	ISBN(int n0, int n1, int n2, char x);
	ISBN();
};

class Book {
private:
	ISBN isbn;
	string title;
	string author;
	Date copyright_date;
	bool checked_out;

public:
	Book(ISBN _isbn, string _title, string _author, Date _copyright_date, bool _checked_out);
	Book();
	ISBN isbnf() { return isbn; }
	string titlef() { return title; }
	string authorf() { return author; }
	Date copyright_datef() { return copyright_date; }

	bool checked_outf() { return checked_out; }
	void book_out();
	void book_in();
};
//endBOOK CLASS------
