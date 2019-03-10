#include <iostream>
#include <cmath>
#include "Circle.h"

using std::pow;
using std::ostream;
using std::endl;

// function definitions
double Circle::get_diameter() const {
	return 2 * radius;
}

double Circle::get_circumference() const {
	return get_diameter() * pi;
}

double Circle::get_area() const {
	return pi * pow(radius, 2.0);
}

// operator definitions
Circle Circle::operator+ (const Circle& right) {
	Circle c;
	c.set_radius(radius + right.radius);
	return c;
}

Circle Circle::operator- (const Circle& right) {
	Circle c;
	c.set_radius(radius - right.radius);
	return c;
}

Circle& Circle::operator++ () {
	++radius;                 // increment data members
	return *this;             // return current object
}

ostream& operator<< (ostream& out, const Circle& circle) {
	out << "radius=" << circle.get_radius()
		<< "|diameter=" << circle.get_diameter()
		<< "|circumference=" << circle.get_circumference()
		<< "|area=" << circle.get_area() << endl;
	return out;
}