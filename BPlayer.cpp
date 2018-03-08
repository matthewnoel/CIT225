#include"BPlayer.h"
#include<string>

using namespace std;

// Gets total number of shots taken.
int BPlayer::getShots() const {
	return shots;
}

// Gets number of shots made.
int BPlayer::getShotsMade() const {
	return made;
}

// Set total shots to int.
void BPlayer::setShots(int s) {
	shots = s;
	return;
}

// Sets shots made to int.
void BPlayer::setShotsMade(int s) {
	made = s;
	return;
}

// Adds single shot, boolean to tell if it was made or not.
void BPlayer::addShot(bool madeIt) {
	if (madeIt) {
		shots += 1;
		made += 1;
	}
	else {
		shots += 1;
	}
}

// Gets shot percentage.
double BPlayer::getShotPercentage() const {
	return 100 * ((double)made / shots);
}

// Gets first name of player.
string BPlayer::getFirstName() const {
	return fName;
}

// Gets last name of player.
string BPlayer::getLastName() const {
	return lName;
}

// Gets full name of player.
string BPlayer::getFullName() const {
	return fName + " " + lName;
}

// Default Player constructor.
BPlayer::BPlayer() {
	fName = "";
	lName = "";
	shots = -1;
	made = -1;
}

// Specific Player constructor.
BPlayer::BPlayer(string first, string last, int s, int m) {
	fName = first;
	lName = last;
	shots = s;
	made = m;
}
