#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>

using namespace std;

int main() {
    cout << "The Invoice 3.0 program\n\n";

    // get input
    char customer_type;
    while (true) {
        cout << "Enter customer type (r/w): ";
        cin >> customer_type;
        if (tolower(customer_type) == 'r' || tolower(customer_type) == 'w') {
            break;
        }
        else {
            cout << "Invalid customer type! Please try again.\n";
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    double subtotal;
    while (true) {                    // loop continues until break statement
        cout << "Enter subtotal:            ";
        cin >> subtotal;

        if (cin.good()) {             // stream good - end loop
            break;
        }
        else if (cin.fail()) {        // stream OK - try again
            cout << "Invalid number! Please try again.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (cin.bad()) {         // stream bad - exit program
            cout << "Sorry, an unexpected error has occurred. Bye! ";
            return 0;
        }
    }

    // set discount percent
    double discount_percent;
    if (tolower(customer_type) == 'r') {          // RETAIL    
        if (subtotal < 100) {
            discount_percent = .0;
        }
        else if (subtotal >= 100 && subtotal < 250) {
            discount_percent = .1;
        }
        else {
            discount_percent = .2;
        }
    }
    else if (tolower(customer_type) == 'w') {   // WHOLESALE
        if (subtotal < 500) {
            discount_percent = .4;
        }
        else {
            discount_percent = .5;
        }
    }
    else {
        discount_percent = .0;
    }

    // calculate and round results
    double discount_amount = subtotal * discount_percent;
    discount_amount = round(discount_amount * 100) / 100;

    double invoice_total = subtotal - discount_amount;
    invoice_total = round(invoice_total * 100) / 100;

    // display output
    int col1 = 18;
    int col2 = 8;
    cout << fixed << setprecision(2) << endl   // use 2 decimal places
         << "INVOICE" << endl
         << left << setw(col1) << "Subtotal:"
         << right << setw(col2) << subtotal << endl
         << left << setw(col1) << "Discount percent:"
         << right << setw(col2) << discount_percent << endl
         << left << setw(col1) << "Discount amount:"
         << right << setw(col2) << discount_amount << endl
         << left << setw(col1) << "Invoice total:"
         << right << setw(col2) << invoice_total << endl;

    // display exit message
    cout << endl << left << "Bye! ";
}