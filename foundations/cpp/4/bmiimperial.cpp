#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double weight, height;
	cout << "Please enter weight in pounds: ";
	cin >> weight;
	cout << "Please enter height in inches: ";
	cin >> height;
	weight *= 0.453592;
	height *= 0.0254;
	double bmi = weight / (height * height);
	cout << std::fixed << std::setprecision(2)
		<< "BMI is: " << bmi << endl;
	return 0;
}