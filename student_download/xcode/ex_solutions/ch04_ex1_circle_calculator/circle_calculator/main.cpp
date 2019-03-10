#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::pow;
using std::round;

int main()
{
	// print name of program
	cout << "Circle Calculator" << endl << endl;

	char choice = 'y';
	while (choice == 'y') {
		// get radius from user
		double radius;
		cout << "Enter radius:  ";
		cin >> radius;

        // make sure radius is a positive number
        if (radius <= 0) {
            cout << "Radius must be a positive number.\n\n";
            continue;
        }


		// make calculations
		double pi = 3.14159;
		double diameter = 2 * radius;
		double circumference = diameter * pi;
		double area = pi * pow(radius, 2.0);

		// round to 1 decimal place
		circumference = round(circumference * 10) / 10;
		area = round(area * 10) / 10;

		// write output to console
		cout << "Diameter:      " << diameter << endl
			<< "Circumference: " << circumference << endl
			<< "Area:          " << area << endl << endl;

		cout << "Enter another radius? (y/n): ";
		cin >> choice;
		cout << endl;
	}

	cout << "Bye!" << endl << endl;

	// return value that indicates normal program exit
    return 0;
}