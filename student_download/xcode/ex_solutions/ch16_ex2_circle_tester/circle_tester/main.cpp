#include <iostream>
#include <cmath>
#include "circle.h"

using std::cout;
using std::cin;
using std::endl;

// display() function is not needed after insertion operator is added
/*
void display(Circle circle) {
	cout << "radius=" << circle.get_radius()
		<< "|diameter=" << circle.get_diameter()
		<< "|circumference=" << circle.get_circumference()
		<< "|area=" << circle.get_area() << endl;
}
*/

int main() {
	// print name of program
	cout << "Circle Tester" << endl << endl;

	// create and display Circle object
	Circle circle1(20);
	cout << "CIRCLE 1:\n" << circle1 << endl;

	Circle circle2(10);
	cout << "CIRCLE 2:\n" << circle2 << endl;

	// test the addition and subtraction operators
	Circle circle3 = circle1 + circle2;
	cout << "CIRCLE 3 (CIRCLE1 + CIRCLE2):\n" << circle3 << endl;

	Circle circle4 = circle1 - circle2;
	cout << "CIRCLE 4 (CIRCLE1 - CIRCLE2):\n" << circle4 << endl;

	// test the increment operator
	cout << "CIRCLE 4 after ++:\n" << ++circle4 << endl;
}
