#include <iostream>
#include <cmath>
#include "console.h"

using namespace std;

void display_title() {
    cout << "Miles Per Gallon Calculator\n\n";
}

double calculate_mpg(double miles, double gallons) {
    if (miles <= 0.0) {
        throw invalid_argument("Error! Miles must be > 0.");
    }
    if (gallons <= 0.0) {
        throw invalid_argument("Error! Gallons must be > 0.");
    }
    double mpg = miles / gallons;
    mpg = round(mpg * 10) / 10;    // round to 1 decimal place
    return mpg;
}

int main() {
    display_title();

    // use console namespace to get valid values
    double miles = console::get_double("Enter miles driven:        ", 0.0);
    double gallons = console::get_double("Enter gallons of gas used: ", 0.0);
    
    // calculate and display mpg
    double mpg = calculate_mpg(miles, gallons);
    cout << "Miles per gallon:          " << mpg << "\n\n";

    // exit program
    cout << "Bye!\n\n";
    return 0;
}