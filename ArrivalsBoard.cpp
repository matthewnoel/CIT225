// Author:  Matthew Noel
// Course:  CIT225
// File:    ArrivalsBoard.cpp
// Purpose: main .cpp file for Program 1

#include<iostream>
#include<ios>
#include<iomanip>
#include<fstream>
#include<string>
#include"Flight.h"

using namespace std;

void printBoard(Flight[], long&, long);
void printFormattedTime(long);
char displayMenu();
void selectionSort(Flight[], int);
Flight& linearSearch(Flight[], int, int);

int main() {
        ifstream flightsIn;
        ofstream flightsOut;
        
        char option;
        const int FLIGHTS_SIZE = 100;
        Flight flights[FLIGHTS_SIZE];
        long numFlights = 0;
        int minSinceMid = 60;

        // Opening flights text file and reading in information
        flightsIn.open("flights.txt");

        if (!flightsIn.is_open()) {
                cout << "Error: File does not exist.\n";
                return 0;
        }

        while (true) {
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

                if (flightsIn.eof()) break;

                flights[numFlights].init(tempName, tempNum, tempDepart, tempArrival, tempStat);
                numFlights += 1;
        }

        // Displays menu for user to select options
        do {
                system("cls");
                // Print out starting board
                selectionSort(flights, numFlights);
                printBoard(flights, numFlights, minSinceMid);

                option = displayMenu();
                switch (option) {
                case 'A':
                case 'a':
                        // Advance time
                        int adMin;
                        cout << "How much time has passed? ";
                        cin >> adMin;
                        minSinceMid += adMin;

                        for (int i = 0; i < numFlights; i++) {
                                if (minSinceMid > flights[i].getDepartureTime()) {
                                        flights[i].depart();
                                }

                                if (minSinceMid > flights[i].getArrivalTime()) {
                                        flights[i].arrive();
                                }
                        }

                        break;
                case 'C':
                case 'c':
                        // Cancel flight
                        int fltNum;
                        cout << "Which flight number to cancel? ";
                        cin >> fltNum;
                        linearSearch(flights, numFlights, fltNum).cancel();
                        break;
                case 'D':
                case 'd':
                        // Delay flight
                        int flNum;
                        int min;
                        cout << "Which flight number to delay? ";
                        cin >> flNum;
                        cout << "Advance flight by how many minutes? ";
                        cin >> min;
                        linearSearch(flights, numFlights, flNum).delay(min);
                        break;

                case 'M':
                case 'm': {
                        // Make flight
                        int n;
                        int d;
                        int a;
                        string air;

                        cout << "Airline: ";
                        cin >> air;
                        cout << "Flight Number: ";
                        cin >> n;
                        cout << "Departure time: ";
                        cin >> d;
                        cout << "Arrival time: ";
                        cin >> a;
                        flights[numFlights].init(air, n, d, a);
                        numFlights += 1;
                        break; }

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
                if (flights[i].getStatus() != 'A' && flights[i].getStatus() != 'C') {
                        flightsOut << flights[i].getAirline() << " " << flights[i].getNumber() << " " << flights[i].getDepartureTime() << " " << flights[i].getArrivalTime() << " " << flights[i].getStatus() << " ";
                }
        }
        
        return 0;
}

void printBoard(Flight flights[], long& numFlights, long time) {
        cout << "   Airline    Number   Arrives    Status   Departs " << endl;
        for (int i = 0; i < numFlights; i++) {
                if (flights[i].getStatus() != 'A' && flights[i].getStatus() != 'C') {
                        cout << setw(10) << flights[i].getAirline() << setw(10) << flights[i].getNumber() << "     ";
                        printFormattedTime(flights[i].getArrivalTime());
                        cout << setw(10) << flights[i].getStatus() << "     ";
                        printFormattedTime(flights[i].getDepartureTime());
                        cout << endl;
                }
        }
        cout << endl << "Time: ";
        printFormattedTime(time);
        cout << endl << endl;
        return;
}

void printFormattedTime(long value) {
        int hours = value / 60;
        int minutes = value % 60;

        cout << setw(2) << setfill('0') << hours << ":" << setw(2) << setfill('0') << minutes << setfill(' ');

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

Flight& linearSearch(Flight flights[], int flightsSize, int flightNum) {
        for (int i = 0; i < flightsSize; i++) {
                if (flights[i].getNumber() == flightNum) {
                        return flights[i];
                }
        }
}