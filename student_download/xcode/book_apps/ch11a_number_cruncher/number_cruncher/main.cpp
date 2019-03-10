#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void display_int(int num) {
    cout << num << ' ';
}

int main() {
    cout << "The Number Cruncher program\n\n";
    
    // create an empty vector with space for 11 elements
    vector<int> numbers;
    numbers.reserve(11);
    
    // fill the vector with random numbers
    srand(time(nullptr));
    for (int i = 0; i < numbers.capacity(); ++i) {
        int number = rand() % 30;
        numbers.push_back(number);
    }
    
    cout << numbers.size() << " RANDOM NUMBERS: ";
    for_each(numbers.begin(), numbers.end(), display_int);
    cout << endl;
    
    sort(numbers.begin(), numbers.end());
    cout << numbers.size() << " SORTED NUMBERS: ";
    for_each(numbers.begin(), numbers.end(), display_int);
    cout << endl;
    
    int sum = accumulate(numbers.begin(), numbers.end(), 0);
    cout << "Sum = " << sum << ' ';
    
    int avg = sum / numbers.size();
    cout << "Average = " << avg << ' ';
    
    auto max_iter = max_element(numbers.begin(), numbers.end());
    cout << "Max = " << *max_iter << ' ';
    
    auto min_iter = min_element(numbers.begin(), numbers.end());
    cout << "Min = " << *min_iter << ' ';
    cout << endl;
    
    int num = 10;
    bool num_exists = binary_search(numbers.begin(), numbers.end(), num);
    if (num_exists) {
        auto c = count(numbers.begin(), numbers.end(), num);
        cout << "The number " << num << " occurs " << c << " time(s).\n";
    }
    else {
        cout << "These numbers do NOT include " << num << ".\n\n";
    }
}

