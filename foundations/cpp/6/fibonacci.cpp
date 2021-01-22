#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "Please enter a positive integer greater than 1: ";
	cin >> n;

	int prior = 0, current = 1;
	do
	{
		cout << current << endl;
		current += prior;
		prior = current - prior;
	} while (--n > 0);

	return 0;
}