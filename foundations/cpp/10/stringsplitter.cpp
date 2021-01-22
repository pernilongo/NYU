#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	cout << "Enter an odd length string: ";
	getline(cin, str);

	int idx = str.length() / 2;
	cout << "Middle character: " << str[idx] << endl;
	cout << "First half: " << str.substr(0, idx) << endl;
	cout << "Second half: " << str.substr(idx+1, str.length()) << endl;
	return 0;
}