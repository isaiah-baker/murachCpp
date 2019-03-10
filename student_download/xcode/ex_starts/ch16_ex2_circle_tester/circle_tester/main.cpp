#include <iostream>
#include <cmath>
#include "circle.h"

using std::cout;
using std::cin;
using std::endl;

void display(Circle circle) {
	cout << "radius=" << circle.get_radius()
		<< "|diameter=" << circle.get_diameter()
		<< "|circumference=" << circle.get_circumference()
		<< "|area=" << circle.get_area() << endl;
}

int main() {
	// print name of program
	cout << "Circle Tester" << endl << endl;

	// create and display Circle object
	Circle circle1(20);
	cout << "CIRCLE 1:\n";
	display(circle1);
	cout << endl;

	Circle circle2(10);
	cout << "CIRCLE 2:\n";
	display(circle2);
	cout << endl;

	// test the addition and subtraction operators

	// test the increment operator
}
