#include <iostream>
using namespace std;

string remainingwords(string s)
{
	int idx = s.find(' ');
	return idx == -1 ? s : s.substr(idx+1);
}
/*
int main()
{
	cout << remainingwords("the quick brown fox") << endl;
	return 0;
}
*/