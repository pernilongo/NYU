#include <iostream>
#include <cmath>
using namespace std;

int maxabsinlst(int lst[], int size)
{
	int max = abs(lst[0]);
	for (int i = 1; i < size; i++)
		if (abs(lst[i]) > max)
			max = abs(lst[i]);
	return max;
}
/*
int main()
{
	int lst[] = {-19, -3, 20, -1, 5, -25};
	cout << maxabsinlst(lst, 6) << endl;

	return 0;
}
*/