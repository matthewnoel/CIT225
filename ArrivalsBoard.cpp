// Author:  Matthew Noel
// Course:  CIT225
// File:    ArrivalsBoard.cpp
// Purpose: main .cpp file for Program 1

#include<iostream>
#include"Flight.h"

using namespace std;

void printBoard(Flight[], long&, long);
void printFormattedTime(long);
char displayMenu();

int main() {
        char option;

        do {
                option = displayMenu();
                switch (option) {
                case   'G':
                case   'g':

                        break;
                case 'H':
                case 'h':

                        break;
                case 'R':
                case 'r':

                        break;
                case 'Q':
                case 'q':

                        break;
                default:
                        cout << "Please select a valid option" << endl;

        } while (option != 'q' && option != 'Q');

        system("pause");
        return 0;
}

void printBoard(Flight[], long& val, long val2) {
        return;
}

void printFormattedTime(long value) {
        return;
}

char displayMenu() {
        char c;
        cout << "(A)dvance time" << endl;
        cout << "(C)ancel flight" << endl;
        cout << "(D)elay flight" << endl;
        cout << "(M)ake flight" << endl;
        cout << "(Q)uit" << endl;
        cin >> c;
        return c;
}