// Menu Lab program to manage and redeem points for milk purchases

// Matthew Noel

 // 2/7/2018 

 #include <iostream>

 using namespace std;

 // Prototypes

 char displayMenu();

 int main() {

 	 // Declaring variables

   char option;

   int points, money = 0;

 	 cout << "Welcome to the grocery store!" << endl;

 	 cout << "Here you can get 1 point per half-gallon of milk you buy, then redeem 5 of those points for $1!" << endl << " H a v e   f u n ! " << endl;

 	 // Menu loop that executes at least once

 	 do {
     option = displayMenu();

 	 	 switch(option){

 	 	 	 // Buy a gallon

 	 	 	 case   'G' :

 	 	 	 case   'g' :

         points += 2;

 	 	 	 	 cout << "You've earned 2 points!" << endl;

 	 	 	 	 break;

 	 	 	 // Buy half a gallon

 	 	 	 case 'H':

 	 	 	 case 'h':

 	 	 	 	 points += 1;

 	 	 	 	 cout << "You've earned 1 point!" << endl;

 	 	 	 	 break;

 	 	 	 // Redeem coupon

 	 	 	 case 'R':

 	 	 	 case 'r':

 	 	 	 	 if (points >= 5) {

 	 	 	 	 	 points -= 5;

 	 	 	 	 	 money += 1;

 	 	 	 	 	 cout << "You've redeemed 5 points for $1!" << endl;

 	 	 	 	 } else {

 	 	 	 	 	 cout << "You need at least five points to redeem a coupon!" << endl;

 	 	 	 	 }

 	 	 	 	 break;

 	 	 	 case 'Q':

 	 	 	 case 'q':

 	 	 	 	 break;

 	 	 	 default:

 	 	 	 	 cout << "Please select a valid option" << endl;

 	 	 }

 	 } while (option != 'q' && option != 'Q');

 	 cout << "You ended with " << points << " points and " << money << " dollars!" << endl << endl;

 	 system("pause");

 	 return 0;

 }

 // Display menu function

 char displayMenu() {

 	 char c;

 	 cout << endl << "What would you like to do? " << endl << endl;

 	 cout << "[G]  Purchase one gallon of milk" << endl;

 	 cout << "[H]  Purchase one-half gallon of milk" << endl;

 	 cout << "[R]  Redeem coupon" << endl;

 	 cout << "[Q]  Quit" << endl;

 	 cout << endl << "I choose to: ";

 	 cin >> c;

 	 cout << endl;

 	 return c;

 }
