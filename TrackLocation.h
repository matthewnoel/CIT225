#pragma once
#ifndef TRACKLOCATION_H
#define TRACKLOCATION_H

#include<string>
using namespace std;

class TrackLocation {

private:
        TrackLocation * nextNodePtr;
        int numTurbos;

public:
        TrackLocation();
        TrackLocation* getNext() const;
        void setNext(TrackLocation*);
        bool hasTurbo();
        int getTurbo();
};

#endif