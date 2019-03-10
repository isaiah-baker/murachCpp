#ifndef MURACH_DICE_H
#define MURACH_DICE_H

#include <vector>
#include "Die.h"

class Dice : public std::vector<Die>
{
public:
    Dice() : vector<Die>() {};
    void roll_all();
};

#endif // MURACH_DICE_H