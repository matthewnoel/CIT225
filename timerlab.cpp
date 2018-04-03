#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

int main() {
        char playAgain;
        bool replay = false;
        int randTime;
        char firstButton;
        char secondButton;
        double firstPress;
        double secondPress;
        double difference;

        srand(time(0));

        do {
                system("cls");

                randTime = (rand() % 10) + 1;

                cout << "Welcome to the guessing game" << endl;
                cout << "Try to press the enter key with a difference of " << randTime << " seconds between presses" << endl;
                cout << "Good luck!" << endl;

                cin.get();
                firstPress = clock();
                cin.get();
                secondPress = clock();

                difference = (secondPress - firstPress) / CLOCKS_PER_SEC;

                cout << "You pressed them in " << difference << " seconds!" << endl;

                if (/*time = time*/) {
                        //win
                } else {
                        //lose
                }

                cout << "Play again? (y/n) ";
                cin >> playAgain;
                switch (playAgain) {
                        case 'Y':
                        case 'y':
                                //Play again
                                replay = true;
                                cin.get();
                                break;
                        case 'N':
                        case 'n':
                                //Don't play again
                                replay = false;
                                break;
                        default:
                                replay = false;
                                break;
                }

        } while (replay);

        return 0;
}