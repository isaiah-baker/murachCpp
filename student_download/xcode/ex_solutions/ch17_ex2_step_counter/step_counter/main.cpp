#include<iostream>
#include <algorithm>
#include <numeric>
#include "HeapArray.h"

using namespace std;

HeapArray get_weekly_steps(HeapArray steps, char* days, int num_days);

int main() {
    const int num_days = 7;
    char days[] = "MTWTFSS";
    HeapArray steps(num_days);

    cout << "Welcome to the Weekly Step Counter program!\n\n"
              << "Please enter your steps for the week:\n";

    steps = get_weekly_steps(steps, days, num_days);
    double total = accumulate(steps.begin(), steps.end(), 0);
    double avg = total / num_days;

    cout << "Total steps for the week:  " << total << '\n'
              << "Average daily steps:       " << avg << "\n\n";
}

HeapArray get_weekly_steps(HeapArray steps, char* days, int num_days) {
    for (int i = 0; i < num_days; ++i) {
        cout << days[i] << ": ";
        cin >> steps[i];
    }
    std::cout << '\n';
	return steps;
}
