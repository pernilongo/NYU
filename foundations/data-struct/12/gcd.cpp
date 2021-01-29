#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}
/*
int main()
{
	cout << gcd(15, 5) << endl;
	return 0;
}
*/