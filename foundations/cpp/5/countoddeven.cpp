#include <iostream>
using namespace std;

int main()
{
	int i1, i2, i3, i4;
	cout << "Please enter 4 positive integers, separated by a space: " << endl;
	cin >> i1 >> i2 >> i3 >> i4;

	int odds = i1 % 2 + i2 % 2 + i3 % 2 + i4 % 2;
	if (odds < 2)
		cout << "more evens" << endl;
	else if (odds > 2)
		cout << "more odds" << endl;
	else
		cout << "same number of evens and odds" << endl;

	return 0;
}