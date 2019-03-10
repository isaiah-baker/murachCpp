#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

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

void display_accounts(string first, string last, string password, string email) {
	ifstream input_file(accounts_file);
	if (input_file) {
		int col_width = 10;
		cout << left
			<< setw(col_width * 3) << "Name"
			<< setw(col_width * 4) << "Email" << endl;
		while (input_file >> first >> last >> password >> email) {
			cout << setw(col_width * 3) << first + ' ' + last
				<< setw(col_width * 4) << email << endl;
		}
		input_file.close();
	}
	cout << endl;
}

void write_account_to_file(const string first, const string last, const string password, const string email) {
	ofstream output_file(accounts_file, ios::app);
	if (output_file) {
		output_file << first << '\t'
			<< last << '\t'
			<< password << '\t'
			<< email << '\n';
		output_file.close();
	}
}

int main()
{
    cout << "Create Account List\n\n";

	string first_name;
	string last_name;
	string password;
	string email;
	display_accounts(first_name, last_name, password, email);

	char another = 'y';
	while (tolower(another) == 'y') {
		cout << "First name: ";
		getline(cin, first_name);
		cout << "Last name: ";
		getline(cin, last_name);
		cout << "Password: ";
		getline(cin, password);
		cout << "Email: ";
		getline(cin, email);

		write_account_to_file(first_name, last_name, password, email);
		cout << endl << email << " was added for " 
			<< first_name + ' ' + last_name << endl << endl;

		cout << "Enter another account? (y/n): ";
		cin >> another;
		cin.ignore();
		cout << endl;
	}

	display_accounts(first_name, last_name, password, email);
}
