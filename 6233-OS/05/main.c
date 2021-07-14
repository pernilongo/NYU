#include <stdio.h>
#include "oslabs.h"

typedef struct PTE PTE;

void access_fifo_0()
{
	PTE page_table[TABLEMAX] = {
		{0, -1, -1, -1, -1},
		{0, -1, -1, -1, -1},
		{1, 10, 3, 3, 1},
		{0, -1, -1, -1, -1},
		{0, -1, -1, -1, -1},
		{1, 20, 2, 4, 2},
		{0, -1, -1, -1, -1},
		{1, 30, 1, 1, 1},
	};
	int table_cnt = 8;
	int page_number = 0;
	int frame_pool[POOLMAX] = {0};
	int frame_cnt = 0;
	int current_timestamp = 12;

	int frame_number = process_page_access_fifo(
		page_table,
		&table_cnt,
		page_number,
		frame_pool,
		&frame_cnt,
		current_timestamp);
	printf("frame_number: %d; VALID: %d\n", frame_number, frame_number == 30);
}

void access_fifo_1()
{
	PTE page_table[TABLEMAX] = {
		{0, -1, -1, -1, -1},
		{0, -1, -1, -1, -1},
		{1, 10, 3, 3, 1},
		{0, -1, -1, -1, -1},
		{0, -1, -1, -1, -1},
		{1, 20, 2, 4, 2},
		{0, -1, -1, -1, -1},
		{1, 30, 1, 1, 1},
	};
	int table_cnt = 8;
	int page_number = 0;
	int frame_pool[POOLMAX] = {0};
	int frame_cnt = 0;
	int current_timestamp = 12;

	int frame_number = process_page_access_fifo(
		page_table,
		&table_cnt,
		page_number,
		frame_pool,
		&frame_cnt,
		current_timestamp);
	printf("frame_number: %d; VALID: %d\n", frame_number, frame_number == 30);
}

void access_fifo_2()
{
	PTE page_table[TABLEMAX] = {
		{0, -1, -1, -1, -1},
		{0, -1, -1, -1, -1},
		{1, 10, 3, 3, 1},
		{0, -1, -1, -1, -1},
		{0, -1, -1, -1, -1},
		{1, 20, 2, 4, 2},
		{0, -1, -1, -1, -1},
		{1, 30, 1, 1, 1},
	};
	int table_cnt = 8;
	int page_number = 2;
	int frame_pool[POOLMAX] = {0};
	int frame_cnt = 0;
	int current_timestamp = 14;

	int frame_number = process_page_access_fifo(
		page_table,
		&table_cnt,
		page_number,
		frame_pool,
		&frame_cnt,
		current_timestamp);
	printf("frame_number: %d; VALID: %d\n", frame_number, frame_number == 10);
}

void access_fifo_3()
{
	PTE page_table[TABLEMAX] = {
		{0, -1, -1, -1, -1},
		{0, -1, -1, -1, -1},
		{0, -1, -1, -1, -1},
		{0, -1, -1, -1, -1},
		{0, -1, -1, -1, -1},
		{1, 20, 2, 4, 2},
		{0, -1, -1, -1, -1},
		{1, 30, 1, 1, 1},
	};
	int table_cnt = 8;
	int page_number = 3;
	int frame_pool[POOLMAX] = {0};
	int frame_cnt = 0;
	frame_pool[frame_cnt++] = 10;
	int current_timestamp = 15;

	int frame_number = process_page_access_fifo(
		page_table,
		&table_cnt,
		page_number,
		frame_pool,
		&frame_cnt,
		current_timestamp);
	printf("frame_number: %d; VALID: %d\n", frame_number, frame_number == 10);
}

void access_fifo_4()
{
	PTE page_table[TABLEMAX] = {
		{0, -1, -1, -1, -1},
		{0, -1, -1, -1, -1},
		{0, -1, -1, -1, -1},
		{1, 10, 15, 15, 1},
		{0, -1, -1, -1, -1},
		{1, 20, 12, 16, 2},
		{0, -1, -1, -1, -1},
		{1, 30, 14, 14, 1},
	};
	int table_cnt = 8;
	int page_number = 2;
	int frame_pool[POOLMAX] = {0};
	int frame_cnt = 0;
	int current_timestamp = 17;

	int frame_number = process_page_access_fifo(
		page_table,
		&table_cnt,
		page_number,
		frame_pool,
		&frame_cnt,
		current_timestamp);
	printf("frame_number: %d; VALID: %d\n", frame_number, frame_number == 20);
}

void count_fifo_1()
{
	PTE page_table[TABLEMAX] = {
		{0, -1, -1, -1, -1},
		{0, -1, -1, -1, -1},
		{0, -1, -1, -1, -1},
		{0, -1, -1, -1, -1},
		{0, -1, -1, -1, -1},
		{0, -1, -1, -1, -1},
		{0, -1, -1, -1, -1},
		{0, -1, -1, -1, -1},
	};
	int table_cnt = 8;
	int reference_string[REFERENCEMAX] = {0, 3, 2, 6, 3, 4, 5, 2, 4, 5, 6};
	int reference_cnt = 11;
	int frame_pool[POOLMAX] = {0, 1, 2};
	int frame_cnt = 3;
	int faults = count_page_faults_fifo(page_table, table_cnt, reference_string, reference_cnt, frame_pool, frame_cnt);
	printf("faults: %d; VALID: %d\n", faults, faults == 8);
}

void count_fifo_2()
{
	PTE page_table[TABLEMAX] = {
		{0, -1, -1, -1, -1},
		{0, -1, -1, -1, -1},
		{1, 10, 3, 3, 1},
		{0, -1, -1, -1, -1},
		{0, -1, -1, -1, -1},
		{1, 20, 2, 4, 2},
		{0, -1, -1, -1, -1},
		{1, 30, 1, 1, 1},
	};
	int table_cnt = 8;
	int reference_string[REFERENCEMAX] = {2, 5, 0, 7, 4, 2, 3, 5, 1, 2, 6, 0};
	int reference_cnt = 12;
	int frame_pool[POOLMAX] = {0};
	int frame_cnt = 0;
	int faults = count_page_faults_fifo(page_table, table_cnt, reference_string, reference_cnt, frame_pool, frame_cnt);
	printf("faults: %d; VALID: %d\n", faults, faults == 10);
}

void count_lfu_1()
{
	PTE page_table[TABLEMAX] = {
		{0, -1, -1, -1, -1},
		{0, -1, -1, -1, -1},
		{0, -1, -1, -1, -1},
		{0, -1, -1, -1, -1},
		{0, -1, -1, -1, -1},
		{0, -1, -1, -1, -1},
		{0, -1, -1, -1, -1},
		{0, -1, -1, -1, -1},
	};
	int table_cnt = 8;
	int reference_string[REFERENCEMAX] = {0, 3, 2, 6, 3, 4, 5, 2, 6, 4, 5};
	int reference_cnt = 11;
	int frame_pool[POOLMAX] = {0, 1, 2};
	int frame_cnt = 3;
	int faults = count_page_faults_lfu(page_table, table_cnt, reference_string, reference_cnt, frame_pool, frame_cnt);
	printf("faults: %d; VALID: %d\n", faults, faults == 10);
}

void count_lfu_2()
{
	PTE page_table[TABLEMAX] = {
		{0, -1, -1, -1, -1},
		{0, -1, -1, -1, -1},
		{1, 10, 3, 3, 1},
		{0, -1, -1, -1, -1},
		{0, -1, -1, -1, -1},
		{1, 20, 2, 4, 2},
		{0, -1, -1, -1, -1},
		{1, 30, 1, 1, 1},
	};
	int table_cnt = 8;
	int reference_string[REFERENCEMAX] = {2, 5, 0, 2, 5, 2, 3, 5, 1, 2, 6, 0};
	int reference_cnt = 12;
	int frame_pool[POOLMAX] = {0};
	int frame_cnt = 0;
	int faults = count_page_faults_lfu(page_table, table_cnt, reference_string, reference_cnt, frame_pool, frame_cnt);
	printf("faults: %d; VALID: %d\n", faults, faults == 5);
}

int main(int argc, char **argv)
{
	access_fifo_0();
	access_fifo_1();
	access_fifo_2();
	access_fifo_3();
	access_fifo_4();
	printf("\n");
	count_fifo_1();
	count_fifo_2();
	printf("\n");
	count_lfu_1();
	count_lfu_2();
	return 0;
}