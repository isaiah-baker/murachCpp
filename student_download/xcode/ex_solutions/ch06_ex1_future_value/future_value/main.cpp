#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    cout << "The Future Value Calculator\n\n";

	vector<double> monthly_investments;
	vector<double> yearly_rates;
	vector<int> investment_years;
	vector<double> future_values;

    char choice = 'y';
    while (choice == 'y' || choice == 'Y') {
        double monthly_investment;
        cout << "Enter monthly investment:   ";
        cin >> monthly_investment;

        double yearly_rate;
        cout << "Enter yearly interest rate: ";
        cin >> yearly_rate;

        int years;
        cout << "Enter number of years:      ";
        cin >> years;

        // convert yearly values to monthly values
        double monthly_rate = yearly_rate / 12 / 100;
        int months = years * 12;

        // calculate future value
        double future_value = 0;
        for (int i = 1; i <= months; i++) {
            future_value = (future_value + monthly_investment) *
                (1 + monthly_rate);
        }

		// round to 2 decimal places and display
		future_value = round(future_value * 100) / 100;
		cout << "Future value:               " << future_value << "\n\n";

		// store values in vectors
		monthly_investments.push_back(monthly_investment);
		yearly_rates.push_back(yearly_rate);
		investment_years.push_back(years);
		future_values.push_back(future_value);

        // see if the user wants to continue
        cout << "Continue? (y/n): ";
        cin >> choice;
        cout << endl;
    }

	cout << fixed << setprecision(2);
	cout << setw(10) << "Monthly"
		 << setw(8) << "Yearly"
		 << endl;
	cout << setw(10) << "investment"
		 << setw(8) << "rate"
		 << setw(7) << "Years"
		 << setw(14) << "Future Value"
		 << endl;
	for (int i = 0; i < future_values.size(); ++i) {
		cout << setw(10) << monthly_investments[i]
			 << setw(8) << yearly_rates[i]
			 << setw(7) << investment_years[i]
			 << setw(14) << future_values[i]
			 << endl;
	}

	cout << endl;
    cout << "Bye! ";
}