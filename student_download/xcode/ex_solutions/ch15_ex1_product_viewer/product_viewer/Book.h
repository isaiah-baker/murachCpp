#ifndef MURACH_BOOK_H
#define MURACH_BOOK_H

#include <string>
#include "Media.h"

class Book : public Media {
private:
    std::string author;
public:
    Book(std::string name = "", double price = 0.0, 
         int disc_pct = 0, std::string author_param = "",
         std::string format = "") :
         Media(name, price, disc_pct, format) {
        author = author_param;
    }

    void set_author(std::string author_param) {
        author = author_param;
    }
    std::string get_author() const {
        return author;
    }

    std::string get_description() const {
        return name + " by " + author + " - " + format;
    }
};
#endif // MURACH_BOOK_H