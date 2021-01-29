#include <string>
using namespace std;

#ifndef SHOW_TICKET_H
#define SHOW_TICKET_H

class ShowTicket
{
private:
	string row;
	string seat;
	bool sold;

public:
	ShowTicket(string row, string seat)
		: row(row), seat(seat), sold(false) {}
	bool is_sold() const { return sold; }
	void sell_seat() { sold = true; }
	string print_ticket() const
	{
		return row + " " + seat + " " + (sold ? "sold" : "available");
	}
};

#endif
