#include <stdio.h>
#include <math.h>
#include "oslabs.h"

typedef struct RCB RCB;
int is_null(const struct RCB rcb);

RCB get_request(int timestamp)
{
	switch (timestamp)
	{
	case 0:
		return (RCB){1, timestamp, 76, 5};
	case 2:
		return (RCB){2, timestamp, 65, 2};
	case 4:
		return (RCB){3, timestamp, 87, 2};
	case 6:
		return (RCB){4, timestamp, 76, 1};
	case 8:
		return (RCB){5, timestamp, 95, 5};
	case 11:
		return (RCB){6, timestamp, 44, 2};
	case 17:
		return (RCB){7, timestamp, 43, 5};
	case 22:
		return (RCB){8, timestamp, 54, 1};
	default:
		return (RCB){0};
	}
}

void calc(const int timestamp, struct RCB *current_request, int *current_cylinder, int *scan_direction)
{
	current_request->execution_starttime = timestamp;
	int k = abs(*current_cylinder - current_request->cylinder);
	double time = 0.5 + current_request->address * 0.1;
	if (k != 0)
		time += 1 + (k - 1) * 0.1;
	current_request->execution_endtime = (current_request->execution_starttime + time);
	*scan_direction = *current_cylinder < current_request->cylinder;
	*current_cylinder = current_request->cylinder;
	printf(" %d, %f (%d%c)", current_request->request_id, current_request->execution_endtime, current_request->cylinder, *scan_direction ? '+' : '-');
}

void test_1()
{
	RCB request_queue[QUEUEMAX] = {0};
	int queue_cnt = 0;
	int current_cylinder = 50;
	RCB current_request = {0};
	int scan_direction = 1;

	printf("(%d%c)\n", current_cylinder, scan_direction ? '+' : '-');
	for (int timestamp = 0; timestamp < 50; timestamp++)
	{
		printf("%d", timestamp);
		RCB new_request = get_request(timestamp);
		if (!is_null(new_request))
		{
			printf(" [%d]", new_request.request_id);
			int is_new = current_request.request_id == 0;
			current_request = handle_request_arrival_look(request_queue, &queue_cnt, current_request, new_request, timestamp);
			if (current_request.request_id == new_request.request_id || is_new)
			{
				printf(" ->");
				calc(timestamp, &current_request, &current_cylinder, &scan_direction);
			}
		}

		if (current_request.execution_endtime <= timestamp * 1.0)
		{
			if (!is_null(current_request))
				printf(" {%d: %d, %f}",
					   current_request.request_id,
					   current_request.execution_starttime - current_request.arrival_timestamp,
					   current_request.execution_endtime - current_request.arrival_timestamp);

			current_request = handle_request_completion_look(request_queue, &queue_cnt, current_cylinder, scan_direction);

			if (!is_null(current_request))
			{
				printf(" =>");
				calc(timestamp, &current_request, &current_cylinder, &scan_direction);
			}
			else
				printf(" IDLE");
		}
		printf("\n");
		//current_cylinder = current_request.cylinder;
	}
}

void test_2()
{
	RCB request_queue[QUEUEMAX] = {
		{1, 0, 45},
		{2, 0, 17},
		{3, 0, 94},
		{4, 0, 64},
		{5, 0, 12},
		{6, 0, 52},
		{7, 0, 3},
		{8, 0, 79},
	};
	int queue_cnt = 8;
	int current_cylinder = 40;
	RCB current_request = {0};
	int scan_direction = 0;

	do
	{
		current_request = handle_request_completion_look(request_queue, &queue_cnt, current_cylinder, scan_direction);
		scan_direction = current_cylinder < current_request.cylinder;
		current_cylinder = current_request.cylinder;
		printf("%d - %d\n", current_request.request_id, current_request.cylinder);
	} while (current_request.request_id != 0);
}

int main(int argc, char **argv)
{
	test_1();
	return 0;
}