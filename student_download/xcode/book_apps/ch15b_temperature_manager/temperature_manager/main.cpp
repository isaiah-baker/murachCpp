#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <limits>
#include <vector>
#include "Day.h"
#include "DayIO.h"
#include "DayIOError.h"

using namespace std;

const string filename = "temps.txt";

// General purpose
char get_char(string prompt);

// Functions for console I/O
void display_menu();
void view_temps(const vector<Day>& days);
void add_temps(vector<Day>& days);
void remove_temps(vector<Day>& days);

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

int main() {
    cout << "The Temperature Manager program\n\n";

    display_menu();

    // get data from file
    DayIO dayIO(get_fulll_path() + filename);
    vector<Day> days;
    try {
        days = dayIO.load_temps();
    }
    catch (DayIOError e) {
        cout << e.what() << "\n"
            << "Exiting program. Bye!\n\n";
        return 0;
    }

    char command = 'v';
    while (command != 'x') {
        // get command from user
        command = get_char("Command: ");

        // execute appropriate command
        switch (tolower(command)) {
        case 'v':
            view_temps(days);
            break;
        case 'a':
            add_temps(days);
            break;
        case 'r':
            remove_temps(days);
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

void display_menu() {
    cout << "COMMANDS\n"
        << "v - View temperatures\n"
        << "a - Add temperatures\n"
        << "r - Remove temperatures\n"
        << "x - Exit\n\n";
}

void view_temps(const vector<Day>& days) {
    cout << "TEMPERATURES\n"
        << left << setw(4) << "Day"
        << right << setw(8) << "Low" << setw(8) << "High" << endl
        << "---- ------- -------" << endl;

    cout << fixed << setprecision(1);
    int day_num = 1;
    for (Day day : days) {
        cout << left << setw(4) << day_num
            << right << setw(8) << day.low_temp 
                     << setw(8) << day.high_temp << '\n';
        ++day_num;
    }
    cout << endl;
}

void add_temps(vector<Day>& days) {
    Day day;

    cout << "Enter low temp: ";
    cin >> day.low_temp;

    cout << "Enter high temp: ";
    cin >> day.high_temp;

    days.push_back(day);    // modify reference param

    // save data to file
    DayIO dayIO(get_fulll_path() + filename);
    dayIO.save_temps(days);
    cout << "Your temperatures have been added.\n\n";
}

void remove_temps(vector<Day>& days) {
    int day_num;
    cout << "Enter day to remove: ";
    cin >> day_num;

    int index = day_num - 1;
    if (index >= 0 && index < days.size()) {
        days.erase(days.begin() + index);  // modify reference param

        // save data to file
        DayIO dayIO(get_fulll_path() + filename);
        dayIO.save_temps(days);
        cout << "Temps for day " << day_num << " have been removed.\n\n";
    }
    else {
        cout << "Unable to remove day " << day_num << ". Invalid day.\n\n";
    }
}
