/*
 * Homework 2 - CIT225
 * Matthew Noel
 */

#include<cstdlib>
#include<iostream>

using namespace std;

void insertionSort(long[], long);
void selectionSort(long[], long);
void quickSort(long[], long, long);
long partition(long[], long, long);
void shellSort(long[], long, long[], long);
void insertionSortInterleaved(long[], long, long, long);

int main() {
        long numbers[] = { 23, 65, 35, 89, 98, 84, 94, 68, 54, 67, 83, 46, 91, 72, 39};
        const long NUMBERS_SIZE = 15;

        cout << "Unsorted: ";
        for (int i = 0; i < NUMBERS_SIZE; i++) {
                cout << numbers[i] << " ";
        }
        long gapValues[] = { 5,3,1 };
        shellSort(numbers, NUMBERS_SIZE, gapValues, 3);

        cout << endl << "Sorted: ";
        for (int i = 0; i < NUMBERS_SIZE; i++) {
                cout << numbers[i] << " ";
        }
        cout << endl;

        return 0;
}

// [Y] Works
// Smallest to largest
void insertionSort(long numbers[], long numbersSize) {
        int i = 0;
        int j = 0;
        int temp = 0;

        for (int i = 1; i < numbersSize; i++) {
                j = i;
                while (j > 0 && numbers[j] < numbers[j - 1]) {
                        temp = numbers[j];
                        numbers[j] = numbers[j - 1];
                        numbers[j - 1] = temp;
                        j--;
                }
        }
}

// [Y] Works
// Smallest to largest
void selectionSort(long numbers[], long numbersSize) {
        int i = 0;
        int j = 0;
        int indexSmallest = 0;
        int temp = 0;

        for (int i = 0; i < numbersSize - 1; i++) {
                indexSmallest = i;
                for (int j = i + 1; j < numbersSize; j++) {
                        if (numbers[j] < numbers[indexSmallest]) {
                                indexSmallest = j;
                        }
                }

                temp = numbers[i];
                numbers[i] = numbers[indexSmallest];
                numbers[indexSmallest] = temp;
        }
}

// [Y] Works
// Smallest to largest
// i is first element
// k is last element
void quickSort(long numbers[], long i, long k) {
        int j = 0;

        if (i >= k) {
                return;
        }

        j = partition(numbers, i, k);

        quickSort(numbers, i, j);
        quickSort(numbers, j + 1, k);
}

long partition(long numbers[], long i, long k) {
        int l = 0;
        int h = 0;
        int midpoint = 0;
        int pivot = 0;
        int temp = 0;
        bool done = false;

        midpoint = i + (k - i) / 2;
        pivot = numbers[midpoint];

        l = i;
        h = k;

        while (!done) {
                while (numbers[l] < pivot) {
                        l++;
                }

                while (pivot < numbers[h]) {
                        h--;
                }

                if (l >= h) {
                        done = true;
                } else {
                        temp = numbers[l];
                        numbers[l] = numbers[h];
                        numbers[h] = temp;

                        l++;
                        h--;
                }
        }

        return h;
}

// [Y] Works
// Smallest to largest
void shellSort(long numbers[], long numbersSize, long gapValues[], long numGaps) {
        for (int j = 0; j < numGaps; j++) {
                for (int i = 0; i < gapValues[j]; i++) {
                        insertionSortInterleaved(numbers, numbersSize, i, gapValues[j]);
                }
        }
}

void insertionSortInterleaved(long numbers[], long numbersSize, long startIndex, long gap) {

        int temp = 0;

        for (int i = startIndex + gap; i < numbersSize; i = i + gap) {
                int j = i;
                while (j - gap >= startIndex && numbers[j] < numbers[j - gap]) {
                        temp = numbers[j];
                        numbers[j] = numbers[j - gap];
                        numbers[j - gap] = temp;
                        j = j - gap;
                }
        }
}