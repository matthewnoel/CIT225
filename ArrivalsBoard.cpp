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
void selectionSort(Flight[], int);
int binarySearch(int[], int, int, int&);

int main() {
        
        char option;

        do {
                option = displayMenu();
                switch (option) {
                case 'A':
                case 'a':

                        break;
                case 'C':
                case 'c':

                        break;
                case 'D':
                case 'd':

                        break;

                case 'M':
                case 'm':

                        break;

                case 'Q':
                case 'q':

                        break;
                default:
                        cout << "Please select a valid option" << endl;
                }

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

void selectionSort(Flight flights[], int flightsSize) {
        int indexSmallest = 0;
        Flight temp;

        for (int i = 0; i < flightsSize - 1; i++) {
                indexSmallest = i;
                for (int j = i + 1; j < flightsSize; j++) {
                        if (flights[j].getArrivalTime() < flights[indexSmallest].getArrivalTime()) {
                                indexSmallest = j;
                        }
                }
                temp = flights[i];
                flights[i] = flights[indexSmallest];
                flights[indexSmallest] = temp;
        }
}

int binarySearch(int arr[], int arrSize, int num, int& count) {
        int mid = 0;
        int low = 0;
        int high = arrSize - 1;

        while (high >= low) {
                count++;
                mid = (high + low) / 2;
                if (arr[mid] < num) {
                        low = mid + 1;
                }
                else if (arr[mid] > num) {
                        high = mid - 1;
                }
                else {
                        return mid;
                }

        }
        return -1;
}