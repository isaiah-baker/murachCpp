#include "Product.h"

#include <string>
#include <cmath>

using std::string;
using std::invalid_argument;

int Product::object_count = 0;  // initialize static data member

Product::Product(string name_param, double price, int discount_pct) {
    ++object_count;    // increment static data member
    name = name_param;
    set_price(price);
    set_discount_percent(discount_pct);
}

void Product::set_price(double price_param) {
    if (price_param >= 0.0)
        price = round(price_param * 100) / 100;
    else
        throw invalid_argument("Price can't be negative.");
}

void Product::set_discount_percent(int disc_pct_param) {
    if (disc_pct_param >= 0 && disc_pct_param <= 100)
        discount_percent = disc_pct_param;
    else
        throw invalid_argument("Invalid range for discount percent.");
}

double Product::get_discount_amount() const {
    double discountAmount = price * discount_percent / 100;
    return round(discountAmount * 100) / 100;
}

double Product::get_discount_price() const {
    double discountPrice = price - get_discount_amount();
    return round(discountPrice * 100) / 100;
}