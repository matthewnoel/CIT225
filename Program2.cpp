// Author:  Matthew Noel
// Course:  CIT225
// File:    Program2.cpp
// Purpose: main .cpp file for Program 2

#include<iostream>
#include<ios>
#include<iomanip>
#include<fstream>
#include<string>
#include"Movie.h"
#include"Party.h"
#include"Queue.h"

using namespace std;

void selectionSort(Movie[], int);
int linearSearch(Movie[], int, string);

int main() {
        string fileName;
        long numParties;
        long numMovies;
        Queue<Party> parties;
        Movie movies[10];

        ifstream moviesIn;

        cout << "What is the name of the file? (Please include .txt)" << endl;
        cin >> fileName;
        moviesIn.open(fileName);

        if (!moviesIn.is_open()) {
                cout << "Error: File does not exist.\n";
                return 0;
        }

        moviesIn >> numParties;

        for (int i = 0; i < numParties; i++) {
                Party tempParty;
                string tempName;
                long tempNum;
                string tempFirst;
                string tempSecond;

                moviesIn >> tempName;
                moviesIn >> tempNum;
                moviesIn >> tempFirst;
                moviesIn >> tempSecond;

                tempParty.init(tempName, tempNum, tempFirst, tempSecond);
                parties.push(tempParty);
        }

        moviesIn >> numMovies;

        for (int i = 0; i < numMovies; i++) {
                string tempName;
                long tempSeats;

                moviesIn >> tempName;
                moviesIn >> tempSeats;

                movies[i].init(tempName, tempSeats);
        }

        return 0;
}

void selectionSort(Movie movies[], int moviesSize) {
        int indexSmallest = 0;
        Movie temp;

        for (int i = 0; i < moviesSize - 1; i++) {
                indexSmallest = i;
                for (int j = i + 1; j < moviesSize; j++) {
                        if (movies[j].getPctFull() < movies[indexSmallest].getPctFull()) {
                                indexSmallest = j;
                        }
                }
                temp = movies[i];
                movies[i] = movies[indexSmallest];
                movies[indexSmallest] = temp;
        }
}

int linearSearch(Movie movies[], int moviesSize, string title) {
        for (int i = 0; i < moviesSize; i++) {
                if (movies[i].getTitle() == title) {
                        return i;
                }
        }
        return -1;
}
