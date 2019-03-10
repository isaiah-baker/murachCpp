#include <iostream>
#include "Die.h"
#include "Dice.h"

using namespace std;

int main() {
    Dice dice = Dice();
    dice.push_back(Die());                  // function from vector class
    dice.push_back(Die());                  // function from vector class
    dice.roll_all();
    Die die = dice[0];                      // operator from vector class
    dice.insert(dice.begin(), Die());       // function from vector class
    dice.pop_back();                        // function from vector class
    cout << "Die value: " << die.get_value() << endl;
    cout << "Dice count: " << dice.size() << endl;  // function from vector class
}

int test() {
    cout << "The Dice Roller program\n\n";

     // get number of dice from user
    int count;
    cout << "Enter the number of dice to roll: ";
    cin >> count;

    // create Dice object and add Die objects to it
    Dice dice;
    for (int i = 0; i < count; ++i) {
        Die die;
        dice.push_back(die);
    }

    char choice = 'y';
    while (choice == 'y') {
        // roll the dice
        dice.roll_all();
        cout << "YOUR ROLL: ";
        for (Die die : dice) {
            cout << die.get_value() << " ";
        }
        cout << endl;

        cout << "Roll again? (y/n): ";
        cin >> choice;
    }
    cout << "Bye!\n\n";

    return 0;
}