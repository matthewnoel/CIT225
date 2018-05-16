#include "Vehicle.h"
#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	TrackLocation *testLoc, *testLoc2, *testLoc3;
	Vehicle v;
	int count, count2, turboVal;

	srand(time(0));

	testLoc = new TrackLocation;
	testLoc2 = new TrackLocation;
	testLoc3 = new TrackLocation;

	testLoc->setNext(testLoc2);
	testLoc2->setNext(testLoc3);
	testLoc3->setNext(testLoc);

	v.init(testLoc, 4, 5);

	if (v.getID() != 5)
		cout << "Error in init 1!\n";

	if(v.getLocation() != testLoc)
		cout << "Error in init 2!\n";

	if (v.getRemaining() != 4)
		cout << "Error in init 3!\n";

	v.move(1);

	if (v.getLocation() != testLoc2)
		cout << "Error in move 1!\n";

	v.move(1);

	if (v.getLocation() != testLoc3)
		cout << "Error in move 2!\n";

	if (v.getRemaining() != 4)
		cout << "Error in getRemaining 1!\n";

	v.move(1);

	if (v.getLocation() != testLoc)
		cout << "Error in move 3!\n";

	if (v.getRemaining() != 3)
		cout << "Error in getRemaining 2!\n";

	v.move(2);

	if (v.getLocation() != testLoc3)
		cout << "Error in move 4!\n";

	if (v.getRemaining() != 3)
		cout << "Error in getRemaining 3!\n";

	v.move(3);

	if (v.getLocation() != testLoc3)
		cout << "Error in move 5!\n";

	if (v.getRemaining() != 2)
		cout << "Error in getRemaining 4!\n";

	v.move(4);

	if (v.getLocation() != testLoc)
		cout << "Error in move 6!\n";

	if (v.getRemaining() != 0)
		cout << "Error in getRemaining 5!\n";


	cout << "Testing complete!\n";
	system("pause");
	return 0;
}