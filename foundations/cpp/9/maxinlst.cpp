#include <iostream>
using namespace std;

int maxinlst(int lst[], int size)
{
	int max = lst[0];
	for (int i = 1; i < size; i++)
		if (lst[i] > max)
			max = lst[i];
	return max;
}
/*
int main()
{
	int lst[] = {-19, -3, 20, -1, 5, -25};
	cout << maxinlst(lst, 6) << endl;

	return 0;
}
*/