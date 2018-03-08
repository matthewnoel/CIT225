#pragma once
#ifndef BPLAYER_H
#define BPLAYER_H

#include <string>
using namespace std;

class BPlayer {

private:
	string fName;
	string lName;
	int shots;
	int made;

public:
	// Gets total number of shots taken.
	int getShots() const;
	// Gets number of shots made.
	int getShotsMade() const;
	// Sets total shots to int.
	void setShots(int);
	// Sets shots made to int.
	void setShotsMade(int);
	// Adds single shot, boolean to tell if it was made or not.
	void addShot(bool);
	// Gets shot percentage.
	double getShotPercentage() const;
	// Gets first name of player.
	string getFirstName() const;
	// Gets last name of player.
	string getLastName() const;
	// Gets full name of player.
	string getFullName() const;
	// Default Player constructor.
	BPlayer();
	// Specific Player constructor.
	BPlayer(string, string, int, int);
};

#endif