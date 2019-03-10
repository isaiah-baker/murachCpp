#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cmath>

using namespace std;

// declare functions
double calculate_future_value(double monthly_investment,
    double yearly_interest_rate, int years);
double get_double(string prompt,
    double min = numeric_limits<double>::min(),
    double max = numeric_limits<double>::max());
int get_int(string prompt,
    int min = numeric_limits<int>::min(),
    int max = numeric_limits<int>::max());

int main() {
    cout << "The Future Value Calculator\n\n";

    char choice = 'y';
    while (choice == 'y' || choice == 'Y') {
        // get input
        cout << "INPUT\n";
        double monthly_investment =
            get_double("Monthly Investment:   ", 0, 10000);
        double yearly_rate =
            get_double("Yearly Interest Rate: ", 0, 30);
        int years =
            get_int("Years:                ", 0, 100);
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
        cout << "Continue? (y/n): ";
        cin >> choice;
        cout << endl;
    };

    cin.ignore(1000, '\n');   // discard all extra data
    cout << "Bye! Press [Enter] to exit...\n";
    cin.ignore();
}

/******************************************************
* Define functions
******************************************************/

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

    future_value = round(future_value * 100) / 100;
    return future_value;
}

double get_double(string prompt, double min, double max) {
    double num;
    while (true) {
        cout << prompt;
        cin >> num;
        if (!cin) {
            cout << "Error! Invalid number. Try again.\n";
            cin.clear();            // clear the failure flag
            cin.ignore(1000, '\n'); // discard any remaining characters 
            continue;
        }
        cin.ignore(1000, '\n');     // discard any remaining characters 

        if (num <= min) {
            cout << "Error! Number must be greater than "
                << min << ". Try again.\n";
        }
        else if (num >= max) {
            cout << "Error! Number must be less than "
                << max << ". Try again.\n";
        }
        else {
            return num;
        }
    }
}

int get_int(string prompt, int min, int max) {
    int num;
    while (true) {
        cout << prompt;
        cin >> num;
        if (!cin) {
            cout << "Error! Invalid number. Try again.\n";
            cin.clear();            // clear the failure flag
            cin.ignore(1000, '\n'); // discard any remaining characters 
            continue;
        }
        cin.ignore(1000, '\n');     // discard any remaining characters 

        if (num <= min) {
            cout << "Error! Number must be greater than "
                << min << ". Try again.\n";
        }
        else if (num >= max) {
            cout << "Error! Number must be less than "
                << max << ". Try again.\n";
        }
        else {
            return num;
        }
    }
}
