#ifndef MURACH_DAYWRITER_H
#define MURACH_DAYWRITER_H

#include <string>
#include <vector>
#include "Day.h"   // include Day structure

class DayWriter {
private:
    std::string filename;
public:
    DayWriter(std::string filename = "");
    void save_temps(const std::vector<Day>& temps);
};

#endif // MURACH_DAYWRITER_H