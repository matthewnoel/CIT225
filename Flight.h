// Author:  Matthew Noel
// Course:  CIT225
// File:    Flight.h
// Purpose: .h file for Flight class

#pragma once
#ifndef FLIGHT_H
#define FLIGHT_H

#include<string>

using namespace std;

class Flight {

private:
        string airlineName;
        int flightNumber, arrival, departure;
        char status;
public:
        string getAirline() const;
        int getNumber() const;
        int getArrivalTime() const;
        int getDepartureTime() const;
        char getStatus() const;

        void init(string, int, int, int);
        void init(string, int, int, int, char);
        void arrive();
        void depart();
        void cancel();
        void finish();
        void delay(int);

        Flight();
};

#endif