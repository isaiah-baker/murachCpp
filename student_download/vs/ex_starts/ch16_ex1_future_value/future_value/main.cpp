#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include "console.h"

using namespace std;

// declare program-specific function
double calculate_future_value(double monthly_investment,
    double yearly_interest_rate, int years);

int main() {
    cout << "The Future Value Calculator\n\n";

    char choice = 'y';
    while (tolower(choice) == 'y') {
        // get input
        cout << "INPUT\n";
        double monthly_investment =
            console::get_double("Monthly Investment:   ", 0, 10000);
        double yearly_rate =
            console::get_double("Yearly Interest Rate: ", 0, 30);
        int years =
            console::get_int("Years:                ", 0, 100);
        cout << endl;

        // calculate future value
        double future_value = calculate_future_value(monthly_investment,
            yearly_rate, years);

        // display the output to user
        cout << "OUTPUT\n"
            << fixed << setprecision(2)
            << "Monthly Investment:   " << monthly_investment << "\n"
            << fixed << setprecision(1)
            << "Yearly Interest Rate: " << yearly_rate << "\n"
            << "Years:                " << years << "\n"
            << fixed << setprecision(2)
            << "Future Value:         " << future_value << "\n\n";

        // see if the user wants to continue
        choice = console::get_char("Continue? (y/n): ");
    };
    cout << "Bye!\n\n";
}

// define program-specific function
double calculate_future_value(double monthly_investment,
    double yearly_interest_rate, int years) {

    // convert yearly values to monthly values
    double monthly_rate = yearly_interest_rate / 12 / 100;
    int months = years * 12;

    // calculate future value
    double future_value = 0;
    for (int i = 0; i < months; ++i) {
        future_value = (future_value + monthly_investment) *
            (1 + monthly_rate);
    }
    return future_value;
}