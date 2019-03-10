#ifndef MURACH_PRODUCT_H
#define MURACH_PRODUCT_H

#include <string>

class Product {
private:
    double price;
    int discount_percent;
    static int object_count;  // static data member

public:
    Product(std::string name = "", double price = 0.0, 
            int discount_percent = 0);

    std::string name;

    void set_price(double);
    double get_price() const { return price; }

    void set_discount_percent(int);
    int get_discount_percent() const { return discount_percent; }

    double get_discount_amount() const;
    double get_discount_price() const;

    static int get_object_count() {   // static function
        return object_count;
    }
};

#endif // MURACH_PRODUCT_H