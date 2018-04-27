#pragma once
#ifndef MOVIE_H
#define MOVIE_H

#include<string>
#include"Queue.h"
#include"Party.h"
using namespace std;

class Movie {

private:
        Queue<Party> parties;
        string title;
        long capacity;
        long remaining;

public:
        Movie();
        void init(string, long);
        bool canFit(Party);
        long getPctFull() const;
        void addPeople(Party);
        Party removePeople();
        bool hasPeople();
        string getTitle();
};

#endif