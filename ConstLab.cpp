#include "Rectangle.h"
#include "Circle.h"
#include <iostream>

using namespace std;

int main() {
	// Create all variables.
	double radius;
	double length;
	double width;

	// Ask user for circle and rectangle information.
	cout << "Circle Info:" << endl;
	cout << "Radius: ";
	cin >> radius;
	cout << endl << endl;
	cout << "Rectangle Info:" << endl;
	cout << "Length: ";
	cin >> length;
	cout << "Width: ";
	cin >> width;

	// Create Circle and Rectangle objects.
	Circle circle(radius);
	Rectangle rectangle(length, width);

	// Calculate who has the higher perimeter and area and display it.
	if (circle.getArea() > rectangle.getArea()) {
		cout << endl << "The circle has the larger area!" << endl << endl;
	}
	else if (circle.getArea() < rectangle.getArea()) {
		cout << endl << "The rectangle has the larger area!" << endl << endl;
	}
	else {
		cout << endl << "They have the same area!" << endl << endl;
	}

	if (circle.getCircumfrence() > rectangle.getPerimeter()) {
		cout << endl << "The circle has the larger perimeter (circumfrencce)!" << endl << endl;
	}
	else if (circle.getArea() < rectangle.getArea()) {
		cout << endl << "The rectangle has the larger perimeter!" << endl << endl;
	}
	else {
		cout << endl << "They have the same perimeter!" << endl << endl;
	}

	return 0;
}
