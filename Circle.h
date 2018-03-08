#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H

using namespace std;

class Circle {

private:
	double radius;
        int id;

public:
	// Gets circle radius.
	double getRadius() const;
	// Gets circle diameter.
	double getDiameter() const;
	// Gets circle area.
	double getArea() const;
	// Gets circle circumfrence.
	double getCircumfrence() const;
        // Gets circle id.
        int getId() const;
        // Sets circle id.
        void setId(int);
	// Sets circle radius.
	void setRadius(double);
	// Sets circle diameter.
	void setDiameter(double);

	// Default Circle constructor.
	Circle();
	// Specific Circle constructor.
	Circle(double);
        // More specific constructor.
        Circle(double, int);
};

#endif