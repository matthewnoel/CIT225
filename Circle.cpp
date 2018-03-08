#include"Circle.h"
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

// Gets circle radius.
double Circle::getRadius() const {
	return radius;
}

// Gets circle diameter.
double Circle::getDiameter() const {
	return radius * 2;
}

// Gets circle area.
double Circle::getArea() const {
	return (radius * radius) * M_PI;
}

// Gets circle circumfrence.
double Circle::getCircumfrence() const {
	return (2 * radius) * M_PI;
}

// Gets circle id.
int Circle::getId() const {
        return id;
}

// Sets circle id.
void Circle::setId(int i) {
        id = i;
}

// Sets circle radius.
void Circle::setRadius(double r) {
	radius = r;
	return;
}

// Sets circle diameter.
void Circle::setDiameter(double d) {
	radius = d / 2;
	return;
}

// Default Circle constructor.
Circle::Circle() {
	radius = -1;
}

// Specific Circle constructor.
Circle::Circle(double r) {
	radius = r;
        id = -1;
}

// More specific constructor.
Circle::Circle(double r, int i) {
        radius = r;
        id = i;
}
