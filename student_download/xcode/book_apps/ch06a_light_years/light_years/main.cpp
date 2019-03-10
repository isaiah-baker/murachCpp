#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    cout << "Light Years Calculator\n\n";

    double light_years;
    cout << "Enter light years: ";
    cin >> light_years;

    // define three constants
    const double miles_per_light_year = 5.879e+12;
    const double km_per_light_year = 9.461e+12;
    const double parsec_per_light_year = 0.306601;

    // calculate miles and kilometers
    double miles = light_years * miles_per_light_year;
    double km = light_years * km_per_light_year;
    double parsecs = light_years * parsec_per_light_year;

    // display the results
    cout << endl << setprecision(8)
        << "SCIENTIFIC NOTATION\n"
        << "Miles:             " << miles << endl
        << "Kilometers:        " << km << endl
        << "Parsecs:           " << parsecs << endl << endl;

    cout << fixed
        << "FIXED NOTATION\n"
        << "Miles:             " << setw(24) << miles << endl
        << "Kilometers:        " << setw(24) << km << endl
        << "Parsecs:           " << setw(24) << parsecs << endl << endl;

    cout << "Bye!\n\n";
}