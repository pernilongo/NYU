#include <string>
#include "showticket.h"
using namespace std;

#ifndef SPORT_TICKET_H
#define SPORT_TICKET_H

class SportTicket : public ShowTicket
{
private:
	bool beerSold;

public:
	SportTicket(string row, string seat)
		: ShowTicket(row, seat), beerSold(false) {}
	bool beer_sold() { return beerSold; }
	void sell_beer() { beerSold = true; }
	string print_ticket()
	{
		return ShowTicket::print_ticket() + " " + (beerSold ? "beer" : "nobeer");
	}
};

#endif
