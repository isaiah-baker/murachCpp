#include <iostream>
#include <string>
#include <algorithm>
#include "MyList.h"

using namespace std;

int main() {
    cout << "The Task Manager program\n";
    cout << "Enter tasks and enter 'x' when done.\n\n";
    
    MyList<string> tasks;
    string task = "";
    while (true) {
        cout << "Enter task:  ";
        getline(cin, task);
        if (task == "x") {
            break;
        }
        else {
            tasks.push_back(task);
        }
    }
    cout << endl;
    
    cout << "My Task List\n";
    cout << "------------\n";
    int num = 0;
    for (string task : tasks) {
        cout << ++num << ") " << task << endl;
    }
    cout << endl;
}
