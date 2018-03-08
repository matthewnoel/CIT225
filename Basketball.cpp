#include "BPlayer.h"
#include <iostream>

using namespace std;

int main() {
	// Create all variables.
	string p1fName;
	string p1lName;
	string p2fName;
	string p2lName;
	int p1shots;
	int p2shots;
	int p1made;
	int p2made;

	// Ask user for player information.
	cout << "Player 1 Stats:" << endl;
	cout << "First Name: ";
	cin >> p1fName;
	cout << "Last Name: ";
	cin >> p1lName;
	cout << "Total Shots Attempted: ";
	cin >> p1shots;
	cout << "Shots Made: ";
	cin >> p1made;
	cout << endl << endl;
	cout << "Player 2 Stats:" << endl;
	cout << "First Name: ";
	cin >> p2fName;
	cout << "Last Name: ";
	cin >> p2lName;
	cout << "Total Shots Attempted: ";
	cin >> p2shots;
	cout << "Shots Made: ";
	cin >> p2made;

	// Create Player objects.
	BPlayer p1(p1fName, p1lName, p1shots, p1made);
	BPlayer p2(p2fName, p2lName, p2shots, p2made);

	// Calculate who has the higher shot percentage and display it.
	if (p1.getShotPercentage() > p2.getShotPercentage()) {
		cout << endl << p1.getFullName() << " has the higher shooting percentage!" << endl << endl;
	} else if (p2.getShotPercentage() > p1.getShotPercentage()) {
		cout << endl << p2.getFullName() << " has the higher shooting percentage!" << endl << endl;
	} else {
		cout << endl << "They have the same shooting percentage!" << endl << endl;
	}

	return 0;
}
