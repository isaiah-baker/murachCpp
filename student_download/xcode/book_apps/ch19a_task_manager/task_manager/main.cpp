#include <iostream>
#include <string>
#include <algorithm>
#include "MyVector.h"

using namespace std;

int main() {
    cout << "The Task Manager program\n";
    cout << "Enter tasks and enter 'x' when done.\n\n";
    
    MyVector<string> tasks;
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
    
    sort(tasks.begin(), tasks.end());
    
    cout << "My Task List\n"
    << "------------\n";
    for (int i = 0; i < tasks.size(); ++i) {
        cout << (i + 1) << ") " << tasks[i] << endl;
    }
    cout << endl;
}
