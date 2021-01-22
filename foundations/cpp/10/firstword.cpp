#include <iostream>
using namespace std;

string firstword(string s)
{
	int idx = s.find(' ');
	return idx == -1 ? s : s.substr(0, idx);
}
/*
int main()
{
	cout << firstword("the quick brown fox");
	return 0;
}
*/