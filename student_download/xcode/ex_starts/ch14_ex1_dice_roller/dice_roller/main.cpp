#include <iostream>
#include "Die.h"
#include "Dice.h"

using namespace std;

int main() {
    cout << "The Dice Roller program\n\n";

    cout << " _____ \n";
    cout << "|o   o|\n";
    cout << "|o   o|\n";
    cout << "|o___o|\n";

    cout << " _____ \n";
    cout << "|o   o|\n";
    cout << "|  o  |\n";
    cout << "|o___o|\n";

    cout << " _____ \n";
    cout << "|o   o|\n";
    cout << "|     |\n";
    cout << "|o___o|\n";

    cout << " _____ \n";
    cout << "|o    |\n";
    cout << "|  o  |\n";
    cout << "|____o|\n";

    cout << " _____ \n";
    cout << "|o    |\n";
    cout << "|     |\n";
    cout << "|____o|\n";

    cout << " _____ \n";
    cout << "|     |\n";
    cout << "|  o  |\n";
    cout << "|____ |\n";

    cout << endl;

     // get number of dice from user
    int count;
    cout << "Enter the number of dice to roll: ";
    cin >> count;

    // create Dice object and add Die objects to it
    Dice dice;
    for (int i = 0; i < count; ++i) {
        Die die;
        dice.add_die(die);
    }

    char choice = 'y';
    while (choice == 'y') {
        // roll the dice
        dice.roll_all();
        cout << "YOUR ROLL: ";
        for (Die die : dice.get_dice()) {
            cout << die.get_value() << " ";
        }
        cout << endl;

        cout << "Roll again? (y/n): ";
        cin >> choice;
    }
    cout << "Bye!\n\n";
}