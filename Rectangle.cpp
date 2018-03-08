#include"Rectangle.h"

using namespace std;

// Gets rectangle length.
double Rectangle::getLength() const {
	return length;
}

// Gets rectangle width.
double Rectangle::getWidth() const {
	return width;
}

// Gets rectangle area.
double Rectangle::getArea() const {
	return width * length;
}

// Gets rectangle perimeter.
double Rectangle::getPerimeter() const {
	return (2 * width) + (2 * length);
}

// Sets rectangle length.
void Rectangle::setLength(double l) {
	length = l;
	return;
}

// Sets rectangle width.
void Rectangle::setWidth(double w) {
	width = w;
	return;
}

// Default Rectangle constructor.
Rectangle::Rectangle() {
	length = -1;
	width = -1;
}

// Specific Rectangle constructor.
Rectangle::Rectangle(double l, double w) {
	length = l;
	width = w;
}