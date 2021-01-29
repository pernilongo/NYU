#ifndef STACK_H
#define STACK_H

#define MAX 1000

class Stack
{
public:
	int top;
	int a[MAX]; // Maximum size of Stack

	Stack() : top(-1) {}
	bool push(int x)
	{
		if (top >= MAX - 1)
			return false;
		a[++top] = x;
		return true;
	}

	int pop() { return top >= 0 ? a[top--] : 0; }
	int peek() { return top >= 0 ? a[top] : 0; }
	bool isEmpty() { return top < 0; };
};

#endif
