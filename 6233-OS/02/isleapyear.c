#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
	int year = atoi(argv[1]);
	bool isLeap = year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
	printf("%i was %s leap year\n", year, isLeap ? "a" : "not a");
	return 0;
}