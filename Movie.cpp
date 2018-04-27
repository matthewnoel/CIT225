// Author:  Matthew Noel
// Course:  CIT225
// File:    Movie.cpp
// Purpose: .cpp file for Movie class

#include"Movie.h"

using namespace std;

Movie::Movie() {
        parties;
        title = "";
        capacity = -1;
        remaining = -1;
}

void Movie::init(string ti, long cap) {
        title = ti;
        capacity = cap;
        remaining = cap;
}

bool Movie::canFit(Party people) {
        if (people.getSeatsNeeded() <= remaining) {
                return true;
        } else {
                return false;
        }
}

long Movie::getPctFull() const {
        return ((double)(capacity - remaining) / (double)capacity) * 100;
}

void Movie::addPeople(Party people) {
        if (canFit(people)) {
                remaining -= people.getSeatsNeeded();
                parties.push(people);
        }
        return;
}

Party Movie::removePeople() {
        Party a = parties.pop();
        remaining += a.getSeatsNeeded();
        return a;
}

bool Movie::hasPeople() {
        if (parties.isEmpty()) {
                return false;
        } else {
                return true;
        }
}

string Movie::getTitle() {
        return title;
}