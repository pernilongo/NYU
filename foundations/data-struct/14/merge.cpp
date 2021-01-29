
void merge(int arr[], int left, int middle, int right)
{
	int *tmp = new int[right - left + 1];
	int idx = 0;
	int l = left;
	int r = middle + 1;
	while (l <= middle && r <= right)
		tmp[idx++] = arr[l] < arr[r] ? arr[l++] : arr[r++];
	while (l <= middle)
		tmp[idx++] = arr[l++];
	while (r <= right)
		tmp[idx++] = arr[r++];

	idx = 0;
	while (left <= right)
		arr[left++] = tmp[idx++];

	delete [] tmp;
}
