#include <string>
using namespace std;

#ifndef CPLUSPLUS_LABS
#define CPLUSPLUS_LABS

class NODE
{
public:
	string firstname;
	string lastname;
	string email;
	NODE *next;
};

void add_node_tail(NODE **data, string firstname, string lastname, string email);
void add_node_head(NODE **data, string firstname, string lastname, string email);
void csv_import2(NODE **data, string filename);

void print(NODE *data);

#endif
