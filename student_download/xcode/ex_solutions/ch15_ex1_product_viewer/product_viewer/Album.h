#ifndef MURACH_ALBUM_H
#define MURACH_ALBUM_H

#include <string>
#include "Media.h"

class Album : public Media {
private:
    std::string artist;
public:
    Album(std::string name = "", double price = 0.0,
        int disc_pct = 0, std::string artist_param = "",
        std::string format = "") :
        Media(name, price, disc_pct, format) {
        artist = artist_param;
    }

    void set_artist(std::string author_param) {
        artist = author_param;
    }
    std::string get_artist() const {
        return artist;
    }

    std::string get_description() const {
        return name + " (" + artist + ") - " + format;
    }
};
#endif // MURACH_ALBUM_H