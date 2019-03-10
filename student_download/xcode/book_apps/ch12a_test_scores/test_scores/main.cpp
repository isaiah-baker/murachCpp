#include <iostream>
#include <cmath>

using namespace std;

int calculate_total(int scores[], int score_count);

int main() {
    const int capacity = 50;
    int scores[capacity] { 0 };  // set each element in array to 0
    
    cout << "The Test Scores program\n\n";
    
    cout << "Enter test scores (" << capacity << " max).\n"
    << "Make sure each score is between 0 and 100.\n"
    << "To end the program, enter -1.\n\n";
    
    // initialize counter and score variables
    int score_count = 0, score = 0;
    
    // prevent out of bounds access by making sure
    // score count is less than capacity
    while (score != -1 && score_count < capacity) {
        cout << "Enter score: ";
        cin >> score;
        
        if (cin.fail()) {
            cin.clear();             // clear bad input flag
            cin.ignore(1000, '\n');  // discard input up to end of line
            cout << "Invalid number. Try again.\n";
        }
        else if (score > 100) {
            cout << "Score must be from 0 to 100. Try again.\n";
        }
        else if (score < -1) {
            cout << "Score can't be a negative number. Try again.\n";
        }
        else if (score > -1) {
            scores[score_count] = score;   // store score in array
            ++score_count;                 // increment score count
        }
    }
    cout << endl;
    
    if (score_count == 0) {
        cout << "No scores entered.\n\n";
    }
    else {
        // calculate total and average scores
        double total = calculate_total(scores, score_count);
        double average = total / score_count;
        average = round(average * 10) / 10;
        
        // display the score count, score total, and average score
        cout << "Score count:   " << score_count << endl
        << "Score total:   " << total << endl
        << "Average score: " << average << endl << endl;
    }
    
    return 0;
}

int calculate_total(int scores[], int score_count) {
    int total = 0.0;
    for (int i = 0; i < score_count; ++i) {
        total += scores[i];
    }
    return total;
}

