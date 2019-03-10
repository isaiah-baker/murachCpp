#include <string>
#include <cmath>
#include "Product.h"

using std::string;
using std::invalid_argument;

Product::Product(string p_name, double price, int discount_percent) {
    name = p_name;
    set_price(price);
    set_discount_percent(discount_percent);
}

void Product::set_price(double p_price) {
    if (p_price >= 0.0)
        price = round(p_price * 100) / 100;
    else
        throw invalid_argument("Price can't be negative.");
}

void Product::set_discount_percent(int p_discount_percent) {
    if (p_discount_percent >= 0 && p_discount_percent <= 100)
        discount_percent = p_discount_percent;
    else
        throw invalid_argument("Invalid range for discount percent.");
}

double Product::get_discount_amount() {
    double discount_amount = price * discount_percent / 100;
    return round(discount_amount * 100) / 100;
}

double Product::get_discount_price() {
    double discount_price = price - get_discount_amount();
    return round(discount_price * 100) / 100;
}