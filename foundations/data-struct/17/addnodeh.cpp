#include <string>
#include "cpluspluslabs.h"
using namespace std;

void add_node_head(NODE **data, string firstname, string lastname, string email)
{
	NODE *node = new NODE;
	node->next = *data;
	node->firstname = firstname;
	node->lastname = lastname;
	node->email = email;

	*data = node;
}
