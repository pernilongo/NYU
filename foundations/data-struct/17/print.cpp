#include <string>
#include <iostream>
#include "cpluspluslabs.h"
using namespace std;

void print(NODE *data)
{
	if (data == nullptr)
	{
		cout << "<NULL>" << endl;
	}
	else
	{
		NODE *node = data;
		do
		{
			cout << "{"
				 << node->firstname << ", "
				 << node->lastname << ", "
				 << node->email << "}" << endl;

			node = node->next;
		} while (node != nullptr);
	}
}
