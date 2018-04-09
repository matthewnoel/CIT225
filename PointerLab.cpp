#include<iostream>

using namespace std;

void referenceAddress(int&);
void valueAddress(int);

int main() {
        int myInt = 0;

        cout << "Enter a number: ";
        cin >> myInt;
        cout << "Stored at: " << &myInt << endl << endl;

        cout << "Running pass by reference function" << endl;
        referenceAddress(myInt);

        cout << "Running pass by value function" << endl;
        valueAddress(myInt);

        return 0;
}

void referenceAddress(int& num) {
        cout << "Memory address: " << &num << endl << endl;
        return;
}

void valueAddress(int num) {
        cout << "Memory address: " << &num << endl << endl;
        return;
}