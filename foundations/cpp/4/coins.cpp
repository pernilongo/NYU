#include <iostream>
using namespace std;

int main()
{
	int dollars, cents;
	cout << "Please enter the amount of money to convert:" << endl;
	cout << "# of dollars: ";
	cin >> dollars;
	cout << "# of cents: ";
	cin >> cents;
	cents += dollars * 100;

	int quarters = cents / 25;
	cents = cents % 25;
	int dimes = cents / 10;
	cents = cents % 10;
	int nickels = cents / 5;
	int pennies = cents % 5;

	cout << "The coins are " << quarters << " quarters, " << dimes << " dimes, " << nickels << " nickels and " << pennies << " pennies" << endl;

	return 0;
}
