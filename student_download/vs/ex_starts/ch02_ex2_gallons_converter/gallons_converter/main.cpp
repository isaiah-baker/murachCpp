#include <iostream>

using namespace std;

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

    // write output to console
    cout << "Liters:        " << liters << endl << endl
         << "Bye!" << endl << endl;

    // return value that indicates normal program exit
    return 0;
}