#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include "validation.h"

using namespace std;
using namespace validation;

struct Account {
	string first_name = "";
	string last_name = "";
	string password = "";
	string email = "";
	bool equals(Account&);        // member function declaration
};

// member function definition
bool Account::equals(Account& to_compare) {
	return (email == to_compare.email);
}

const string accounts_file = "accounts.txt";

string get_fulll_path() {
    // set a full path to the correct directory
    const char* home = getenv("HOME");
    string user_home = "";
    if (home) {
        user_home = home;
    }
    else {
        // if home isn't found, edit 'username' so it's correct for your system
        user_home = "/Users/username";
    }
    string file_path = "/Documents/murach/cpp/files/";
    return user_home + file_path;
}

vector<Account> read_accounts_from_file() {
	vector<Account> accounts;

	ifstream input_file(get_fulll_path() + accounts_file);
	if (input_file) {
		Account account;
		while (input_file >> account.first_name >> account.last_name >> account.password >> account.email) {
			accounts.push_back(account);
		}
		input_file.close();
	}
	return accounts;
}

void write_accounts_to_file(const vector<Account>& accounts) {
	ofstream output_file(get_fulll_path() + accounts_file);
	if (output_file) {
		for (Account account : accounts) {
			output_file << account.first_name << '\t'
				<< account.last_name << '\t'
				<< account.password << '\t'
				<< account.email << '\n';
		}
		output_file.close();
	}
}

void display_accounts(const vector<Account>& accounts) {
	int col_width = 10;
	cout << left
		<< setw(col_width * 3) << "Name"
		<< setw(col_width * 4) << "Email" << endl;

	for (Account account : accounts) {
		cout << setw(col_width * 3) << account.first_name + ' ' + account.last_name
			<< setw(col_width * 4) << account.email << endl;
	}
	cout << endl;
}

Account get_account() {
	Account account;
	cout << "First name: ";
	getline(cin, account.first_name);
	cout << "Last name: ";
	getline(cin, account.last_name);
	cout << "Password: ";
	getline(cin, account.password);
	cout << "Email: ";
	getline(cin, account.email);
	return account;
}

int main()
{
    cout << "Create Account List\n\n";
	vector<Account> accounts = read_accounts_from_file();
	display_accounts(accounts);

	char another = 'y';
	while (tolower(another) == 'y') {
		Account account = get_account();

		// check if account already exists
		bool already_exists = false;
		for (Account& a : accounts) {
			if (a.equals(account)) {
				already_exists = true;
				break;
			}
		}

		if (already_exists) {
			cout << account.email << " already exists - account not added.\n\n";
		}
		else {
			accounts.push_back(account);
			write_accounts_to_file(accounts);
			cout << endl << account.email << " was added for " 
				<< account.first_name + ' ' + account.last_name + '.' << endl << endl;
		}

		cout << "Enter another account? (y/n): ";
		cin >> another;
		cin.ignore();
		cout << endl;
	}

	// display the Account objects in the vector
	display_accounts(accounts);
}
