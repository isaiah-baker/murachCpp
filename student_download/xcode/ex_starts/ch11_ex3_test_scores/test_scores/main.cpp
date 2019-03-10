#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>

using namespace std;

int sort_descending(int i, int j) {
	return i > j;
}

void display(int value) {
	cout << value << ' ';
}

int main()
{
    cout << "The Test Scores program\n\n";

    cout << "Enter test scores from 0 to 100.\n"
        << "To end the program, enter -1.\n\n";

    vector<int> scores;
    int score = 0;
    while (score != -1) {
        cout << "Enter score: ";
        cin >> score;

        if (cin.fail()) {
            cin.clear();             // clear error bits
            cin.ignore(1000, '\n');  // discard input up to end of line
            cout << "Invalid number. Try again.\n";
        }
        else if (score > 100) {
            cout << "Score must be from 0 to 100. Try again.\n";
        }
        else if (score < -1) {
            cout << "Score can't be a negative number. Try again.\n";
        }
        else if (score > -1) {     // valid score – add to vector
            scores.push_back(score);
        }
    }

    if (scores.empty()) {                 // vector is empty
        cout << "\nNo scores entered\n.";
    }
    else {                                 // vector contains scores
		// sort scores in descending order
		sort(scores.begin(), scores.end(), sort_descending);

		// display sorted scores
		cout << endl;
		for_each(scores.begin(), scores.end(), display);
		cout << endl;

		// display minimum and maximum scores
		auto max_iter = max_element(scores.begin(), scores.end());
		cout << "Highest score: " << *max_iter << endl;
		auto min_iter = min_element(scores.begin(), scores.end());
		cout << "Lowest score: " << *min_iter << endl;

		// display number of scores equal to 100
		int count_100 = count(scores.begin(), scores.end(), 100);
		cout << "This student has " << count_100 << " perfect score(s)!" << endl;

        // calculate total of all scores
        int total = accumulate(scores.begin(), scores.end(), 0);

        // get the count and calculate the average
        auto score_count = scores.size();
        double average = static_cast<double>(total) / score_count;
        average = round(average * 10) / 10;

        // display the score count, total, and average
        cout << '\n'  // blank line
            << "Score count:   " << score_count << endl
            << "Score total:   " << total << endl
            << "Average score: " << average << endl << endl;
    }
}