#include "cpluspluslabs.h"
#include <iostream>
using namespace std;

Node *new_node(int key)
{
	Node *node = new Node();
	node->key = key;
	node->height = 0;
	node->left = node->right = nullptr;
	return node;
}

Node *insertnb(Node *node, int key)
{
	if (node == nullptr)
		return new_node(key);

	node->height++;
	if (key <= node->key)
	{
		if (node->left == nullptr)
			node->left = new_node(key);
		else
			insertnb(node->left, key);
	}
	else
	{
		if (node->right == nullptr)
			node->right = new_node(key);
		else
			insertnb(node->right, key);
	}
	return node;
}

void set_height(Node *node)
{
	int left = node->left == nullptr ? -1 : node->left->height;
	int right = node->right == nullptr ? -1 : node->right->height;
	node->height = left > right ? left + 1 : right + 1;
}

Node *left_rotate(Node *x)
{
	//cout << "left rotate: " << x->key << endl;
	Node *z = x->right;
	x->right = z->left;
	z->left = x;
	set_height(x);
	set_height(z);
	return z;
}

Node *right_rotate(Node *x)
{
	//cout << "right rotate: " << x->key << endl;
	Node *z = x->left;
	x->left = z->right;
	z->right = x;
	set_height(x);
	set_height(z);
	return z;
}

int get_balance(Node *x)
{
	if (x == nullptr)
		return 0;
	int left = x->left == nullptr ? -1 : x->left->height;
	int right = x->right == nullptr ? -1 : x->right->height;
	return left - right;
}

Node *rebalance(Node *node)
{
	int balance = get_balance(node);
	if (balance < -1) // righ heavy
	{
		int child = get_balance(node->right);
		if (child > 0)
			node->right = right_rotate(node->right);
		return left_rotate(node);
	}
	if (balance > 1) // left heavy
	{
		int child = get_balance(node->left);
		if (child < 0)
			node->left = left_rotate(node->left);
		return right_rotate(node);
	}
	return node;
}

Node *insert(Node *node, int key)
{
	if (node == nullptr)
		return new_node(key);

	node->height++;
	if (key <= node->key)
	{
		if (node->left == nullptr)
			node->left = new_node(key);
		else
			node->left = insert(node->left, key);
	}
	else
	{
		if (node->right == nullptr)
			node->right = new_node(key);
		else
			node->right = insert(node->right, key);
	}
	if (node->height > 1)
		return rebalance(node);
	return node;
}
