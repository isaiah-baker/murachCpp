#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	cout << "The Product Sales program\n\n";

	cout << "Enter product sales from 0 to 10,000.\n"
		<< "To end the program, enter -1.\n\n";

	vector<double> sales;
	double sale = 0.0;
	while (sale != -1) {
		cout << "Enter sales amount: ";
		cin >> sale;

		if (cin.fail()) {
			cin.clear();             // clear error bits
			cin.ignore(1000, '\n');  // discard input up to end of line
			cout << "Invalid number. Try again.\n";
		}
		else if (sale > 10000) {
			cout << "Score must be from 0 to 10,000. Try again.\n";
		}
		else if (sale < -1) {
			cout << "Score can't be a negative number. Try again.\n";
		}
		else if (sale > -1) {        // valid sale amount – add to vector
			sales.push_back(sale);
		}
	}

	if (sales.empty()) {             // vector is empty
		cout << "\nNo sales entered.\n\n";
	}
	else {                           // vector contains sales
									 // calculate total of all sales
		double total = 0.0;
		for (double sale : sales) {
			total += sale;
		}

		// get the count and calculate the average
		auto sales_count = sales.size();
		double average = static_cast<double>(total) / sales_count;
		average = round(average * 100) / 100;

		// display the sales count, total, and average
		cout << '\n'
			<< "Sales count:   " << sales_count << endl
			<< "Sales total:   " << total << endl
			<< "Average sales: " << average << endl << endl;
	}
}

