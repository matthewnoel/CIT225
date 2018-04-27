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
        remaining = capacity;
}

bool Movie::canFit(Party people) {
        if (people.getSeatsNeeded() <= remaining) {
                return true;
        } else {
                return false;
        }
}

long Movie::getPctFull() const {
        return ((double)(capacity - remaining) / capacity) * 100;
}

void Movie::addPeople(Party people) {
        if (canFit(people)) {
                parties.push(people);
                remaining -= people.getSeatsNeeded();
        }
        return;
}

Party Movie::removePeople() {
        Party a = parties.pop();
        remaining -= a.getSeatsNeeded();
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