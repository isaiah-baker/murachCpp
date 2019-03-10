#ifndef MURACH_DAYREADER_H
#define MURACH_DAYREADER_H

#include <string>
#include <vector>
#include "Day.h"    // include Day structure

class DayReader {
private:
    std::string filename;
public:
    DayReader(std::string filename);
    std::vector<Day> load_temps();
};

#endif // MURACH_DAYREADER_H