#include "Party.h"
#include <iostream>

using namespace std;

int main()
{
	Party p;

	p.init("Test", 3, "Lassie", "Bambi");

	if (p.getName() != "Test")
		cout << "Error with getName!\n";

	if (p.getSeatsNeeded() != 3)
		cout << "Error with getSeatsNeeded!\n";

	if (p.getFirstChoice() != "Lassie")
		cout << "Error with getFirstChoice!\n";

	if (p.getSecondChoice() != "Bambi")
		cout << "Error with getSecondChoice!\n";

	cout << "Testing Complete!\n";

	system("pause");
	return 0;
}
