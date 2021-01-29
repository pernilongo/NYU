#include <string>
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
