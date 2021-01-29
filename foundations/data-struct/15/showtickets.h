#include <string>
#include <vector>
using namespace std;

#ifndef SHOW_TICKETS_H
#define SHOW_TICKETS_H

class ShowTickets
{
private:
	vector<string> tickets;

	bool find(string row, string seat)
	{
		for (string &st : tickets)
			if (st == (row + "-" + seat))
				return true;
		return false;
	}

public:
	bool is_sold(string row, string seat)
	{
		return find(row, seat);
	}
	void sell_seat(string row, string seat)
	{
		if (find(row, seat))
			return;
		tickets.push_back(row + "-" + seat);
	}
	string print_ticket(string row, string seat)
	{
		bool sold = find(row, seat);
		return row + " " + seat + " " + (sold ? "sold" : "available");
	}
};

#endif
