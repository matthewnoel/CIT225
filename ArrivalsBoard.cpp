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
        long numFlights = 0;
        int minSinceMid = 60;

        // Opening flights text file and reading in information
        flightsIn.open("flights.txt");

        if (!flightsIn.is_open()) {
                cout << "Error: File does not exist.\n";
                return 0;
        }

        while (!flightsIn.peek()) {
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

                flights[numFlights].init(tempName, tempNum, tempDepart, tempArrival, tempStat);
                numFlights += 1;
        }
        
        // Print out starting board
        printBoard(flights, numFlights, minSinceMid);

        // Displays menu for user to select options
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

        // Saves flight info to text file
        flightsIn.close();
        flightsOut.open("flights.txt");
        for (int i = 0; i < numFlights; i++) {
                flightsOut << flights[i].getAirline() << " " << flights[i].getNumber() << " " << flights[i].getDepartureTime() << " " << flights[i].getArrivalTime() << " " << flights[i].getStatus() << " ";
        }

        system("pause");
        
        return 0;
}

void printBoard(Flight flights[], long& numFlights, long time) {
        cout << "  Airline    Number   Arrives    Status   Departs " << endl;
        for (int i = 0; i < numFlights; i++) {
                cout << flights[i].getAirline() << " " << flights[i].getNumber() << " " << flights[i].getDepartureTime() << " " << flights[i].getArrivalTime() << " " << flights[i].getStatus() << endl;
        }
        printFormattedTime(time);
        return;
}

void printFormattedTime(long value) {
        int hours = value / 60;
        int minutes = value % 60;

        cout << hours << ":" << minutes << endl;

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