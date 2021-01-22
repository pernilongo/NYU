#include <iostream>
using namespace std;

int main()
{
	int quarters, dimes, nickels, pennies;
	cout << "Please enter the number of coins:" << endl;
	cout << "# of quarters: ";
	cin >> quarters;
	cout << "# of dimes: ";
	cin >> dimes;
	cout << "# of nickels: ";
	cin >> nickels;
	cout << "# of pennies: ";
	cin >> pennies;
	int cents = quarters * 25 + dimes * 10 + nickels * 5 + pennies;
	cout << "The total is " << cents / 100 << " dollars and " << cents % 100 << " cents" << endl;
	return 0;
}