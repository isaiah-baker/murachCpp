#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

void get_monthly_weights(double* weights, string* months, int num_months);
double get_total(double* weights, int num_months);

int main()
{
	const int num_months = 12;
	string months[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	double weights[num_months] = { 0.0 };

	cout << "Welcome to the Weight Tracker program!\n\n"
		<< "Please enter your weight at the beginning of each month:\n";

	get_monthly_weights(weights, months, num_months);
	auto max = max_element(weights, weights + num_months);
	auto min = min_element(weights, weights + num_months);
	//double total = get_total(weights, num_months);
	double total = accumulate(weights, weights + num_months, 0.0);
	double avg = total / num_months;

	cout << "Maximum weight: " << *max << '\n';
	cout << "Minimum weight: " << *min << '\n';
	cout << "Average weight: " << avg << "\n\n";
}

void get_monthly_weights(double* weights, string* months, int num_months) {
	if (!weights || !months) {
		return;
	}
	for (int i = 0; i < num_months; ++i) {
		cout << months[i] << ": ";
		cin >> weights[i];
	}
	cout << '\n';
}

double get_total(double* weights, int num_months) {
	double total = 0;
	if (weights) {
		for (int i = 0; i < num_months; ++i) {
			total += weights[i];
		}
	}
	return total;
}
