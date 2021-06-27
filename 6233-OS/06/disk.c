#include <limits.h>
#include <math.h>
#include "oslabs.h"

typedef struct RCB RCB;

int is_null(const struct RCB rcb)
{
	return rcb.request_id == 0 &&
		   rcb.arrival_timestamp == 0 &&
		   rcb.cylinder == 0 &&
		   rcb.address == 0 &&
		   rcb.process_id == 0;
}

void srink(struct RCB request_queue[QUEUEMAX], int *queue_cnt, int index)
{
	for (int i = index; i < *queue_cnt; i++)
	{
		request_queue[i - 1] = request_queue[i];
	}
	request_queue[--(*queue_cnt)] = (RCB){0};
}

struct RCB handle_request_arrival_fcfs(struct RCB request_queue[QUEUEMAX], int *queue_cnt, struct RCB current_request, struct RCB new_request, int timestamp)
{
	if (is_null(current_request))
		return new_request;

	request_queue[(*queue_cnt)++] = new_request;
	return current_request;
}

struct RCB handle_request_completion_fcfs(struct RCB request_queue[QUEUEMAX], int *queue_cnt)
{
	if (*queue_cnt == 0)
		return (RCB){0};

	const struct RCB rcb = request_queue[0];
	srink(request_queue, queue_cnt, 1);
	return rcb;
}

struct RCB handle_request_arrival_sstf(struct RCB request_queue[QUEUEMAX], int *queue_cnt, struct RCB current_request, struct RCB new_request, int timestamp)
{
	if (is_null(current_request))
		return new_request;

	request_queue[(*queue_cnt)++] = new_request;
	return current_request;
}

struct RCB handle_request_completion_sstf(struct RCB request_queue[QUEUEMAX], int *queue_cnt, int current_cylinder)
{
	if (*queue_cnt == 0)
		return (RCB){0};

	int distance = INT_MAX;
	int index = -1;
	for (int i = 0; i < *queue_cnt; i++)
	{
		if (abs(request_queue[i].cylinder - current_cylinder) < distance)
		{
			distance = abs(request_queue[i].cylinder - current_cylinder);
			index = i;
		}
	}

	const struct RCB rcb = request_queue[index];
	srink(request_queue, queue_cnt, index + 1);
	return rcb;
}

struct RCB handle_request_arrival_look(struct RCB request_queue[QUEUEMAX], int *queue_cnt, struct RCB current_request, struct RCB new_request, int timestamp)
{
	if (is_null(current_request))
		return new_request;

	request_queue[(*queue_cnt)++] = new_request;
	return current_request;
}

struct RCB handle_request_completion_look(struct RCB request_queue[QUEUEMAX], int *queue_cnt, int current_cylinder, int scan_direction)
{
	if (*queue_cnt == 0)
		return (RCB){0};

	int min_cylinder = request_queue[0].cylinder - current_cylinder;
	int arrival_timestamp = request_queue[0].arrival_timestamp;
	int index = 0;
	if (scan_direction == 0)
		scan_direction = -1;

	for (int i = 1; i < *queue_cnt; i++)
	{
		// if (min_cylinder == 0) break;
		int distance = (request_queue[i].cylinder - current_cylinder);
		if ((distance * min_cylinder) >= 0) // same direction
		{
			if (abs(distance) < abs(min_cylinder) || (abs(distance) == abs(min_cylinder) && request_queue[i].arrival_timestamp < arrival_timestamp)) // get shorter
			{
				min_cylinder = distance;
				arrival_timestamp = request_queue[i].arrival_timestamp;
				index = i;
			}
		}
		else // different direction
		{
			if ((scan_direction * min_cylinder) < 0) // get same direction
			{
				min_cylinder = distance;
				index = i;
			}
		}
	}

	const struct RCB rcb = request_queue[index];
	srink(request_queue, queue_cnt, index + 1);
	return rcb;
}
