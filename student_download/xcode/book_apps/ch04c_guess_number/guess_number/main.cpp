#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int upper_limit = 10;
    cout << "Guess the number!\n";
    cout << "I'm thinking of a number from 1 to " << upper_limit << "\n\n";

    // get a random number between 1 and the upper limit
    srand(time(nullptr));              // seed the rand() function
    int number = rand() % upper_limit; // number is >= 0 and < upper_limit
    ++number;                          // number is >= 1 and <= upper_limit

    int count = 1;
    while (true) {
        int guess;
        cout << "Your guess: ";
        cin >> guess;

        if (guess < 1 || guess > upper_limit) {
            cout << "Invalid guess. Try again.\n";
            continue;
        }

        if (guess < number) {
            cout << "Too low.\n";
        }
        else if (guess > number) {
            cout << "Too high.\n";
        }
        else {
            cout << "You guessed it in " << count << " tries.\n\n";
            break;
        }
        ++count;
    }
    cout << "Bye!\n\n";
}
