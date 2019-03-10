#ifndef MURACH_MEDIA_H
#define MURACH_MEDIA_H

#include <string>
#include "Product.h"

class Media: public Product {
protected:
    std::string format;
public:
    Media(std::string name = "", double price = 0.0,
        int disc_pct = 0, std::string format_param = "") : Product(name, price, disc_pct) {
        format = format_param;
    }
};
#endif // MURACH_MEDIA_H