#include "p340_9_my_book_class.h"


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



//LIBRARY CLASS_HELPER FUNCTIONS------

bool operator ==(Book& _book1, Book& _book2) {
	if (_book1.isbnf() == _book2.isbnf()
		&& _book1.titlef() == _book2.titlef()
		&& _book1.authorf() == _book2.authorf()) {
		return true;
	}
	else {
		return false;
	}
}

bool operator ==(Patron& _patron1, Patron& _patron2) {
	if (_patron1.patron_namef() == _patron2.patron_namef()
		&& _patron1.patron_numf() == _patron2.patron_numf()) {
		return true;
	}
	else {
		return false;
	}
}

void Library::add_book(Book _book) {
	if (books.size() == 0) {
		books.push_back(_book);
	}
	else {
		int counter = 0;
		for (int i = 0; i < books.size(); i++) {
			if (books[i] == _book) {
				cout << "Book already exists in Library\n";
				counter++;
			}
		}
		if (counter == 0) {
			books.push_back(_book);
		}
	}
}

void Library::add_patron(Patron _patron) {
	if (patrons.size() == 0) {
		patrons.push_back(_patron);
	}
	else {
		int counter = 0;
		for (int i = 0; i < patrons.size(); i++) {
			if (patrons[i] == _patron) {
				cout << "Patron already exists in Library\n";
				counter++;
			}
		}
		if (counter == 0) {
			patrons.push_back(_patron);
		}
	}
}

void Library::add_transaction(Book _book, Patron _patron, Date _date) {
	bool book_ckeck = false;
	bool patron_check = false;

	//book check
	for (int i = 0; i < books.size(); i++) {
		if (books[i] == _book) {
			book_ckeck = true;
		}
	}
	if (!book_ckeck) {
		cout << "Book does not exist in Library\n";
	}

	//patron check
	for (int i = 0; i < patrons.size(); i++) {
		if (patrons[i] == _patron) {
			patron_check = true;
		}
	}
	if (!patron_check) {
		cout << "Patron does not exist in Library\n";
	}

	//adding transaction
	if (!_book.checked_outf() && book_ckeck && patron_check) {
		_book.book_out();
		transactions.push_back(Transaction(_book, _patron, _date));
		cout << "Book checked out!\n";
	}
	else {
		_book.book_in();
		transactions.push_back(Transaction(_book, _patron, _date));
		cout << "Book checked in!\n";
	}
}

void Library::fee_check() {
	for (int i = 0; i < patrons.size(); i++) {
		if (patrons[i].fee_owedf()) {
			cout << patrons[i].patron_namef() << "\n";
			cout << patrons[i].fee_amountf() << "\n";
		}
	}
}

//endLIBRARY CLASS_HELPER FUNCTIONS------