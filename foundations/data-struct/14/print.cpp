#include <iostream>
using namespace std;

void print(int lst[], int size)
{
	cout << "{";
	for (int i = 0; i < size; i++)
	{
		if (i > 0)
			cout << ", ";
		cout << lst[i];
	}
	cout << "}" << endl;
}
