#include <iostream>
using namespace std;

bool isleapyear(int year)
{
	return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}
/*
int main(int argc, char *argv[])
{
	int mybirthyear = 2000;
	if (isleapyear(mybirthyear))
	{
		printf("Year %i was a leap year\n", mybirthyear);
	}
	return 0;
}
*/