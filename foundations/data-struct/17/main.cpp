#include <iostream>
#include "cpluspluslabs.h"
using namespace std;

void test1()
{
	NODE *data = nullptr;
	add_node_tail(&data, "aspen", "olmsted", "aspeno@aol.com");
	add_node_tail(&data, "Juan", "Rovirosa", "jrr9511@nyu.edu");
	print(data);
}

void test2()
{
	NODE *data = nullptr;
	add_node_head(&data, "aspen", "olmsted", "aspeno@aol.com");
	add_node_head(&data, "Juan", "Rovirosa", "jrr9511@nyu.edu");
	print(data);
}

void test3()
{
	NODE *data = nullptr;
	csv_import2(&data, "customers.csv");
	print(data);
}

int main()
{
	test3();
	return 0;
}
