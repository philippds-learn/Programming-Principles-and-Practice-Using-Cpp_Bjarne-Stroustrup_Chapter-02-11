#include "p340_6_my_book_class.h"

ISBN::ISBN(int _n0, int _n1, int _n2, char _x) {
	n0 = _n0;
	n1 = _n1;
	n2 = _n2;
	x = _x;
}

ISBN::ISBN() {
	n0 = 0;
	n1 = 0;
	n2 = 0;
	x = '0';
}

Book::Book(ISBN _isbn, string _title, string _author, Date _copyright_date, bool _checked_out) {

	cout << "Creating book\n";
	isbn = _isbn;
	title = _title;
	author = _author;
	copyright_date = _copyright_date;
	checked_out = _checked_out;
};

void Book::book_out() {
	checked_out = true;
};

void Book::book_in() {
	checked_out = false;
};

ostream& operator << (ostream& os, ISBN& _isbn) {
	os << _isbn.n0 << _isbn.n1 << _isbn.n2 << _isbn.x;
	return os;
}

ostream& operator << (ostream& os, Book& _book) {
	os << "ISBN: " << _book.isbnf() << "\n"
		<< "Title: " << _book.titlef() << "\n"
		<< "Author: " << _book.authorf() << "\n"
		<< "Copyright Date: " << _book.copyright_datef() << "\n"
		<< "Checked out: " << boolalpha << _book.checked_outf() << "\n";
	return os;
}

bool operator ==(ISBN& book1, ISBN& book2) {
	if (book1 == book2) {
		return true;
	}
	else {
		return false;
	}
}

bool operator !=(ISBN& book1, ISBN& book2) {
	if (book1 != book2) {
		return true;
	}
	else {
		return false;
	}
}