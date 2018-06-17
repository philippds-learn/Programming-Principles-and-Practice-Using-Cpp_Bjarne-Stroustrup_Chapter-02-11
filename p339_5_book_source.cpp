#include "p339_5_my_book_class.h"

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

Book::Book() {
	
	cout << "Creating book\n";
	isbn = ISBN();
	title = "noTitle";
	author = "noAuthor";
	copyright_date = Date();
	checked_out = false;
}

void Book::book_out() {
	checked_out = true;
};

void Book::book_in() {
	checked_out = false;
};

