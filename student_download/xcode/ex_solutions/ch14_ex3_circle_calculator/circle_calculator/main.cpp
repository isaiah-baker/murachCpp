#include <iostream>
#include <cmath>
#include "Circle.h"

using std::cout;
using std::cin;
using std::endl;
using std::round;

int main()
{
	// print name of program
	cout << "Circle Calculator" << endl << endl;

	// get radius from user
	double radius;
	cout << "Enter radius:  ";
	cin >> radius;

	// create Circle object
	Circle circle(radius);

	// round to 1 decimal place
	double circumference = round(circle.get_circumference() * 10) / 10;
	double area = round(circle.get_area() * 10) / 10;

	// write output to console
	cout << "Diameter:      " << circle.get_diameter() << endl
		<< "Circumference: " << circumference << endl
		<< "Area:          " << area << endl << endl
		<< "Bye!" << endl << endl;

	// return value that indicates normal program exit
	return 0;
}
