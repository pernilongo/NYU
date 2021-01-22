#include <iostream>
using namespace std;

int main()
{
	char ch;
	cout << "Enter a character: ";
	cin >> ch;

	if (islower(ch))
		cout << ch << " is a lower case letter." << endl;
	else if (isupper(ch))
		cout << ch << " is an upper case letter." << endl;
	else if (isdigit(ch))
		cout << ch << " is a digit." << endl;
	else
		cout << ch << " is a non-alphanumeric character." << endl;
	return 0;
}