#include <iostream>
using namespace std;

int binary_search(int search_value, int lst[], int elements)
{
	int start = 0;
	int end = elements - 1;
	int cnt = 0;
	while (start <= end)
	{
		cnt++;
		int mid = (start + end) / 2;
		int val = lst[mid];
		if (val == search_value)
			break;
		if (val < search_value)
			start = mid + 1;
		else
			end = mid - 1;
	}
	return cnt;
}
/*
int main()
{
	int lst[] = {0, 1, 2, 18, 19, 20, 25};
	cout << binary_search(20, lst, 7) << endl;
	return 0;
}
*/