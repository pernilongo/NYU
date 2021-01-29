#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "cpluspluslabs.h"
using namespace std;

void add_node_tail(NODE **data, string firstname, string lastname, string email)
{
	NODE *node = new NODE;
	node->next = nullptr;
	node->firstname = firstname;
	node->lastname = lastname;
	node->email = email;

	if (*data == nullptr)
	{
		*data = node;
	}
	else
	{
		NODE *tmp = *data;
		while (tmp->next != nullptr)
			tmp = tmp->next;
		tmp->next = node;
	}
}

void csv_import2(NODE **data, string filename)
{
	string line;
	ifstream fin(filename);
	while (getline(fin, line))
	{
		int j = 0;
		string firstname, lastname, email;
		istringstream tokenStream(line);

		getline(tokenStream, firstname, ',');
		getline(tokenStream, lastname, ',');
		getline(tokenStream, email, ',');

		add_node_tail(data, firstname, lastname, email);
	}
	fin.close();
}
