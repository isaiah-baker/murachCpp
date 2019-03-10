#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <limits>
#include <vector>

using namespace std;

int main()
{
    string filename = "temps.txt";

    // set a full path to the correct file
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
    filename = user_home + file_path + filename;
    
    cout << "The Temperature Manager program\n\n";

    cout << "COMMANDS\n"
        << "v - View temperatures\n"
        << "a - Add temperatures\n"
        << "r - Remove temperatures\n"
        << "s - Save changes\n"
        << "x - Exit\n";

    // read low and high temps from file and store in vectors
    double low, high;
    vector<double> low_temps, high_temps;
    ifstream input_file;
    input_file.open(filename);
    if (input_file) {     // if file opened successfully...
        while (input_file >> low >> high) {
            low_temps.push_back(low);
            high_temps.push_back(high);
        }
        input_file.close();
    }
    else {
        cout << "\nUnable to open file. You may need to add temperatures.\n";
    }

    char command = 'v';
    while (command != 'x') {
        // get command from user
        cout << endl;
        cout << "Command: ";
        cin >> command;

        // initialize variables
        ofstream output_file;
        double low, high;
        int day_num, index;

        // execute appropriate command
        switch (command) {
        case 'v':
            cout << "TEMPERATURES\n"
                << left << setw(4) << "Day"
                << right << setw(8) << "Low" << setw(8) << "High" << endl
                << "---- ------- -------" << endl;

            cout << fixed << setprecision(1);
            day_num = 1;
            for (int i = 0; i < low_temps.size(); ++i) {
                low = low_temps[i];
                high = high_temps[i];
                cout << left << setw(4) << day_num
                    << right << setw(8) << low << setw(8) << high << '\n';
                ++day_num;
            }
            break;

        case 'a':
            cout << "Enter low temp: ";
            cin >> low;

            cout << "Enter high temp: ";
            cin >> high;

            low_temps.push_back(low);
            high_temps.push_back(high);
            break;

        case 'r':
            int day;
            cout << "Enter day to remove: ";
            cin >> day;

            index = day - 1;
            if (index >= 0 && index < high_temps.size()) {
                high_temps.erase(high_temps.begin() + index);
                low_temps.erase(low_temps.begin() + index);
            }

            cout << "Temps for day " << day << " have been removed.\n";
            break;

        case 's':
            output_file.open(filename);
            for (int i = 0; i < low_temps.size(); ++i) {
                low = low_temps[i];
                high = high_temps[i];
                output_file << low << '\t' << high << '\n';
            }
            output_file.close();
            cout << "Your changes have been saved.\n";
            break;

        case 'x':
            cout << "Bye!\n\n";
            break;

        default:
            cout << "Invalid command. Try again.\n";
            break;
        }
    }
}
