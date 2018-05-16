// Author:  Matthew Noel
// Course:  CIT225
// File:    Program3.cpp
// Purpose: main .cpp file for Program 3

#include<iostream>
#include<ios>
#include<iomanip>
#include<string>
#include"TrackLocation.h"
#include"Vehicle.h"

using namespace std;

void printRace(TrackLocation*, Vehicle[], long, long);
void printLocation(TrackLocation*, Vehicle[], long);

int main() {
        srand(time(0));
        // Create track
        TrackLocation *loc1, *loc2, *loc3, *loc4, *loc5, *loc6, *loc7, *loc8, *loc9, *loc10;
        loc1 = new TrackLocation;
        loc2 = new TrackLocation;
        loc3 = new TrackLocation;
        loc4 = new TrackLocation;
        loc5 = new TrackLocation;
        loc6 = new TrackLocation;
        loc7 = new TrackLocation;
        loc8 = new TrackLocation;
        loc9 = new TrackLocation;
        loc10 = new TrackLocation;
        loc1->setNext(loc2);
        loc2->setNext(loc3);
        loc3->setNext(loc4);
        loc4->setNext(loc5);
        loc5->setNext(loc6);
        loc6->setNext(loc7);
        loc7->setNext(loc8);
        loc8->setNext(loc9);
        loc9->setNext(loc10);
        loc10->setNext(loc1);

        // Create vehicles
        const int NUM_CARS = 3;
        const int NUM_LAPS = 3;
        Vehicle cars [NUM_CARS];
        for (int i = 0; i < NUM_CARS; i++) {
                cars[i].init(loc1, NUM_LAPS, i + 1);
        }

        // Runs race
        bool hasWon = false;
        while (!hasWon) {
                for (int i = 0; i < NUM_CARS && !hasWon; i++) {
                        printRace(loc1, cars, NUM_CARS, i);
                        system("PAUSE");
                        cars[i].move(1);
                        if (cars[i].getLocation()->hasTurbo()) {
                                printRace(loc1, cars, NUM_CARS, i);
                                int turboAmount = cars[i].getLocation()->getTurbo();
                                cout << "Player " << cars[i].getID() << " has recived a turbo bonus of " << turboAmount << " move(s)!" << endl;
                                system("PAUSE");
                                cars[i].move(turboAmount);
                        }
                        if (cars[i].getRemaining() == 0) {

                                hasWon = true;
                                printRace(loc1, cars, NUM_CARS, i);
                                cout << "Player " << cars[i].getID() << " won!" << endl;
                        }
                }
        }

        return 0;
}

void printRace(TrackLocation* head, Vehicle vehicles [], long numVehicles, long moveNext) {
        system("cls");
        // Prints track
        TrackLocation* temp;
        temp = head;
        do {
                printLocation(temp, vehicles, numVehicles);
                temp = temp->getNext();
        } while (temp != head);
        cout << "|" << endl << endl;

        // Prints driver rankings
        cout << "   Player  To Go" << endl;
        for (int i = 0; i < numVehicles; i++) {
                if (i == moveNext) {
                        cout << "*";
                } else {
                        cout << " ";
                }
                cout << "       " << vehicles[i].getID() << "      " << vehicles[i].getRemaining() << endl;
        }

        return;
}

void printLocation(TrackLocation* loc, Vehicle vehicles[], long numVehicles) {
        cout << "|";
        if (loc->hasTurbo()) {
                cout << ">";
        } else {
                cout << " ";
        }
        cout << setw(5) << right;
        for (int i = 0; i < numVehicles; i++) {
                if (vehicles[i].getLocation() == loc) {
                        cout << vehicles[i].getID();
                }
        }
        return;
}