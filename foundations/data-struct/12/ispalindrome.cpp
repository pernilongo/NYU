#include <iostream>
#include <string>
using namespace std;

bool is_palindrome(string str, int start, int end)
{
	if (end - start <= 1)
		return str[start] == str[end];

	return str[start] == str[end] && is_palindrome(str, start + 1, end - 1);
}

bool is_palindrome(int test)
{
	string str = to_string(test);
	return is_palindrome(str, 0, str.length() - 1);
}
/*
int main()
{
	cout << is_palindrome(1010) << endl;
	cout << is_palindrome(101) << endl;
	return 0;
}
*/