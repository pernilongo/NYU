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
		<< "BMI is: " << bmi;
	if (bmi < 18.5) cout << ", Status is Underweight";
	else if (bmi >= 18.5 && bmi < 24.9) cout << ", Status is Normal";
	else if (bmi >= 24.9 && bmi < 29.9) cout << ", Status is Overweight";
	else cout << ", Status is Obese";
	return 0;
}