#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "Please enter a positive integer: ";
	cin >> n;

	int even = 2;
	while (n-- > 0)
	{
		cout << even << endl;
		even += 2;
	}

	return 0;
}