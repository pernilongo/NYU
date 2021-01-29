#ifndef QUEUE_H
#define QUEUE_H

#define MAX 1000

class Queue
{
public:
	int rear_value;
	int a[MAX]; // Maximum size of Queue

	Queue() : rear_value(-1) {}

	bool enqueue(int x)
	{
		if (rear_value >= MAX - 1)
			return false;
		a[++rear_value] = x;
		return true;
	}
	int dequeue()
	{
		if (rear_value < 0)
			return 0;
		int value = a[0];
		for (int i = 1; i <= rear_value; i++)
			a[i - 1] = a[i];
		rear_value--;
		return value;
	};
	int front() { return rear_value >= 0 ? a[rear_value] : 0; };
	int rear() { return rear_value >= 0 ? a[0] : 0; };
};

#endif
