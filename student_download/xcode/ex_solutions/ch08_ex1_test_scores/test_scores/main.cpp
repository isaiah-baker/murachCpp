#include <iostream>

using namespace std;

int main()
{
    cout << "Enter test scores from 0 to 100.\n"
        << "To end the program, enter -1.\n\n";

    // define variables 
    int score = 0;
    int count = 0;
    double total = 0.0;
    while (score != -1) {            // get all scores from the user
        cout << "Enter score: ";
        cin >> score;

		if (score == -1) {
			break;
		}

		if (score >= 0 && score <= 100) {
			total += score;
			count += 1;
		}
		else {
			cout << "Score must be from 0 through 100. Try again.\n";
		}
    }

    // calculate the average score - make sure not to divide by zero
    double avg_score = 0.0;
    if (count > 0) {
        avg_score = total / count;
    }

    // display the score count, total, and average
    cout << endl
        << "Score count:   " << count << endl
        << "Score total:   " << total << endl
        << "Average score: " << avg_score << endl;
}