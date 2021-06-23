#include <stdio.h>
#include "oslabs.h"

struct PCB get_process(const struct PCB processes[QUEUEMAX], int timestamp)
{
	struct PCB new_process = {0};
	for (int i = 1; i < QUEUEMAX; i++)
	{
		if (processes[i].arrival_timestamp == timestamp)
		{
			return processes[i];
		}
	}
	return new_process;
}

void print_process(const struct PCB p[QUEUEMAX])
{
	int turnaround_total = 0;
	int waittime_total = 0;
	int turnaround_max = 0;
	int waittime_max = 0;
	int count = 0;
	printf("\nPID\tAT\tTBT\tEST\tEET\tRBT\t PP\twait\tturnaround\n");
	for (int i = 1; i < QUEUEMAX; i++)
	{
		if (p[i].process_id == 0)
			continue;
		count++;
		int turnaround = p[i].execution_endtime - p[i].arrival_timestamp + 1;
		turnaround_total += turnaround;
		turnaround_max = turnaround > turnaround_max ? turnaround : turnaround_max;
		int waittime = turnaround - p[i].total_bursttime;
		waittime_total += waittime;
		waittime_max = waittime > waittime_max ? waittime : waittime_max;
		printf("%d\t", p[i].process_id);
		printf("%d\t", p[i].arrival_timestamp);
		printf("%d\t", p[i].total_bursttime);
		printf("%d\t", p[i].execution_starttime);
		printf("%d\t", p[i].execution_endtime);
		printf("%d\t", p[i].remaining_bursttime);
		printf("%d\t", p[i].process_priority);
		printf("%d\t", waittime);
		printf("%d\n", turnaround);
	}
	printf("Wait (avg): %f, (max): %d\n", 1.0 * waittime_total / count, waittime_max);
	printf("Turnaround (avg): %f, (max): %d\n", 1.0 * turnaround_total / count, turnaround_max);
}

void handle_process()
{
	struct PCB processes[QUEUEMAX] = {
		(PCB){0},
		(PCB){1, 0, 5, 0, 0, 0, 7},
		(PCB){2, 2, 7, 0, 0, 0, 6},
		(PCB){3, 4, 3, 0, 0, 0, 5},
		(PCB){4, 6, 9, 0, 0, 0, 9},
		(PCB){5, 8, 1, 0, 0, 0, 8},
		(PCB){6, 10, 5, 0, 0, 0, 4},
	};

	struct PCB ready_queue[QUEUEMAX] = {0};
	struct PCB current_process = {0};
	struct PCB new_process = {0};
	struct PCB result;
	int queue_cnt = 0;
	int timestamp = 0;
	const int QUANTUM = 1000;

	printf("time,\tnew,\tcur, END\n");
	do
	{
		new_process = get_process(processes, timestamp);
		printf("%d", timestamp);
		if (!is_null(new_process))
		{
			printf("\t %d", new_process.process_id);
			current_process = handle_process_arrival_rr(
				ready_queue, &queue_cnt, current_process, new_process, timestamp, QUANTUM);
		}
		else
		{
			printf("\t");
		}

		// run process
		printf("\t (%d)", current_process.process_id);
		current_process.remaining_bursttime--;

		if (current_process.remaining_bursttime == 0)
		{
			processes[current_process.process_id] = current_process;
			printf(" *");
			current_process = handle_process_completion_rr(
				ready_queue, &queue_cnt, timestamp, QUANTUM);
		}
		// else if (current_process.execution_endtime <= timestamp)
		// {
		// 	current_process.execution_endtime = 0;
		// 	ready_queue[queue_cnt++] = current_process;
		// 	printf(" ^");
		// 	current_process = handle_process_completion_srpt(
		// 		ready_queue, &queue_cnt, timestamp);
		// }

		printf("\n");
		timestamp++;
	} while (!is_null(current_process));
	print_process(processes);
}

int main(int argc, char **argv)
{
	handle_process();

	return 0;
}