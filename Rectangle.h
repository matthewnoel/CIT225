#pragma once
#ifndef RECTANGLE_H
#define RECTANGLE_H
 
using namespace std;

class Rectangle {

private:
	double length;
	double width;

public:
	// Gets rectangle length.
	double getLength() const;
	// Gets rectangle width.
	double getWidth() const;
	// Gets rectangle area.
	double getArea() const;
	// Gets rectangle perimeter.
	double getPerimeter() const;
	// Sets rectangle length.
	void setLength(double);
	// Sets rectangle width.
	void setWidth(double);

	// Default Rectangle constructor.
	Rectangle();
	// Specific Rectangle constructor.
	Rectangle(double, double);
};

#endif
