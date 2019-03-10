#ifndef MURACH_DAYIO_H
#define MURACH_DAYIO_H

#include <string>
#include "DayReader.h"
#include "DayWriter.h"

class DayIO : public DayReader, public DayWriter {
public:
    DayIO(std::string filename = "");
};

#endif // MURACH_DAYIO_H