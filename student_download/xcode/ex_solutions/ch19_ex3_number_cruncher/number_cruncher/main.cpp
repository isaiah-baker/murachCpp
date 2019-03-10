#include <iostream>
#include <cstdlib>
#include <ctime>
#include "MyVector.h"      // NEW
#include <algorithm>
#include <numeric>
#include "find_midpoint.h" // NEW
#include "calc_median.h"   // NEW

using namespace std;

void display_int(int num) {
    cout << num << ' ';
}

int main() {
    cout << "The Number Cruncher program\n\n";

    // create an empty vector for a specified number of elements
    MyVector<int> numbers;
    numbers.reserve(12);

    // fill the vector with random numbers
    srand(time(nullptr));
    for (int i = 0; i < numbers.capacity(); ++i) {
        int number = rand() % 30;
        numbers.push_back(number);
    }

    // use STL algorithms
    cout << numbers.size() << " RANDOM NUMBERS: ";
    for_each(numbers.begin(), numbers.end(), display_int);
    cout << endl;

    sort(numbers.begin(), numbers.end());
    cout << numbers.size() << " SORTED NUMBERS: ";
    for_each(numbers.begin(), numbers.end(), display_int);
    cout << endl;

    int sum = accumulate(numbers.begin(), numbers.end(), 0);
    cout << "Sum = " << sum << ' ';

    auto avg = sum / numbers.size();
    cout << "Average = " << avg << '\n';

    auto min_iter = min_element(numbers.begin(), numbers.end());
    cout << "Min = " << *min_iter << ' ';

    auto max_iter = max_element(numbers.begin(), numbers.end());
    cout << "Max = " << *max_iter << '\n';

    // use custom algorithms
    auto mid_iter = find_midpoint(numbers.begin(), numbers.end());   // NEW
    cout << "Midpoint = " << *mid_iter << ' ';

    double median = calc_median(numbers.begin(), numbers.end());
    cout << "Median = " << median << "\n\n";
}