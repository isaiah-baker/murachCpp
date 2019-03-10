#ifndef MURACH_CONSOLE_H
#define MURACH_CONSOLE_H

#include <string>
#include <limits>

class Console {
public:
    // declare general-purpose functions
    static double get_double(std::string prompt,
        double min = std::numeric_limits<double>::min(),
        double max = std::numeric_limits<double>::max());
    static int get_int(std::string prompt,
        int min = std::numeric_limits<int>::min(),
        int max = std::numeric_limits<int>::max());
    static char get_char(std::string prompt,
        bool add_blank_line = true);
};

#endif // MURACH_CONSOLE_H
