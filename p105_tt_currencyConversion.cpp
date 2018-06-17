//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 4 Try This page 105

#include "std_lib_facilities.h"

int main()
{
	const double yenToDollar = 101.10;
	const double euroToDollar = 0.89;
	const double poundToDollar = 0.76;

	

	double dollar = 1;
	char currency = 'a';

	cout << "Please enter an amount of dollar(s) you want to convert,\nfollowed by the desired conversion currency (yen = y, euro = e, pound = p): \n";
	cin >> dollar >> currency;
	
	if (currency == 'y')
	{
		if (dollar*yenToDollar <= 1)
		{
			cout << dollar << " dollar is " << dollar*yenToDollar << " yen";
		}
		else
		{
			cout << dollar << " dollars are " << dollar*yenToDollar << " yen\n";
		}
	}
	else if(currency == 'e')
	{
		if (dollar*euroToDollar <= 1)
		{
			cout << dollar << " dollar is " << dollar*euroToDollar << " euro\n";
		}
		else
		{
			cout << dollar << " dollars are " << dollar*euroToDollar << " euros\n";
		}
	}
	else if (currency == 'p')
	{
		if (dollar*euroToDollar <= 1)
		{
			cout << dollar << " dollar is " << dollar*poundToDollar << " pound\n";
		}
		else
		{
			cout << dollar << " dollars are " << dollar*poundToDollar << " pounds\n";
		}
	}
	else
	{
		cout << "I dont know what " << currency << " for an currency is\n";
	}
	
	keep_window_open();
}