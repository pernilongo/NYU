#include <limits.h>
#include "oslabs.h"

int is_null(struct PCB pcb)
{
	return pcb.process_id == 0 &&
		   pcb.arrival_timestamp == 0 &&
		   pcb.total_bursttime == 0 &&
		   pcb.execution_starttime == 0 &&
		   pcb.execution_endtime == 0 &&
		   pcb.remaining_bursttime == 0 &&
		   pcb.process_priority == 0;
}

struct PCB handle_process_arrival_pp(struct PCB ready_queue[QUEUEMAX], int *queue_cnt, struct PCB current_process, struct PCB new_process, int timestamp)
{
	// no process running
	if (is_null(current_process))
	{
		new_process.execution_starttime = timestamp;
		new_process.execution_endtime = timestamp + new_process.total_bursttime - 1;
		new_process.remaining_bursttime = new_process.total_bursttime;
		return new_process;
	}

	// new process has same or lower priority than the current process
	if (new_process.process_priority >= current_process.process_priority)
	{
		new_process.execution_starttime = -1;
		new_process.execution_endtime = 0;
		new_process.remaining_bursttime = new_process.total_bursttime;
		ready_queue[(*queue_cnt)++] = new_process;
		return current_process;
	}

	// new process has higher priority than the current process
	current_process.remaining_bursttime = current_process.execution_endtime - timestamp + 1;
	current_process.execution_endtime = 0;
	ready_queue[(*queue_cnt)++] = current_process;
	new_process.execution_starttime = timestamp;
	new_process.execution_endtime = timestamp + new_process.total_bursttime - 1;
	new_process.remaining_bursttime = new_process.total_bursttime;
	return new_process;
}

struct PCB handle_process_completion_pp(struct PCB ready_queue[QUEUEMAX], int *queue_cnt, int timestamp)
{
	PCB new_process = {0};

	if (*queue_cnt == 0)
		return new_process;

	// find highest priority
	int value = INT_MAX;
	int index = -1;
	for (int i = 0; i < *queue_cnt; i++)
	{
		if (ready_queue[i].process_priority < value)
		{
			value = ready_queue[i].process_priority;
			index = i;
		}
	}
	new_process = ready_queue[index];

	for (int i = index + 1; i < *queue_cnt; i++)
	{
		ready_queue[i - 1] = ready_queue[i];
	}
	ready_queue[--(*queue_cnt)] = (PCB){0};
	if (new_process.execution_starttime == -1)
		new_process.execution_starttime = timestamp + 1;
	new_process.execution_endtime = timestamp + new_process.remaining_bursttime;
	return new_process;
}

struct PCB handle_process_arrival_srtp(struct PCB ready_queue[QUEUEMAX], int *queue_cnt, struct PCB current_process, struct PCB new_process, int timestamp)
{
	// no process running
	if (is_null(current_process))
	{
		new_process.execution_starttime = timestamp;
		new_process.execution_endtime = timestamp + new_process.total_bursttime - 1;
		new_process.remaining_bursttime = new_process.total_bursttime;
		return new_process;
	}

	// new process has longer burst time than the current process
	//if (new_process.remaining_bursttime >= current_process.total_bursttime)
	//if (new_process.total_bursttime >= current_process.total_bursttime)
	{
		new_process.execution_starttime = -1;
		new_process.execution_endtime = 0;
		new_process.remaining_bursttime = new_process.total_bursttime;
		ready_queue[(*queue_cnt)++] = new_process;
		return current_process;
	}

	// new process has shorter burst time than the current process
	current_process.remaining_bursttime = current_process.execution_endtime - timestamp + 1;
	current_process.execution_endtime = 0;
	ready_queue[(*queue_cnt)++] = current_process;
	new_process.execution_starttime = timestamp;
	new_process.execution_endtime = timestamp + new_process.total_bursttime - 1;
	new_process.remaining_bursttime = new_process.total_bursttime;
	return new_process;
}

struct PCB handle_process_completion_srtp(struct PCB ready_queue[QUEUEMAX], int *queue_cnt, int timestamp)
{
	PCB new_process = {0};

	if (*queue_cnt == 0)
		return new_process;

	// find highest priority
	int value = INT_MAX;
	int index = -1;
	for (int i = 0; i < *queue_cnt; i++)
	{
		if (ready_queue[i].total_bursttime < value)
		{
			value = ready_queue[i].total_bursttime;
			index = i;
		}
	}
	new_process = ready_queue[index];

	for (int i = index + 1; i < *queue_cnt; i++)
	{
		ready_queue[i - 1] = ready_queue[i];
	}
	ready_queue[--(*queue_cnt)] = (PCB){0};
	if (new_process.execution_starttime == -1)
		new_process.execution_starttime = timestamp + 1;
	new_process.execution_endtime = timestamp + new_process.remaining_bursttime;
	return new_process;
}

// FCFS with large QUANTUM
struct PCB handle_process_arrival_rr(struct PCB ready_queue[QUEUEMAX], int *queue_cnt, struct PCB current_process, struct PCB new_process, int timestamp, int time_quantum)
{
	// no process running
	if (is_null(current_process))
	{
		new_process.execution_starttime = timestamp;
		new_process.execution_endtime = timestamp - 1 + MIN(time_quantum, new_process.total_bursttime);
		new_process.remaining_bursttime = new_process.total_bursttime;
		return new_process;
	}

	new_process.execution_starttime = -1;
	new_process.execution_endtime = 0;
	new_process.remaining_bursttime = new_process.total_bursttime;
	ready_queue[(*queue_cnt)++] = new_process;
	return current_process;
}

// FCFS with large QUANTUM
struct PCB handle_process_completion_rr(struct PCB ready_queue[QUEUEMAX], int *queue_cnt, int timestamp, int time_quantum)
{
	PCB new_process = {0};

	if (*queue_cnt == 0)
		return new_process;

	new_process = ready_queue[0];

	for (int i = 1; i < *queue_cnt; i++)
	{
		ready_queue[i - 1] = ready_queue[i];
	}
	ready_queue[--(*queue_cnt)] = (PCB){0};
	if (new_process.execution_starttime == -1)
		new_process.execution_starttime = timestamp + 1;
	new_process.execution_endtime = timestamp + MIN(time_quantum, new_process.remaining_bursttime);
	return new_process;
}
