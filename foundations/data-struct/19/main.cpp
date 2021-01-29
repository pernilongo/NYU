#include <iostream>
#include "bst.h"
#include "cpluspluslabs.h"
using namespace std;

void test1()
{
	BST mytree0;
	BST mytree(10);
	mytree.insert(20);
}

void printInOrder(BST *node, int *idx)
{
	if (node != nullptr)
	{
		printInOrder(node->left, idx);
		cout << ++(*idx) << ":" << node->data << ", ";
		printInOrder(node->right, idx);
	}
}

void test2()
{
	BST node(10);
	cout << endl
		 << node.nth_node(1) << endl;
	node.insert(20);
	node.insert(30);
	node.insert(1);
	node.insert(2);
	int index = 0;
	printInOrder(&node, &index);
	cout << endl
		 << node.nth_node(0) << endl;
}

void test3()
{
	Node *root = new_node(10);
}

void test4()
{
	Node *root = insertnb(NULL, 10);
	root = insertnb(root, 20);
	root = insertnb(root, 30);
	root = insertnb(root, 1);
}

void test5()
{
	Node *root = insertnb(NULL, 10);
	root = insertnb(root, 20);
	root = insertnb(root, 30);
	root = left_rotate(root);
}

void test6()
{
	Node *root = insertnb(NULL, 30);
	root = insertnb(root, 20);
	root = insertnb(root, 10);
	root = right_rotate(root);
}

void test7()
{
	Node *root = insertnb(NULL, 30);
	root = insertnb(root, 20);
	root = insertnb(root, 10);
	cout << get_balance(root) << endl;
}

void test8()
{
	Node *root = insert(NULL, 10);
	root = insert(root, 20);
	root = insert(root, 30);
	root = insert(root, 40);
	root = insert(root, 50);
	root = insert(root, 25);
}

int main()
{
	test8();
	return 0;
}
