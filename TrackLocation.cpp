// Author:  Matthew Noel
// Course:  CIT225
// File:    TrackLocation.cpp
// Purpose: .cpp file for TrackLocation class

#include"TrackLocation.h"
#include<cstdlib>

using namespace std;

TrackLocation::TrackLocation() {
        nextNodePtr = nullptr;
        if (rand() % 5 == 0) {
                numTurbos = 2;
        } else {
                numTurbos = 0;
        }
}

TrackLocation* TrackLocation::getNext() const {
        return nextNodePtr;
}

void TrackLocation::setNext(TrackLocation* next) {
        nextNodePtr = next;
}

bool TrackLocation::hasTurbo() {
        if (numTurbos == 0) {
                return false;
        } else {
                return true;
        }
}

int TrackLocation::getTurbo() {
        int num = rand() % 3;
        numTurbos -= num;
        return num;
}
