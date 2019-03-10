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
    if (calculate_future_value(100, 3, 3) == 3771.46 &&
        calculate_future_value(25.25, 2.3, 7) == 2303.31 &&
        calculate_future_value(9999.99, 29.9, 99) == 2052116761478260736.00)
        cout << "Test for calculate_future_value() succeeded.\n";
    else
        cout << "Test for calculate_future_value() failed.\n";

    double fv = get_double("Enter future value: ", 0, 10000);
    cout << "Future value is valid.\n\n";
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

    // round future value to 2 decimal places
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
