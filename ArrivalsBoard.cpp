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

//Pseudo code
SelectionSort(numbers, numbersSize) {
i = 0
j = 0
indexSmallest = 0
temp = 0  // Temporary variable for swap

for (i = 0; i < numbersSize - 1; ++i) {

// Find index of smallest remaining element
indexSmallest = i
for (j = i + 1; j < numbersSize; ++j) {

if (numbers[j] < numbers[indexSmallest]) {
indexSmallest = j
}
}

// Swap numbers[i] and numbers[indexSmallest]
temp = numbers[i]
numbers[i] = numbers[indexSmallest]
numbers[indexSmallest] = temp
}
}

// Pseudo Code
void binarySearch(numbers, numbersSize, key) {
        mid = 0
        low = 0
        high = numbersSize - 1

        while (high >= low) {
                mid = (high + low) / 2
                if (numbers[mid] < key) {
                        low = mid + 1
                } else if (numbers[mid] > key) {
                        high = mid - 1
                } else {
                        return mid
                }
        }
        return -1
}