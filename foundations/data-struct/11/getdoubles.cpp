#include <iostream>
using namespace std;

double *getDoubles(int numDoubles)
{
	double *arr = new double[numDoubles];
	for (int i = 0; i < numDoubles; i++)
		arr[i] = (i + 1.0) / 3;
	return arr;
}
/*
int main()
{
	double *arr = getDoubles(4);

	for (int i = 0; i < 4; i++)
		cout << arr[i] << endl;

	return 0;
}
*/