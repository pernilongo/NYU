#include <string>
using namespace std;

void csv_export(string data[][10], int records, int columns, string filename);
void csv_import(string data[][10], int columns, int *records, string filename);

void test1()
{
	string data[][10] = {
		{"aspen", "olmsted", "aspen@pleasedonotemail.com"},
		{"sally", "jones", "sally@gmail.com"},
		{"fred", "smith", "fsmith@aol.com"}};

	csv_export(data, 3, 3, "customers.csv");
}

void test2()
{
	string data[10][10];
	int records;
	csv_import(data, 3, &records, "customers.csv");
}

int main()
{
	test2();
	return 0;
}
