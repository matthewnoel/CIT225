#include "TrackLocation.h"
#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	TrackLocation *testLoc, *testLoc2, *testLoc3;
	int count, count2, turboVal;

	srand(time(0));

	testLoc = new TrackLocation;

	count = 100;
	while (testLoc->hasTurbo() && count > 0)
	{
		delete testLoc;
		testLoc = new TrackLocation;
		count--;
	}

	if (count == 0)
	{
		cout << "Error creating location without turbo!\n";
	}
	
	count = 100;

	delete testLoc;
	testLoc = new TrackLocation;

	while (!testLoc->hasTurbo() && count > 0)
	{
		delete testLoc;
		testLoc = new TrackLocation;
		count--;
	}

	if (count == 0)
	{
		cout << "Error creating location with turbo 1!\n";
	}
	else
	{
		count2 = 100;
		do
		{
			do
			{
				delete testLoc;
				testLoc = new TrackLocation;
			} while (!testLoc->hasTurbo());

			count = 100;
			do
			{
				turboVal = testLoc->getTurbo();
				count--;

			} while (turboVal == 0 && count > 0);

			count2--;
		} while (turboVal != 1 && count2 >0);


		if (count2 == 0)
		{
			cout << "Error generating turbo value of 1!\n";
		}

		if (!testLoc->hasTurbo())
		{
			"Error with hasTurbo method 1!\n";
		}

		count = 100;
		do
		{
			turboVal = testLoc->getTurbo();
			count--;

		} while (turboVal != 1 && count > 0);

		if (count == 0)
		{
			cout << "Error generating second turbo value of 1!\n";
		}

		if (turboVal == 2)
		{
			cout << "Error generating too much turbo!\n";
		}


		if (testLoc->hasTurbo())
		{
			"Error with hasTurbo method 2!\n";
		}

		delete testLoc;

		testLoc = new TrackLocation;

		count = 100;
		while (!testLoc->hasTurbo() && count > 0)
		{
			delete testLoc;
			testLoc = new TrackLocation;
			count--;
		}

		if (count == 0)
		{
			cout << "Error creating location with turbo 2!\n";
		}
		else
		{
			count2 = 100;
			do
			{
				do
				{
					delete testLoc;
					testLoc = new TrackLocation;
				} while (!testLoc->hasTurbo());

				count = 100;
				do
				{
					turboVal = testLoc->getTurbo();
					count--;

				} while (turboVal == 0 && count > 0);

				count2--;
			} while (turboVal != 2 && count2 >0);

			
			if (count2 == 0)
			{
				cout << "Error generating turbo value of 2!\n";
			}

			if (testLoc->hasTurbo())
			{
				"Error with hasTurbo method 3!\n";
			}


		}

	}

	delete testLoc;

	testLoc = new TrackLocation;
	testLoc2 = new TrackLocation;
	testLoc3 = new TrackLocation;

	testLoc->setNext(testLoc2);

	if (testLoc->getNext() != testLoc2)
		cout << "Error with get/set next 1!\n";

	testLoc2->setNext(testLoc3);

	if (testLoc2->getNext() != testLoc3)
		cout << "Error with get/set next 2!\n";

	testLoc3->setNext(testLoc);

	if (testLoc3->getNext() != testLoc)
		cout << "Error with get/set next 3!\n";


	cout << "Testing complete!\n";
	system("pause");
	return 0;
}