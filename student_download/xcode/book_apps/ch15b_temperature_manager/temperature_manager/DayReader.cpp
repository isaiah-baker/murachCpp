#include <fstream>
#include <vector>
#include "DayReader.h"
#include "DayIOError.h"

using namespace std;

DayReader::DayReader(string filename_param) {
    filename = filename_param;
}

vector<Day> DayReader::load_temps() {
    vector<Day> days;
    Day day;
    ifstream input_file(filename);
    if (input_file) {
        while (input_file >> day.low_temp >> day.high_temp) {
            days.push_back(day);
        }
        input_file.close();
        return days;
    }
    else {
        throw DayIOError("Unable to open file: " + filename);
    }
}