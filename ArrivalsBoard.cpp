// Author:  Matthew Noel
// Course:  CIT225
// File:    ArrivalsBoard.cpp
// Purpose: main .cpp file for Program 1

#include<iostream>
#include<ios>
#include<iomanip>
#include<fstream>
#include"Flight.h"

using namespace std;

void printBoard(Flight[], long&, long);
void printFormattedTime(long);
char displayMenu();
void selectionSort(Flight[], int);
Flight linearSearch(Flight[], int, int);

int main() {
        ifstream flightsIn;
        ofstream flightsOut;
        
        char option;
        const int FLIGHTS_SIZE = 20;
        Flight flights[FLIGHTS_SIZE];
        int numFlights = 0;

        // Read in flights from file
        flightsIn.open("flights.txt");

        if (!flightsIn.is_open()) {
                cout << "Error: File does not exist.\n";
                return 0;
        }

        while (!flightsIn.eof()) {
                numFlights += 1;
                string tempName;
                int tempNum;
                int tempDepart;
                int tempArrival;
                char tempStat;

                flightsIn >> tempName;
                flightsIn >> tempNum;
                flightsIn >> tempDepart;
                flightsIn >> tempArrival;
                flightsIn >> tempStat;

                flights[numFlights - 1].init(tempName, tempNum, tempDepart, tempArrival, tempStat);
        }

        do {
                option = displayMenu();
                switch (option) {
                case 'A':
                case 'a':

                        break;
                case 'C':
                case 'c':

                        break;
                case 'D':
                case 'd':

                        break;

                case 'M':
                case 'm':

                        break;

                case 'Q':
                case 'q':

                        break;
                default:
                        cout << "Please select a valid option" << endl;
                }

        } while (option != 'q' && option != 'Q');

        // After quit, save info to baseball.txt
        flightsIn.close();
        flightsOut.open("flights.txt");
        for (int i = 0; i < numFlights; i++) {
                flightsOut << flights[i].getFullName() << " " << players[i].getNumAtBats() << " " << players[i].getNumSingles() << " " << players[i].getNumDoubles() << " " << players[i].getNumTriples() << " " << players[i].getNumHomeRuns() << " " << players[i].getNumGamesPlayed() << " ";
        }

        system("pause");
        
        return 0;
}

void printBoard(Flight flights[], long& val, long val2) {
        system("cls");
        cout << "  Airline    Number   Arrives    Status   Departs ";
        for (int i = 0; i < val2; i++) {

        }
        return;
}

void printFormattedTime(long value) {
        return;
}

char displayMenu() {
        char c;
        cout << "(A)dvance time" << endl;
        cout << "(C)ancel flight" << endl;
        cout << "(D)elay flight" << endl;
        cout << "(M)ake flight" << endl;
        cout << "(Q)uit" << endl;
        cin >> c;
        return c;
}

void selectionSort(Flight flights[], int flightsSize) {
        int indexSmallest = 0;
        Flight temp;

        for (int i = 0; i < flightsSize - 1; i++) {
                indexSmallest = i;
                for (int j = i + 1; j < flightsSize; j++) {
                        if (flights[j].getArrivalTime() < flights[indexSmallest].getArrivalTime()) {
                                indexSmallest = j;
                        }
                }
                temp = flights[i];
                flights[i] = flights[indexSmallest];
                flights[indexSmallest] = temp;
        }
}

Flight linearSearch(Flight flights[], int flightsSize, int flightNum) {
        for (int i = 0; i < flightsSize; i++) {
                if (flights[i].getNumber() == flightNum) {
                        return flights[i];
                }
        }
}