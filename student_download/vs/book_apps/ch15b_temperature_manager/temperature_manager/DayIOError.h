#ifndef MURACH_DAYIOERROR_H
#define MURACH_DAYIOERROR_H

#include <iostream>
#include <string>

class DayIOError : public std::runtime_error {
public:
    DayIOError(std::string message = "") : runtime_error(message) {};
};

#endif // MURACH_DAYIOERROR_H