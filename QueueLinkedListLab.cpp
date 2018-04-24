#include<ctime>
#include<iostream>
#include<cstdlib>
#include"QueueLinkedList.h"

using namespace std;

int main() {
        int randNum;
        srand(time(NULL));
        Queue<int> myQueue;

        cout << "Generated Queue" << endl;
        for (int i = 0; i < 5; i++) {
                randNum = rand() % 90 + 10;
                //add num to queue
                myQueue.push(randNum);
                cout << randNum << " ";
        }
        cout << endl << endl << "Popping Queue" << endl;
        while (!myQueue.isEmpty())
        {
                cout << myQueue.pop() << endl;
        }
        return 0;
}