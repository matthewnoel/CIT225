#include "Circle.h"
#include <iostream>

using namespace std;

const int NUM_CIRCLES = 5;

void selectionSort(Circle[], int);

int main() {
        Circle circles[NUM_CIRCLES];
        // Loop and get radii for array
        for (int i = 0; i < NUM_CIRCLES; i++) {
                int tempRadius = 0;
                cout << "Circle " << i + 1 << " radius: ";
                cin >> tempRadius;
                circles[i].setRadius(tempRadius);
                circles[i].setId(i + 1);
        }
        cout << endl;

        // Sort array

        selectionSort(circles, NUM_CIRCLES);

        // Print ids
        for (int i = NUM_CIRCLES - 1; i >= 0; i--) {
                cout << circles[i].getId() << " area: " << circles[i].getArea() << " ";
        }
        cout << endl;

        return 0;
}

void selectionSort(Circle circles[], int circlesSize) {
        int indexSmallest = 0;
        Circle temp;

        for (int i = 0; i < circlesSize - 1; i++) {
                indexSmallest = i;
                for (int j = i + 1; j < circlesSize; j++) {
                        if (circles[j].getRadius() < circles[indexSmallest].getRadius()) {
                                indexSmallest = j;
                        }
                }
                temp = circles[i];
                circles[i] = circles[indexSmallest];
                circles[indexSmallest] = temp;
        }
}