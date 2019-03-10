#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <limits>
#include <vector>

using namespace std;

const string filename = "temps.txt";

// General purpose
char get_char(string prompt);

// Functions for file I/O
void load_temps(vector<double>& low, vector<double>& high);
void load_temps_with_check(vector<double>& low, vector<double>& high);
void save_temps(const vector<double>& low, const vector<double>& high);

// Functions for console I/O
void display_menu();
void view_temps(const vector<double>& low, const vector<double>& high);
void add_temps(vector<double>& low, vector<double>& high);
void remove_temps(vector<double>& low, vector<double>& high);

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
    string file_path = "/Documents/murach/cpp/files/temp_manager/";
    return user_home + file_path;
}

int main() 
{
    cout << "The Temperature Manager program\n\n";

    display_menu();

    // get temps from file
    vector<double> low_temps, high_temps;
    try {
        load_temps_with_check(low_temps, high_temps);
    }
    catch (const runtime_error& e) {
        cout << "Bye!\n\n";
        return 0;
    }

    char command = 'v';
    while (command != 'x') {
        // get command from user
        command = get_char("Command: ");

        // execute appropriate command
        switch (tolower(command)) {
        case 'v':
            view_temps(low_temps, high_temps);
            break;
        case 'a':
            add_temps(low_temps, high_temps);
            break;
        case 'r':
            remove_temps(low_temps, high_temps);
            break;
        case 'x':
            cout << "Bye!\n\n";
            break;
        default:
            cout << "Invalid command. Try again.\n\n";
            display_menu();
            break;
        }
    }
}

char get_char(string prompt) {
    char choice;
    cout << prompt;
    cin >> choice;

    cin.ignore(10000, '\n');
    return choice;
}

void load_temps(vector<double>& low_temps,
    vector<double>& high_temps) {
    double low, high;
    ifstream input_file(get_fulll_path() + filename);
    if (input_file) {
        while (input_file >> low >> high) {
            low_temps.push_back(low);
            high_temps.push_back(high);
        }
        input_file.close();
    }
    else {
        throw runtime_error("Error! Unable to open file: " + filename);
    }
}

void load_temps_with_check(vector<double>& low_temps,
    vector<double>& high_temps) {
    try {
        load_temps(low_temps, high_temps);
        cout << "Temperatures have been loaded.\n\n";
    }
    catch (const runtime_error& e) {
        cout << e.what() << endl;
        cout << "Unable to load temperatures from file.\n";

        char choice;
        cout << "Would you like to create a new file? (y/n): ";
        cin >> choice;
        cout << endl;

        if (choice == 'y') {
            cout << "OK. You can add temperatures now.\n";
        }
        else {
            cout << "Please make sure the file exists and try again.\n"
                 << "You may need to specify a full path to this file.\n";
            throw;
        }
    }
}

void save_temps(const vector<double>& low_temps,
    const vector<double>& high_temps) {
    ofstream output_file(get_fulll_path() + filename);
    for (int i = 0; i < low_temps.size(); ++i) {
        output_file << low_temps[i] << '\t' << high_temps[i] << '\n';
    }
    output_file.close();
}

void display_menu() {
    cout << "COMMANDS\n"
        << "v - View temperatures\n"
        << "a - Add temperatures\n"
        << "r - Remove temperatures\n"
        << "x - Exit\n\n";
}

void view_temps(const vector<double>& low_temps,
    const vector<double>& high_temps) {
    cout << "TEMPERATURES\n"
        << left << setw(4) << "Day"
        << right << setw(8) << "Low" << setw(8) << "High" << endl
        << "---- ------- -------" << endl;

    cout << fixed << setprecision(1);
    int day_num = 1;
    double low, high;
    for (int i = 0; i < low_temps.size(); ++i) {
        low = low_temps[i];
        high = high_temps[i];
        cout << left << setw(4) << day_num
            << right << setw(8) << low << setw(8) << high << '\n';
        ++day_num;
    }
    cout << endl;
}

void add_temps(vector<double>& low_temps, vector<double>& high_temps) {
    double low, high;

    cout << "Enter low temp: ";
    cin >> low;

    cout << "Enter high temp: ";
    cin >> high;

    low_temps.push_back(low);    // modifies reference param
    high_temps.push_back(high);  // modifies reference param
    save_temps(low_temps, high_temps);
    cout << "Your temperatures have been added.\n\n";
}

void remove_temps(vector<double>& low_temps, vector<double>& high_temps) {
    int day;
    cout << "Enter day to remove: ";
    cin >> day;

    int index = day - 1;
    if (index >= 0 && index < high_temps.size()) {
        high_temps.erase(high_temps.begin() + index);  // modifies reference param
        low_temps.erase(low_temps.begin() + index);    // modifies reference param
        save_temps(low_temps, high_temps);
        cout << "Temps for day " << day << " have been removed.\n\n";
    }
    else {
        cout << "Unable to remove day " << day << ". Invalid day.\n\n";
    }
}
