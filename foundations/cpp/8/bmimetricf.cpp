#include <iostream>
#include <iomanip>
using namespace std;

float bmimetricf(int weight, float height)
{
	return weight / (height * height);
}
/*
int main()
{
	int weight = 50;
	float height = 1.58;
	printf("BMI is: %3.2f\n", bmimetricf(weight, height));

	return 0;
}
*/