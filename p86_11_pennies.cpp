//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 3 Exercise 11

#include "std_lib_facilities.h"

int main()
{
	int oneCentCoins = 0;
	int fiveCentCoins = 0;
	int tenCentCoins = 0;
	int twfiveCentCoins = 0;
	int ffCentCoins = 0;
	int dollars = 0;
	double total = 0;

	cout << "How many 1-Cent-Coins do you have?\n";
	cin >> oneCentCoins;
	cout << "How many 5-Cent-Coins do you have?\n";
	cin >> fiveCentCoins;
	cout << "How many 10-Cent-Coins do you have?\n";
	cin >> tenCentCoins;
	cout << "How many 25-Cent-Coins do you have?\n";
	cin >> twfiveCentCoins;
	cout << "How many 50-Cent-Coins do you have?\n";
	cin >> ffCentCoins;
	cout << "How many 1-Dollar-Coins do you have?\n";
	cin >> dollars;

	total = oneCentCoins*0.01 + fiveCentCoins*0.05 + tenCentCoins*0.10 + twfiveCentCoins*0.25 + ffCentCoins*0.50 + dollars*1.00;

	if (oneCentCoins < 2) cout << "You have " << oneCentCoins << " pennie\n";
	else cout << "You have " << oneCentCoins << " pennies\n";
	if (fiveCentCoins < 2) cout << "You have " << oneCentCoins << " nickle\n";
	else cout << "You have " << fiveCentCoins << " nickles\n";
	if (tenCentCoins < 2) cout << "You have " << oneCentCoins << " dime\n";
	else cout << "You have " << tenCentCoins << " dimes\n";
	if (twfiveCentCoins < 2) cout << "You have " << oneCentCoins << " quarter\n";
	else cout << "You have " << twfiveCentCoins << " quarters\n";
	if (ffCentCoins < 2) cout << "You have " << oneCentCoins << " half dollar\n";
	else cout << "You have " << ffCentCoins << " half dollars\n";
	if (dollars < 2) cout << "You have " << oneCentCoins << " dollar\n";
	else cout << "You have " << dollars << " dollars\n";

	cout << "the value of all your coins is " << total << " Dollar\n";
	keep_window_open();
}