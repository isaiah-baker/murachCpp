#include <iostream>
#include <iomanip>
#include <fstream>
#include <limits>
#include <string>

using namespace std;

int main()
{
    string filename = "temps.txt";

    cout << "The Temperature Manager program\n\n";

    cout << "COMMANDS\n"
        << "v - View temperatures\n"
        << "a - Add a temperature\n"
        << "x - Exit\n";

    char command = 'v';
    while (command != 'x') {
        // get command from user
        cout << endl;
        cout << "Command: ";
        cin >> command;
        cout << endl;

        if (command == 'v') {
            cout << "TEMPERATURES\n";
            cout << setw(8) << "Low" << setw(8) << "High" << endl;
            cout << "-------- -------" << endl;

            ifstream input_file;
            input_file.open(filename);

            double low;
            double high;
            if (input_file) {     // if file opened successfully...
                cout << fixed << setprecision(1);
                while (input_file >> low >> high) {
                    cout << setw(8) << low << setw(8) << high << '\n';
                }
                input_file.close();
            }
            else {
                cout << "Unable to open file.\n";
            }
        }
        else if (command == 'a') {
            double low;
            cout << "Enter low temp: ";
            cin >> low;

            double high;
            cout << "Enter high temp: ";
            cin >> high;

            ofstream output_file;
            output_file.open(filename, ios::app);
            output_file << low << '\t' << high << '\n';
            output_file.close();
            cout << "Temps have been saved.\n";
        }
        else if (command == 'x') {
            cout << "Bye!\n\n";
        }
        else {
            cout << "Invalid command. Try again.\n";
        }
    }
}
