#include<iostream>
#include<ios>
#include<iomanip>
#include<fstream>
#include "Player.h"

using namespace std;

// File streams
ifstream baseball;
ofstream baseout;

// Prototypes
char displayMenu();
void printPlayerInfo(Player);
void getGameInformation(Player&);

int main() {
        // Create all variables
        const int NUM_PLAYERS = 3;
        Player players [NUM_PLAYERS];
        string f, l;
        int b, s, d, t, h, g;
        char option;

        baseball.open("baseball.txt");

        // If the file exists, load info of each player into program, else ask user for first and last names of 3 players
        if (baseball.is_open()) {
                // Read in all the stuff
                for (int i = 0; i < NUM_PLAYERS; i++) {
                        baseball >> f >> l >> b >> s >> d >> t >> h >> g;
                        players[i] = Player(f,l,b,s,d,t,h,g);
                }
        } else {
                // Ask for info
                for (int i = 0; i < NUM_PLAYERS; i++) {
                        cout << "Player " << i + 1 << " First Name: ";
                        cin >> f;
                        cout << "Player " << i + 1 << " Last Name: ";
                        cin >> l;
                        players[i] = Player(f, l);
                }
        }

        // Menu loop that executes at least once
        do {
                system("cls");
                option = displayMenu();

                switch (option) {

                // Add Game
                case 'A':
                case 'a':
                        for (int i = 0; i < NUM_PLAYERS; i++) {
                                getGameInformation(players[i]);
                        }
                        break;

                // Print Stats
                case 'P':
                case 'p':
                        cout << setw(19) << right << "Name";
                        cout << setw(4) << right << "G";
                        cout << setw(9) << right << "Avg";
                        cout << setw(9) << right << "Slg" << endl;
                        for (int i = 0; i < NUM_PLAYERS; i++) {
                                printPlayerInfo(players[i]);
                        }
                        system("pause");
                        break;

                // Quit
                case 'Q':
                case 'q':
                        break;

                default:
                        cout << "Please select a valid option" << endl;
                }

        } while (option != 'q' && option != 'Q');

        // After quit, save info to baseball.txt
        baseball.close();
        baseout.open("baseball.txt");
        for (int i = 0; i < NUM_PLAYERS; i++) {
                baseout << players[i].getFullName() << " " << players[i].getNumAtBats() << " " << players[i].getNumSingles() << " " << players[i].getNumDoubles() << " " << players[i].getNumTriples() << " " << players[i].getNumHomeRuns() << " " << players[i].getNumGamesPlayed() << " ";
        }

        return 0;
}

char displayMenu() {
        char c;

        cout << "(A)dd Game" << endl;
        cout << "(P)rint Statistics" << endl;
        cout << "(Q)uit" << endl;

        cout << endl << "Selection: ";

        cin >> c;

        cout << endl;

        return c;
}

void printPlayerInfo(Player athlete) {
        cout << setw(19) << right << athlete.getFullName();
        cout << setw(4) << right << athlete.getNumGamesPlayed();
        cout << setw(9) << right << fixed << showpoint << setprecision(3) << athlete.getBattingAverage();
        cout << setw(9) << right << fixed << showpoint << setprecision(3) << athlete.getSluggingPercentage() << endl;
        return;
}

void getGameInformation(Player& athlete) {
        int abats, sings, doubs, trips, homes;
        cout << athlete.getFullName() << " At Bats: ";
        cin >> abats;
        cout << athlete.getFullName() << " Singles: ";
        cin >> sings;
        cout << athlete.getFullName() << " Doubles: ";
        cin >> doubs;
        cout << athlete.getFullName() << " Triples: ";
        cin >> trips;
        cout << athlete.getFullName() << " Home Runs: ";
        cin >> homes;
        athlete.addGame(abats, sings, doubs, trips, homes);
        return;
}
