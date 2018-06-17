//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 4 Try This page 109

#include "std_lib_facilities.h"

int main()
{
	const double yenToDollar = 101.10;
	const double euroToDollar = 0.89;
	const double poundToDollar = 0.76;
	const double yuanToDollar = 6.63;
	const double kronarToDollar = 8.44;

	double dollar = 1;
	char currency = 'a';

	cout << "Please enter an amount of dollar(s) you want to convert,\nfollowed by the desired conversion currency (yen = y, euro = e, pound = p, yuan = yu, kronar = k): \n";
	cin >> dollar >> currency;

	switch (currency)
	{
	case 'y':
		if (dollar*yenToDollar <= 1)
		{
			cout << dollar << " dollar is " << dollar*yenToDollar << " yen";
		}
		else
		{
			cout << dollar << " dollars are " << dollar*yenToDollar << " yen\n";
		}
		break;
	case 'e':
		if (dollar*euroToDollar <= 1)
		{
			cout << dollar << " dollar is " << dollar*euroToDollar << " euro\n";
		}
		else
		{
			cout << dollar << " dollars are " << dollar*euroToDollar << " euros\n";
		}
		break;
	case 'p':
		if (dollar*poundToDollar <= 1)
		{
			cout << dollar << " dollar is " << dollar*poundToDollar << " pound\n";
		}
		else
		{
			cout << dollar << " dollars are " << dollar*poundToDollar << " pounds\n";
		}
		break;
	case 'yu':
		if (dollar*yuanToDollar <= 1)
		{
			cout << dollar << " dollar is " << dollar*yuanToDollar << " yuan\n";
		}
		else
		{
			cout << dollar << " dollars are " << dollar*yuanToDollar << " yuans\n";
		}
		break;
	case 'k':
		if (dollar*kronarToDollar <= 1)
		{
			cout << dollar << " dollar is " << dollar*kronarToDollar << " kronar\n";
		}
		else
		{
			cout << dollar << " dollars are " << dollar*kronarToDollar << " kronars\n";
		}
		break;
	default:
		cout << "I dont know what " << currency << " for an currency is\n";
		break;
	}

	keep_window_open();
}