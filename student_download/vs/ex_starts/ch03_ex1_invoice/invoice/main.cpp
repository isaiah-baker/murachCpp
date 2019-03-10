#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // display title
    cout << "The Invoice Total Calculator 2.0\n\n";

    // get input
    char customer_type;
    cout << "Enter customer type (r/w): ";
    cin >> customer_type;

    double subtotal;
    cout << "Enter subtotal:            ";
    cin >> subtotal;

    // set discount percent
    double discount_percent;
    if (tolower(customer_type) == 'r') {           // RETAIL
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
    else if (tolower(customer_type) == 'w') {     // WHOLESALE
        if (subtotal < 500) {
            discount_percent = .4;
        }
        else {
            discount_percent = .5;
        }
    }
    else {                                       // OTHER
        discount_percent = .0;
    }

    // calculate and round results
    double discount_amount = subtotal * discount_percent;
    discount_amount = round(discount_amount * 100) / 100;

    double invoice_total = subtotal - discount_amount;
    invoice_total = round(invoice_total * 100) / 100;

    // display output
    cout << "Discount percent:          " << discount_percent << endl
         << "Discount amount:           " << discount_amount << endl
         << "Invoice total:             " << invoice_total << endl << endl;

    cout << "Bye!\n\n";
}