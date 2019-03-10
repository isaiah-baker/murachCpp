#include <iostream>

using namespace std;

void display_scores(int scores[], int score_count);
double calculate_total(int scores[], int score_count);

int main() {
 	const int cols = 3;
    const int rows = 20;
    int scores[rows][cols] { 0 };  // set each element in array to 0

    cout << "The Test Scores program\n\n";

    cout << "Enter test scores (" << cols << " per student, " << rows << " max students.)\n"
         << "Make sure each score is between 0 and 100.\n"
         << "To end the program, enter -1.\n\n";

	// initialize student counter, score counter, and score variables
	int student_count = 0, score_count = 0, score = 0;

	// prevent out of bounds access by making sure
	// student count is less than the number of rows
	while (score != -1 && student_count < rows) {
		cout << "Student " << (student_count + 1) << endl;
		score_count = 0;
		score = 0;
		// prevent out of bounds access by making sure
		// score count is less than the number of columns
		while (score != -1 && score_count < cols) {
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
				scores[student_count][score_count] = score;   // store score in array
				++score_count;                 // increment score count
			}
		}
		++student_count;
		cout << endl;
	}

    if (student_count == 0) {
        cout << "No scores entered.\n\n";
    }
    else {
        // calculate and display total and average scores
		int row = 0;
		while (row < student_count - 1) {
			cout << "Student " << (row + 1) << ": ";
			display_scores(scores[row], cols);

			double total = calculate_total(scores[row], cols);
			double average = total / cols;
			average = round(average * 10) / 10;
			cout << "\tAvg score: " << average << endl;
			++row;
		}
		cout << endl;
    }
	    return 0;
}

void display_scores(int scores[], int score_count) {
	for (int i = 0; i < score_count; ++i) {
		cout << scores[i] << ' ';
	}
}

double calculate_total(int scores[], int score_count) {
	double total = 0.0;
	for (int i = 0; i < score_count; ++i) {
		total += scores[i];
	}
	return total;
}