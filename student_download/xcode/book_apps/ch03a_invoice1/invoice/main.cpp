#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    cout << "Invoice Total Calculator 1.0\n\n";

    // get subtotal from user
    double subtotal;
    cout << "Enter a subtotal: ";
    cin >> subtotal;

    // determine discount percent based on subtotal
    double discount_percent;
    if (subtotal >= 200) {
        discount_percent = .2;
    }
    else if (subtotal >= 100) {
        discount_percent = .1;
    }
    else {
        discount_percent = .05;
    }

    // calculate and round results
    double discount_amount = subtotal * discount_percent;
    discount_amount = round(discount_amount * 100) / 100;

    double invoice_total = subtotal - discount_amount;
    invoice_total = round(invoice_total * 100) / 100;

    // write the results data to the console
    cout << "Discount percent: " << discount_percent << endl
        << "Discount amount:  " << discount_amount << endl
        << "Invoice total:    " << invoice_total << endl << endl;

    cout << "Bye!\n\n";
}