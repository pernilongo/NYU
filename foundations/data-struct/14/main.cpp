#include <iostream>
#include "cpluspluslabs.h"
using namespace std;

int main()
{
	int lst[] = {25, 20, 19, 18, 2, 1, 0};
	print(lst, 6);
	//swap(&lst[0], &lst[1]);
	selection_sort(lst, 6);
	print(lst, 6);

	int lst2[] = {0, 2, 1, 18, 20};
	merge(lst2, 0, 1, 3);
	print(lst2, 5);

	int lst3[] = {19, 2, 20, 1, 0, 18};
	merge_sort(lst3,0,5);
	print(lst3, 5);

	return 0;
}
