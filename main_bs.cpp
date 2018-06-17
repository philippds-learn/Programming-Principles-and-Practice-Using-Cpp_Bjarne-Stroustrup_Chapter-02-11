
int main()
try
{
	Chrono::Date xxx(2001, Chrono::Date::jan, 1);
	write(xxx);
	Chrono::Date xxxw = next_weekday(xxx);
	write(xxxw);

	Chrono::Date xx(2001, Chrono::Date::jan, 8);
	write(xx);
	Chrono::Date xxw = next_weekday(xx);
	write(xxw);

	Chrono::Date today(2010, Chrono::Date::jan, 16);
	write(today);
	Chrono::Date todayw = next_weekday(today);
	write(todayw);

	Chrono::Date vote(2010, Chrono::Date::mar, 13);
	write(vote);
	Chrono::Date votew = next_weekday(vote);
	write(votew);

	using namespace Chrono;
	cout << "enter some dates: ";
	Date d;
	while (cin >> d) {
		write(d);
	}

	keep_window_open("~");	// For some Windows(tm) setups
}
catch (Chrono::Date::Invalid&) {
	cerr << "error: Invalid date\n";
	keep_window_open("~");	// For some Windows(tm) setup
	return 1;
}
catch (runtime_error& e) {	// this code is to produce error messages
	cout << e.what() << '\n';
	keep_window_open("~");	// For some Windows(tm) setups
}

/*
This has not been SYSTEMATICALLY tested, so you should be able to find bugs;
I'd like to hear about those.
*/