#include <fstream>
#include <vector>
#include "DayWriter.h"

using namespace std;

DayWriter::DayWriter(string filename_param) {
    filename = filename_param;
}

void DayWriter::save_temps(const vector<Day>& days) {
    ofstream output_file(filename);
    for (Day day : days) {
        output_file << day.low_temp << '\t' << day.high_temp << '\n';
    }
    output_file.close();
}