#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

class Player {

private:
	string fName, lName;
	int atBats, singles, doubles, triples, homeRuns, gamesPlayed;

public:
	// Methods.
	int getNumAtBats() const;
	int getNumSingles() const;
	int getNumDoubles() const;
	int getNumTriples() const;
	int getNumHomeRuns() const;
	int getNumGamesPlayed() const;
	string getFirstName() const;
	string getLastName() const;
	string getFullName() const;
	double getBattingAverage() const;
	double getSluggingPercentage() const;
	void addGame(int, int, int, int, int);

	// Constructors.
	Player();
	Player(string, string);
	Player(string, string, int, int, int, int, int, int);
};

#endif