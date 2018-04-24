#include "Movie.h"
#include "Party.h"
#include <iostream>

using namespace std;

int main()
{
	Party p;
	Movie m;

	m.init("Rampage", 10);

	if (m.getTitle() != "Rampage")
		cout << "Error in init!\n";

	if (m.hasPeople())
		cout << "Error with hasPeople 1!\n";

	if (m.getPctFull() != 0)
		cout << "Error in getPctFull 1!\n";

	if (m.getTitle() != "Rampage")
		cout << "Error in init!\n";

	p.init("Party 1", 3, "Movie 1", "Movie 2");

	if (!m.canFit(p))
		cout << "Error in canFit 1\n";

	m.addPeople(p);

	if (!m.hasPeople())
		cout << "Error with hasPeople 2!\n";

	if (m.getPctFull() != 30)
		cout << "Error in getPctFull 2!\n";


	p.init("Party 2", 4, "Movie 1", "Movie 2");

	if (!m.canFit(p))
		cout << "Error in canFit 2\n";

	m.addPeople(p);

	if (m.getPctFull() != 70)
		cout << "Error in getPctFull 3!\n";

	p.init("Party 3", 4, "Movie 1", "Movie 2");

	if (m.canFit(p))
		cout << "Error in canFit 3\n";

	p = m.removePeople();

	if (p.getName() != "Party 1")
		cout << "Error in removePeople 1!\n";

	if (!m.hasPeople())
		cout << "Error with hasPeople 3!\n";

	if (m.getPctFull() != 40)
		cout << "Error in getPctFull 4!\n";

	p = m.removePeople();

	if (p.getName() != "Party 2")
		cout << "Error in removePeople 2!\n";

	if (m.hasPeople())
		cout << "Error with hasPeople 3!\n";

	if (m.getPctFull() != 0)
		cout << "Error in getPctFull 5!\n";

	cout << "Testing Complete!\n";
	
	system("pause");
	return 0;
}