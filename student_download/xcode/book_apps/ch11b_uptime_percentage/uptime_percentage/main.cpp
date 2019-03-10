#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>

using namespace std;

template<typename T> void display(T value);
map<string, vector<double> > load_uptimes(string filename);
void process_uptimes(const map<string, vector<double> >& uptimes);

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

int main() {
    const string filename = "uptimes.txt";
    cout << "Processing regional uptimes in " << filename << "...\n\n";
    auto uptimes = load_uptimes(get_fulll_path() + filename);
    
    if (uptimes.empty()) {
        cout << "No data or unable to open file.\n\n";
    }
    else {
        process_uptimes(uptimes);
    }
}

template<typename T>
void display(T value) {
    cout << value << "%  ";
}

map<string, vector<double> > load_uptimes(string filename) {
    map<string, vector<double> > uptimes;
    ifstream datafile(filename);
    
    if (datafile) {
        string line;
        while (getline(datafile, line)) {     // for each line in file...
            istringstream row(line);          // create string stream
            
            string region;                    // get region
            row >> region;
            
            vector<double> times;             // get uptimes
            double uptime;
            while (row >> uptime) {
                times.push_back(uptime);
            }
            
            uptimes[region] = times;          // add to map
        }
        datafile.close();
    }
    return uptimes;
}

void process_uptimes(const map<string, vector<double> >& uptimes) {
    for (auto p : uptimes) {
        string region = p.first;
        vector<double> times = p.second;    // get vector of uptimes
        double sum = accumulate(times.begin(), times.end(), 0.0);
        
        cout << region;
        cout << "\n\tAvg uptime - " << fixed << setprecision(2);
        cout << (sum / times.size()) << '%';
        
        cout << "\n\tDaily: " << setprecision(1);
        for_each(times.begin(), times.end(), display<double>);
        
        sort(times.begin(), times.end());
        cout << "\n\tSorted: ";
        for_each(times.begin(), times.end(), display<double>);
        cout << endl;
    }
    
    cout << "\nAvg uptime across all regions - ";
    double uptime_total = accumulate(uptimes.begin(), uptimes.end(), 0.0,
                                     [] (double total, auto p) {
                                         return total + accumulate(p.second.begin(), p.second.end(), 0.0);
                                     }
                                     );
    int uptime_count = accumulate(uptimes.begin(), uptimes.end(), 0,
                                  [] (int count, auto p) {
                                      return count + p.second.size();
                                  }
                                  );
    cout << setprecision(2) << (uptime_total / uptime_count) << "%\n\n";
}

