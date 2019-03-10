#include <iostream>
#include <cstring>

using namespace std;

// global constant
const int item_length = 51;

// function declarations
void alpha_sort(char items[][item_length], int size);
void reset_stream();

int main() {
    // create 2D array to hold C strings from user
    const int size = 5;
    char list[size][item_length];
    
    char item_type[item_length] = "";
    cout << "What kind of items are going to be in your list? ";
    cin.getline(item_type, item_length);
    reset_stream();
    cout << endl;
    
    // get list from user
    cout << "Please enter your top " << size << " " << item_type << ":\n";
    for (int i = 0; i < size; ++i) {
        cout << "#" << (i + 1) << ": ";
        cin.getline(list[i], item_length);
        reset_stream();
    }
    cout << endl;
    
    // sort and display the items in the list
    alpha_sort(list, size);
    cout << "Your top " << size << " " << item_type
    << ", sorted " << "alphabetically:\n"
    << "------------------------------------------\n";
    for (int i = 0; i < size; ++i) {
        cout << list[i] << endl;
    }
    cout << endl;
}

// an alphabetical bubble sort
void alpha_sort(char items[][item_length], int size) {
    bool is_swap;
    char temp[item_length] = "";  // temporary C string
    do {
        is_swap = false;                        // reset flag to false
        
        for (int i = 0; i < (size - 1); ++i) {  // stop at 2nd to last
            if (strcmp(items[i], items[i + 1]) > 0) {
                // swap current and next values
                strncpy(temp, items[i], item_length - 1);
                strncpy(items[i], items[i + 1], item_length - 1);
                strncpy(items[i + 1], temp, item_length - 1);
                
                // set flag to indicate a swap occurred
                is_swap = true;
            }
        }
    } while (is_swap); // if a swap occurred, continue loop
}

void reset_stream() {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

