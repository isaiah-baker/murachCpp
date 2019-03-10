#include <iostream>

using namespace std;

template<typename T>
void bubble_sort(T arr[], int size) {
	bool is_swap;
	T element;
	do {
		is_swap = false;                        // reset swap flag each iteration 
		for (int i = 0; i < (size - 1); ++i) {  // stop at 2nd to last 
			if (arr[i] > arr[i + 1]) {          // if current greater than next
				element = arr[i];               // swap current and next values
				arr[i] = arr[i + 1];
				arr[i + 1] = element;
				is_swap = true;                 // set flag to show swap occurred
			}
		}
	} while (is_swap);  // if a swap occurred, continue loop
}

int main()
{
	const int size = 5;
	int temps[size] = { 75, 64, 92, 88, 57 };
	cout << "Temperatures: ";
	for (int temp : temps) {
		cout << temp << ' ';
	}
	cout << endl;

	bubble_sort(temps, size);
	cout << "Sorted temperatures: ";
	for (int temp : temps) {
		cout << temp << ' ';
	}
	cout << endl << endl;

	double prices[size] = { 18.99, 9.99, 12.99, 24.99, 15.99 };
	cout << "Prices: ";
	for (double price : prices) {
		cout << price << ' ';
	}
	cout << endl;

	bubble_sort(prices, size);
	cout << "Sorted prices: ";
	for (double price : prices) {
		cout << price << ' ';
	}
	cout << endl << endl;

    return 0;
}

