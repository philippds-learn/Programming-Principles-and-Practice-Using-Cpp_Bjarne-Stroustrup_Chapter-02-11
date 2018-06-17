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

// exercise 7 genre enumerator
enum Genre {
	fiction = 0,
	nonfiction,
	periodical,
	biography,
	children
};

class Book {
private:
	ISBN isbn;
	string title;
	string author;
	Date copyright_date;
	Genre genre;
	bool checked_out;

public:
	Book(ISBN _isbn, string _title, string _author, Date _copyright_date, Genre _genrebook, bool _checked_out);
	Book();
	ISBN isbnf() { return isbn; }
	string titlef() { return title; }
	string authorf() { return author; }
	Date copyright_datef() { return copyright_date; }
	Genre genref() { return genre; }
	bool checked_outf() { return checked_out; }
	void book_out();
	void book_in();
};

//exercise 6 operator overloading
ostream& operator << (ostream&, ISBN&);
ostream& operator << (ostream&, const Genre&);
ostream& operator << (ostream&, Book&);
bool operator ==(ISBN&, ISBN&);
bool operator !=(ISBN&, ISBN&);

//endBOOK CLASS------

//PATRON CLASS------
class Patron {
private:
	string patron_name;
	int patron_num;
	bool fee_owed;
	double fee_amount;
public:
	Patron(string _patron_name, int _patron_num);
	Patron();

	string patron_namef() { return patron_name; }
	int patron_numf() { return patron_num; }
	bool fee_owedf() { return fee_owed; }
	double fee_amountf() { return fee_amount; }

	void add_fee(double _fee);
};

ostream& operator << (ostream&, Patron&);

//endPATRON CLASS------