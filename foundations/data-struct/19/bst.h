#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

class BST
{
public:
	int data;
	BST *left, *right;

	BST(int data = 0) : data(data), left(nullptr), right(nullptr){};

	void insert(int val, BST *node = nullptr)
	{
		node = node == nullptr ? this : node;
		if (val < node->data)
		{
			if (node->left == nullptr)
				node->left = new BST(val);
			else
				insert(val, node->left);
		}
		else
		{
			if (node->right == nullptr)
				node->right = new BST(val);
			else
				insert(val, node->right);
		}
	}

	BST *nth(BST *node, int *idx, int n)
	{
		if (node != nullptr)
		{
			BST *left = nth(node->left, idx, n);
			if (left != nullptr)
				return left;
			if (++(*idx) == n)
				return node;
			BST *right = nth(node->right, idx, n);
			if (right != nullptr)
				return right;
		}
		return nullptr;
	}

	int nth_node(int n)
	{
		int index = 0;
		BST *node = nth(this, &index, n);
		if (index != n || node == nullptr)
		{
			cout << "Invalid index: " << index << endl;
			return -1;
		}
		return node->data;
	}
};

#endif
