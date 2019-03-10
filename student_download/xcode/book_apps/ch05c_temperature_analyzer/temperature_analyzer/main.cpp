#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>

using namespace std;

int main()
{
    cout << "Temperature Analyzer\n\n";

    // open input file
    string filename;
    ifstream infile;
    while (true) {
        cout << "Enter input filename: ";
        cin >> filename;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

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
        string file_path = "/Documents/murach/cpp/files/temp_analyzer/";
        filename = user_home + file_path + filename;
        
        infile.open(filename);   // if file opened successfully
        if (infile) {
            break;
        }
        else {
            cout << "Unable to open input file! Try again.\n";
        }
    }
    cout << "Input file (" << filename << ") opened successfully.\n\n";

    // start output - set floating-point formatting
    cout << fixed << setprecision(1);

    // output table header
    int col = 7;  // column width for display
    cout << setw(col) << "Low" << setw(col) << "High"
         << setw(col) << "Avg" << endl;
    cout << "-------------------------" << endl;

    // initialize variables used by the next loop
    double low = 0.0;
    double high = 0.0;
    double avg = 0.0;
    double avg_total = 0.0;
    double lowest = 1000.0;
    double highest = -1000.0;
    int lines_read = 0;
    int lines_processed = 0;

    // loop through each line in the input file
    string line;
    stringstream ss;
    while (getline(infile, line)) {
        ++lines_read;   // increment counter variable

        ss.str(line);   // replace string steam buffer with line
        ss.clear();     // reset string stream error bits

        // extract temps from string stream - if OK, process
        if (ss >> low >> high) {
            ++lines_processed;

            // calculate avg temp
            avg = (low + high) / 2;

            // display low, high, avg temps
            cout << setw(col) << low << setw(col) << high
                 << setw(col) << avg << endl;

            // update totals
            avg_total += avg;
            if (low < lowest)
                lowest = low;
            if (high > highest)
                highest = high;
        }
    }
    infile.close();

    cout << endl
         << lines_processed << " of "
         << lines_read << " lines successfully processed.\n\n";

    // calculate the daily avg
    double avg_daily = avg_total / lines_processed;

    // display calculations
    int col1 = 17;
    int col2 = 7;
    cout << left << setw(col1) << "Lowest temp: "
         << right << setw(col2) << lowest << endl
         << left << setw(col1) << "Highest temp: "
         << right << setw(col2) << highest << endl
         << left << setw(col1) << "Avg daily temp: "
         << right << setw(col2) << avg_daily << endl << endl;
}
