#pragma once
#ifndef VEHICLE_H
#define VEHICLE_H

#include<string>
#include"TrackLocation.h"
using namespace std;

class Vehicle {

private:
        TrackLocation* location;
        TrackLocation* start;
        int identify;
        int laps;

public:
        Vehicle();
        TrackLocation* getLocation() const;
        void init(TrackLocation*, int, int);
        int getID() const;
        int getRemaining() const;
        void move(int);
};

#endif