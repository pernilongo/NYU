//#include <iostream>
//using namespace std;

float avgoflst(int lst[], int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += lst[i];
		//cout << lst[i] << ", ";
	}
	float avg = (float)sum / (float)size;
	//cout << "-->" << sum << "/" << size << "=" << avg << ";";

	return avg;
}
/*
int main()
{
	int lst[] = {1269, 1155, 1915, 1987, 730};
	cout << avgoflst(lst, 5) << endl;

	return 0;
}
*/