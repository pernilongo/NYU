#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double weight, height;
	cout << "Please enter weight in kilograms: ";
	cin >> weight;
	cout << "Please enter height in meters: ";
	cin >> height;
	double bmi = weight / (height * height);
	cout << std::fixed << std::setprecision(2)
		<< "BMI is: " << bmi << endl;
	return 0;
}