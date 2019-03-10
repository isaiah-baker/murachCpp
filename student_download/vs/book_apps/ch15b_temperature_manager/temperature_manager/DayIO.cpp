#include <string>
#include "DayIO.h"

DayIO::DayIO(std::string filename) : 
    DayReader(filename), DayWriter(filename)
{}