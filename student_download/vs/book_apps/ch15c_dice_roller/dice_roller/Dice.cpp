#include "Dice.h"

void Dice::roll_all() {
    for (int i = 0; i < size(); ++i) {
        Die& die = at(i);
        die.roll();
    }
}