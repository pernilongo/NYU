#include "cpluspluslabs.h"

void selection_sort(int arr[], int elements)
{
	int start = 0;
	int end = elements - 1;
	while (start < end)
	{
		int minIdx = start + 1;
		int maxIdx = minIdx;
		int min = arr[minIdx];
		int max = min;
		for (int i = start + 1; i <= end; i++)
		{
			if (arr[i] < min)
			{
				minIdx = i;
				min = arr[i];
			}
			if (arr[i] > max)
			{
				maxIdx = i;
				max = arr[i];
			}
		}
		if (arr[start] > min)
		{
			swap(&arr[start], &arr[minIdx]);
		}
		if (arr[end] < max)
		{
			swap(&arr[end], &arr[maxIdx]);
		}
		//print(arr, elements);
		start++;
		end--;
	}
}