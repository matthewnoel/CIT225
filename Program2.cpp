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
        // Declare all variables
        string fileName;
        long numParties;
        long numMovies;
        Queue<Party> parties;
        Movie movies[10];
        Queue<Party> wentElsewhere;
        ifstream moviesIn;

        // Prompt user for filename
        cout << "What is the name of the file? (Please include .txt)" << endl;
        cin >> fileName;
        moviesIn.open(fileName);

        // Open file
        if (!moviesIn.is_open()) {
                cout << "Error: File does not exist.\n";
                return 0;
        }

        // Read in information from file
        moviesIn >> numParties;

        for (int i = 0; i < numParties; i++) {
                // Add parties to queue
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
                // Add movies to array
                string tempName;
                long tempSeats;

                moviesIn >> tempName;
                moviesIn >> tempSeats;

                movies[i].init(tempName, tempSeats);
        }

        // Assign people to movies
        while (!parties.isEmpty()) {
                int indexOne = linearSearch(movies, numMovies, parties.peek().getFirstChoice());
                int indexTwo = linearSearch(movies, numMovies, parties.peek().getSecondChoice());
                if (movies[indexOne].canFit(parties.peek())) {
                        movies[indexOne].addPeople(parties.pop());
                } else if (movies[indexTwo].canFit(parties.peek())) {
                        movies[indexTwo].addPeople(parties.pop());
                } else {
                        wentElsewhere.push(parties.pop());
                }
        }

        // Sort movies by percent full
        selectionSort(movies, numMovies);

        // Display all movie assignments
        for (int i = 0; i < numMovies; i++) {
                cout << setw(16) << left << movies[i].getTitle() << setw(14) << right << movies[i].getPctFull() << "% full" << endl;
                while (movies[i].hasPeople()) {
                        cout << "   " << movies[i].removePeople().getName() << endl;
                }
                cout << endl;
        }

        cout << "Went Elsewhere" << endl;
        while (!wentElsewhere.isEmpty()) {
                cout << "   " << wentElsewhere.pop().getName() << endl;
        }
        cout << endl;

        return 0;
}

void selectionSort(Movie movies[], int moviesSize) {
        int indexLargest = 0;
        Movie temp;

        for (int i = 0; i < moviesSize - 1; i++) {
                indexLargest = i;
                for (int j = i + 1; j < moviesSize; j++) {
                        if (movies[j].getPctFull() > movies[indexLargest].getPctFull()) {
                                indexLargest = j;
                        }
                }
                temp = movies[i];
                movies[i] = movies[indexLargest];
                movies[indexLargest] = temp;
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
