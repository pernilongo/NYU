#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double price1, price2, taxRate;
	char clubCard;
	cout << "Enter price of the first item: ";
	cin >> price1;
	cout << "Enter price of the second item: ";
	cin >> price2;
	cout << "Does customer have a club card? (Y/N): ";
	cin >> clubCard;
	cout << "Enter tax rate, e.g. 5.5 for 5.5% tax: ";
	cin >> taxRate;

	bool club = clubCard == 'Y' || clubCard == 'y';
	double basePrice = price1 + price2;
	double discount = price1 < price2 ? price1 / 2 : price2 / 2;
	double discountPrice = (basePrice - discount) * (club ? 0.9 : 1.0);
	double totalPrice = discountPrice * (1 + taxRate / 100);

	cout << std::fixed << std::setprecision(2)
		 << "Base price = " << basePrice << endl;
	cout << std::fixed << std::setprecision(2)
		 << "Price after discounts = " << discountPrice << endl;
	cout << std::fixed << std::setprecision(2)
		 << "Total price = " << totalPrice << endl;
	return 0;
}