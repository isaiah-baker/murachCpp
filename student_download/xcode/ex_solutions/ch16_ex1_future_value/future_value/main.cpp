#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include "console.h"
#include "Finance.h"

using namespace std;

int main() {
    cout << "The Future Value Calculator\n\n";

    Console c;
    char choice = 'y';
    while (tolower(choice) == 'y') {
        // get input
        cout << "INPUT\n";
        double monthly_investment =
            c.get_double("Monthly Investment:   ", 0, 10000);
        double yearly_rate =
            c.get_double("Yearly Interest Rate: ", 0, 30);
        int years =
            c.get_int("Years:                ", 0, 100);
        cout << endl;

        // calculate future value
        double future_value = Finance::calculate_future_value(
            monthly_investment, yearly_rate, years);

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
        choice = c.get_char("Continue? (y/n): ");
    };
    cout << "Bye!\n\n";
}