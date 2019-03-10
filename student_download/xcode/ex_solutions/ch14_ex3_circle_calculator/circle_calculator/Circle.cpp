#include <cmath>
#include "Circle.h"

using std::pow;

// function definitions
double Circle::get_diameter() {
	return 2 * radius;
}

double Circle::get_circumference() {
	return get_diameter() * pi;
}

double Circle::get_area() {
	return pi * pow(radius, 2.0);
}
