#ifndef MURACH_USEDBOOK_H
#define MURACH_USEDBOOK_H

#include <string>
#include "Book.h"

class UsedBook : public Book {
public:
    UsedBook(std::string name = "", double price = 0.0,
        int disc_pct = 0, std::string author_param = "") :
        Book(name, price, disc_pct, author_param) {
        // no code in constructor
    }

    std::string get_description() const {
        return name + " by " + Book::get_author() + " (Used)";
    }
};
#endif // MURACH_USEDBOOK_H