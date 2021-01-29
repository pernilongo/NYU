#include <string>
#include "sportticket.h"
using namespace std;

#ifndef TICKET_SALES_H
#define TICKET_SALES_H

class TicketSales
{
public:
	string print_ticket(ShowTicket *myticket)
	{
		return myticket->print_ticket();
	}
};

#endif
