// Author:  Matthew Noel
// Course:  CIT225
// File:    Vehicle.cpp
// Purpose: .cpp file for Vehicle class

#include"Vehicle.h"
#include"TrackLocation.h"
#include<cstdlib>

using namespace std;

Vehicle::Vehicle() {
        location = nullptr;
        start = nullptr;
        identify = -1;
        laps = -1;
}

TrackLocation* Vehicle::getLocation() const {
        return location;
}

void Vehicle::init(TrackLocation* startingSpot, int numLaps, int id) {
        location = startingSpot;
        start = startingSpot;        
        identify = id;
        laps = numLaps;
}

int Vehicle::getID() const {
        return identify;
}

int Vehicle::getRemaining() const {
        return laps;
}

void Vehicle::move(int spots) {
        for (int i = 0; i < spots; i++) {
                location = location->getNext();
                if (location == start) {
                        laps -= 1;
                }
        }
}