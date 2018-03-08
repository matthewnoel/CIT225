#include"Player.h"
#include<string>
#include<iostream>

using namespace std;

// Methods.
int Player::getNumAtBats() const {
	return atBats;
}

int Player::getNumSingles() const {
	return singles;
}

int Player::getNumDoubles() const {
	return doubles;
}

int Player::getNumTriples() const {
	return triples;
}

int Player::getNumHomeRuns() const {
	return homeRuns;
}

int Player::getNumGamesPlayed() const {
	return gamesPlayed;
}

string Player::getFirstName() const {
	return fName;
}

string Player::getLastName() const {
	return lName;
}

string Player::getFullName() const {
	return fName + " " + lName;
}

double Player::getBattingAverage() const {
        if (atBats != 0) {
                return (singles + doubles + triples + homeRuns) / (double)atBats;
        } else {
                return 0;
        }
}

double Player::getSluggingPercentage() const {
        if (atBats != 0) {
	        return (singles + (doubles * 2) + (triples * 3) + (homeRuns * 4)) / (double)atBats;
        }
        else {
                return 0;
        }
}

void Player::addGame(int bats, int sing, int doub, int trip, int home) {
	if (sing < 0 || doub < 0 || trip < 0 || home < 0 || (sing + doub + trip + home) > bats) {
		cout << "That data doesn't seem to be right!";
	} else {
		atBats += bats;
		singles += sing;
		doubles += doub;
		triples += trip;
		homeRuns += home;
		gamesPlayed += 1;
	}
	return;
}

// Constructors.
Player::Player() {
	fName = "None";
	lName = "None";
	atBats = 0;
	singles = 0;
	doubles = 0;
	triples = 0;
	homeRuns = 0;
	gamesPlayed = 0;
}

Player::Player(string first, string last) {
	fName = first;
	lName = last;
	atBats = 0;
	singles = 0;
	doubles = 0;
	triples = 0;
	homeRuns = 0;
	gamesPlayed = 0;
}

Player::Player(string first, string last, int bats, int s, int d, int t, int h, int games) {
	fName = first;
	lName = last;
	atBats = bats;
	singles = s;
	doubles = d;
	triples = t;
	homeRuns = h;
	gamesPlayed = games;
}