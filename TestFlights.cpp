#include "Flight.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	Flight f, f2;
	if (f.getAirline() != "None" || f.getStatus() != 'N' || f.getArrivalTime() != -1 || f.getDepartureTime() != -1 || f.getNumber() != -1)
		cout << "Error in constructor!\n";

	//init should be passed airline, number, departure time, and arrival time
	f.init("Airline", 227, 100, 200);
	if (f.getAirline() != "Airline" || f.getStatus() != 'R' || f.getArrivalTime() != 200 || f.getDepartureTime() != 100 || f.getNumber() != 227)
		cout << "Error in init!\n";

	f.delay(30);
	if (f.getStatus() != 'D' || f.getArrivalTime() != 230 || f.getDepartureTime() != 130)
		cout << "Error in delay!\n";

	f.delay(25.5);
	if (f.getStatus() != 'D' || f.getArrivalTime() != 255 || f.getDepartureTime() != 155)
		cout << "Error in delay!\n";

	f.depart();
	if (f.getStatus() != 'E')
		cout << "Error in depart!\n";

	f.arrive();
	if (f.getStatus() != 'A')
		cout << "Error in arrive!\n";
	
	f.finish();
	if (f.getArrivalTime() != 1500)
		cout << "Error in finish!\n";

	f2.cancel();
	if (f2.getStatus() != 'C')
		cout << "Error in cancel!\n";

	cout << "Testing complete!\n";

	system("pause");
	return 0;
}