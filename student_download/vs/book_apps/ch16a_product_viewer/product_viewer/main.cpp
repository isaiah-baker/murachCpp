#include <iostream>
#include <string>
#include <vector>
#include "Product.h"

using namespace std;

void show_products(const vector<Product>& products) {
    cout << "PRODUCTS\n";
    int number = 0;
    for (Product product : products) {
        cout << ++number << ". " << product.name << endl;
    }
    cout << endl;
}

void show_product(Product p) {
    cout << "PRODUCT DATA\n"
        << "Name:             " << p.name << endl
        << "Price:            " << p.get_price() << endl
        << "Discount percent: " << p.get_discount_percent() << endl
        << "Discount amount:  " << p.get_discount_amount() << endl
        << "Discount price:   " << p.get_discount_price() << "\n\n";
}

int main() {
    cout << "The Product Viewer program\n\n";

    vector<Product> products;
    products.push_back(
        Product("Stanley 13 Ounce Wood Hammer", 12.99, 62));
    products.push_back(
        Product("National Hardware 3/4\" Wire Nails", 5.06, 0));
    products.push_back(
        Product("Economy Duct Tape, 60 yds, Silver", 7.24, 0));

    show_products(products);

    cout << Product::get_object_count() 
         << " Product objects have been created.\n\n";

    char choice = 'y';
    while (choice == 'y') {
        int number;
        cout << "Enter product number: ";
        cin >> number;
        cout << endl;

        Product product = products[number - 1];
        show_product(product);

        cout << "View another product? (y/n): ";
        cin >> choice;
        cout << endl;
    }
    cout << "Bye!\n\n";
}