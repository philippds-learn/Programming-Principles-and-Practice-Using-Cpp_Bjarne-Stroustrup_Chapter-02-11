#include "p340_8_my_book_class.h"


//BOOK CLASS_HELPER FUNCTIONS------

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

Book::Book(ISBN _isbn, string _title, string _author, Date _copyright_date, Genre _genrebook, bool _checked_out) {
	cout << "--- Creating book ---\n";
	isbn = _isbn;
	title = _title;
	author = _author;
	copyright_date = _copyright_date;
	genre = _genrebook;
	checked_out = _checked_out;
};

Book::Book() {
	cout << "--- Creating book ---\n";
	isbn = ISBN(0, 0, 0, 0);
	title = "";
	author = "";
	copyright_date = Date();
	genre = Genre();
	checked_out = false;
}

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

ostream& operator << (ostream& os, const Genre& _genre) {
	switch (_genre) {
	case Genre::biography:
		os << "biography";
		return os;
	case Genre::children:
		os << "children";
		return os;
	case Genre::fiction:
		os << "fiction";
		return os;
	case Genre::nonfiction:
		os << "nonfiction";
		return os;
	case Genre::periodical:
		os << "periodical";
		return os;
	}
}

ostream& operator << (ostream& os, Book& _book) {
	os << "ISBN: " << _book.isbnf() << "\n"
		<< "Title: " << _book.titlef() << "\n"
		<< "Author: " << _book.authorf() << "\n"
		<< "Copyright Date: " << _book.copyright_datef() << "\n"
		<< "Genre: " << _book.genref() << "\n"
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

//endBOOK CLASS_HELPER FUNCTIONS------



//PATRON CLASS_HELPER FUNCTIONS------

Patron::Patron(string _patron_name, int _patron_num) {
	cout << "--- Creating Patron ---\n";
	patron_name = _patron_name;
	patron_num = _patron_num;
	fee_owed = false;
	fee_amount = 0;
}

Patron::Patron() {
	cout << "--- Creating Patron ---\n";
	patron_name = "";
	patron_num = 0000;
	fee_owed = false;
	fee_amount = 0;
}

void Patron::add_fee(double _fee) {
	fee_amount += _fee;
	if (fee_amount != 0) {
		fee_owed = true;
	}
	else {
		fee_owed = false;
	}
}

ostream& operator << (ostream& os, Patron& _patron) {
	os << "Patron Name: " << _patron.patron_namef() << "\n"
		<< "Patron Number: " << _patron.patron_numf() << "\n"
		<< "Fee owed: " << boolalpha << _patron.fee_owedf() << "\n"
		<< "Fee owed: " << _patron.fee_amountf() << "\n";
	return os;
}

//endPATRON CLASS_HELPER FUNCTIONS------