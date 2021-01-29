#include <iostream>
#include "showticket.h"
#include "showtickets.h"
#include "sportticket.h"
#include "ticketsales.h"
using namespace std;

void test1()
{
	ShowTicket myticket1("AA", "101");
	ShowTicket myticket2("AA", "102");

	if (!myticket1.is_sold())
		myticket1.sell_seat();
	cout << myticket1.print_ticket() << endl;
	cout << myticket2.print_ticket() << endl;
}

void test2()
{
	ShowTickets myticket;

	if (!myticket.is_sold("AA", "101"))
		myticket.sell_seat("AA", "101");
	cout << myticket.print_ticket("AA", "101") << endl;
	cout << myticket.print_ticket("AA", "102") << endl;
}

void test3()
{
	SportTicket myticket1("AA", "101");
	SportTicket myticket2("AA", "102");

	myticket1.sell_seat();
	myticket2.sell_seat();
	myticket2.sell_beer();
	cout << myticket1.print_ticket() << endl;
	cout << myticket2.print_ticket() << endl;
}

void test4()
{
	TicketSales ts;
	ShowTicket myticket1("AA", "101");
	SportTicket myticket2("AA", "102");

	myticket1.sell_seat();
	myticket2.sell_seat();
	myticket2.beer_sold();
	cout << ts.print_ticket(&myticket1);
	cout << ts.print_ticket(&myticket2);
}

int main()
{
	test4();
	return 0;
}
