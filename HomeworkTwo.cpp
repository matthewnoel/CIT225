/*
 * Homework 2 - CIT225
 * Matthew Noel
 */

#include<cstdlib>
#include<iostream>

using namespace std;

struct Counter {
        long long swaps;
        long long comparisons;
};

void insertionSort(long[], long, Counter&);
void selectionSort(long[], long, Counter&);
void quickSort(long[], long, long, Counter&);
long partition(long[], long, long, Counter&);
void shellSort(long[], long, long[], long, Counter&);
void insertionSortInterleaved(long[], long, long, long, Counter&);

int main() {
        Counter insertionCounter;
        Counter selectionCounter;
        Counter quickCounter;
        Counter shellCounter;
        Counter shellOneCounter;

        long fiveThousandMaster[5000];
        long tenThousandMaster[10000];
        long hundredThousandMaster[100000];

        long fiveThousand[5000];
        long tenThousand[10000];
        long hundredThousand[100000];

        long gapValues[20];

        // Fill master arrays randomly
        for (int i = 0; i < 5000; i++) {
                fiveThousandMaster[i] = rand();
        }

        for (int i = 0; i < 10000; i++) {
                tenThousandMaster[i] = rand();
        }

        for (int i = 0; i < 100000; i++) {
                hundredThousandMaster[i] = rand();
        }

        for (int i = 0; i < 3; i++) {

                // Fill duplicate arrays
                for (int i = 0; i < 5000; i++) {
                        fiveThousand[i] = fiveThousandMaster[i];
                }

                for (int i = 0; i < 10000; i++) {
                        tenThousand[i] = tenThousandMaster[i];
                }

                for (int i = 0; i < 100000; i++) {
                        hundredThousand[i] = hundredThousandMaster[i];
                }

                // Insertion sort all three
                insertionSort(fiveThousand, 5000, insertionCounter);
                insertionSort(tenThousand, 10000, insertionCounter);
                insertionSort(hundredThousand, 100000, insertionCounter);

                // Output counts
        }

        for (int i = 0; i < 3; i++) {

                // Fill duplicate arrays
                for (int i = 0; i < 5000; i++) {
                        fiveThousand[i] = fiveThousandMaster[i];
                }

                for (int i = 0; i < 10000; i++) {
                        tenThousand[i] = tenThousandMaster[i];
                }

                for (int i = 0; i < 100000; i++) {
                        hundredThousand[i] = hundredThousandMaster[i];
                }

                // Selection sort all three

                // Output counts
        }

        for (int i = 0; i < 3; i++) {

                // Fill duplicate arrays
                for (int i = 0; i < 5000; i++) {
                        fiveThousand[i] = fiveThousandMaster[i];
                }

                for (int i = 0; i < 10000; i++) {
                        tenThousand[i] = tenThousandMaster[i];
                }

                for (int i = 0; i < 100000; i++) {
                        hundredThousand[i] = hundredThousandMaster[i];
                }

                // Quicksort all three

                // Output counts
        }

        // Fill gapValues[]

        for (int i = 0; i < 3; i++) {

                // Fill duplicate arrays
                for (int i = 0; i < 5000; i++) {
                        fiveThousand[i] = fiveThousandMaster[i];
                }

                for (int i = 0; i < 10000; i++) {
                        tenThousand[i] = tenThousandMaster[i];
                }

                for (int i = 0; i < 100000; i++) {
                        hundredThousand[i] = hundredThousandMaster[i];
                }

                // Shell sort all three

                // Output counts
        }

        // Fill gapValues[]

        for (int i = 0; i < 3; i++) {

                // Fill duplicate arrays
                for (int i = 0; i < 5000; i++) {
                        fiveThousand[i] = fiveThousandMaster[i];
                }

                for (int i = 0; i < 10000; i++) {
                        tenThousand[i] = tenThousandMaster[i];
                }

                for (int i = 0; i < 100000; i++) {
                        hundredThousand[i] = hundredThousandMaster[i];
                }

                // Shell sort all three

                // Output counts
        }

        return 0;
}

// [Y] Works
// Smallest to largest
void insertionSort(long numbers[], long numbersSize, Counter& insertionCounts) {
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
void selectionSort(long numbers[], long numbersSize, Counter& selectionCounts) {
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
void quickSort(long numbers[], long i, long k, Counter& quickCounts) {
        int j = 0;

        if (i >= k) {
                return;
        }

        j = partition(numbers, i, k, quickCounts);

        quickSort(numbers, i, j, quickCounts);
        quickSort(numbers, j + 1, k, quickCounts);
}

long partition(long numbers[], long i, long k, Counter& quickCounts) {
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
void shellSort(long numbers[], long numbersSize, long gapValues[], long numGaps, Counter& shellCounts) {
        for (int j = 0; j < numGaps; j++) {
                for (int i = 0; i < gapValues[j]; i++) {
                        insertionSortInterleaved(numbers, numbersSize, i, gapValues[j], shellCounts);
                }
        }
}

void insertionSortInterleaved(long numbers[], long numbersSize, long startIndex, long gap, Counter& shellCounts) {

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