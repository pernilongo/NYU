#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	string week_day;
	int time24, duration;

	cout << "Enter the day the call started at: ";
	cin >> week_day;
	cout << "Enter the time the call started at (hhmm): ";
	cin >> time24;
	cout << "Enter the duration of the call (in minutes): ";
	cin >> duration;

	double rate;
	if (tolower(week_day[0]) == 's')
		rate = 0.15;
	else if (800 <= time24 && time24 <= 1800)
		rate = 0.40;
	else
		rate = 0.25;
	double cost = rate * duration;

	cout << std::fixed << std::setprecision(2)
		 << "This call will cost $" << cost << endl;

	return 0;
}