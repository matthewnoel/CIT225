#pragma once
#ifndef PARTY_H
#define PARTY_H

#include<string>
using namespace std;

class Party {

private:
        string name;
        long seatsNeeded;
        string firstChoice;
        string secondChoice;
public:
        Party();
        void init(string, long, string, string);
        string getName() const;
        long getSeatsNeeded() const;
        string getFirstChoice() const;
        string getSecondChoice() const;
};

#endif