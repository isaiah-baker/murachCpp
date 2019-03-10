#ifndef MURACH_MOVIE_H
#define MURACH_MOVIE_H

#include <string>
#include "Media.h"

class Movie : public Media {
private:
    int year;
public:
    Movie(std::string name = "", double price = 0.0, 
          int disc_pct = 0, int year_param = 1888, 
          std::string format = "") : Media(name, price, disc_pct, format) {
        year = year_param;
    }

    void set_year(int year_param) {
        year = year_param;
    }
    int get_year() const { 
        return year;
    }

    std::string get_description() const {
        return name + " (" + std::to_string(year) + ") - " + format;
    }
};
#endif // MURACH_MOVIE_H