#include"Flight.h"
#include<string>

using namespace std;

string Flight::getAirline() const {
        return airlineName;
}

int Flight::getNumber() const {
        return flightNumber;
}

int Flight::getArrivalTime() const {
        return arrival;
}

int Flight::getDepartureTime() const {
        return departure;
}

char Flight::getStatus() const {
        return status;
}

void Flight::init(string airline, int number, int departureTime, int arrivalTime) {
        airlineName = airline;
        flightNumber = number;
        departure = departureTime;
        arrival = arrivalTime;
        status = 'R';
        return;
}

void Flight::arrive() {
        status = 'A';
        return;
}

void Flight::depart() {
        status = 'E';
        return;
}

void Flight::cancel() {
        status = 'C';
        return;
}

void Flight::finish() {
        arrival = 1500;
        status = 'F';
        return;
}

void Flight::delay(int minutes) {
        arrival, departure += minutes;
        status = 'D';
        return;
}

Flight::Flight() {
        airlineName = "None";
        status = 'N';
        flightNumber, arrival, departure = -1;
}