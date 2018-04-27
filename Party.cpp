// Author:  Matthew Noel
// Course:  CIT225
// File:    Program2.cpp
// Purpose: .cpp file for Party class

#include"Party.h"

using namespace std;

Party::Party()
{
        name = "";
        seatsNeeded = -1;
        firstChoice = "";
        secondChoice = "";
}

void Party::init(string nam, long seat, string fir, string sec) {
        name = nam;
        seatsNeeded = seat;
        firstChoice = fir;
        secondChoice = sec;
}

string Party::getName() const {
        return name;
}

long Party::getSeatsNeeded() const {
        return seatsNeeded;
}

string Party::getFirstChoice() const {
        return firstChoice;
}

string Party::getSecondChoice() const {
        return secondChoice;
}