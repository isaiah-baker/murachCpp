#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::round;

int main()
{
    // print name of program
    cout << "Gallons Converter" << endl << endl;

    // get gallons from user
    double gallons;
    cout << "Enter gallons: ";
    cin >> gallons;

    // convert gallons to liters
    double liters = gallons * 3.7854;
	liters = round(liters * 100) / 100;

	// convert gallons to quarts
	double quarts = gallons * 4;
	quarts = round(quarts * 100) / 100;

	// convert gallons to ounces
	double ounces = gallons * 128;
	ounces = round(ounces * 100) / 100;

    // write output to console
    cout << "Liters:        " << liters << endl
		 << "Quarts:        " << quarts << endl
		 << "Ounces:        " << ounces << endl << endl
         << "Bye!" << endl << endl;

    // return value that indicates normal program exit
    return 0;
}