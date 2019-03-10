#include <iostream>

using namespace std;

enum class Department { marketing = 1, it, sales, other };

// function prototypes
void show_menu();
Department get_department();
bool check_criteria(Department);

int main() {
    cout << "The Monthly Bonus Calculator\n\n";
    show_menu();

    const double bonus_amt = 1000;
    Department dept = get_department();
    bool bonus = check_criteria(dept);
    if (bonus) {
        cout << "Congrats! You earned the $" << bonus_amt
            << " monthly bonus.\n\n";
    }
    else {
        cout << "Sorry! No bonus for you this month :(  Keep trying!\n\n";
    }

    return 0;
}

// function definitions
void show_menu() {
    cout << "DEPARTMENTS\n"
         << static_cast<int>(Department::marketing) << " - Marketing\n"
         << static_cast<int>(Department::it) << " - IT\n"
         << static_cast<int>(Department::sales) << " - Sales\n"
         << static_cast<int>(Department::other) << " - Other\n\n";
}

Department get_department() {
    cout << "Enter department number: ";
    int choice = 0;
    cin >> choice;

    Department dept = static_cast<Department>(choice);
    if (dept < Department::marketing || dept > Department::other) {
        return Department::other;
    }
    else {
        return dept;
    }
}

bool check_criteria(Department dept) {
    switch (dept) {
        case Department::marketing:
            int viral_campaigns;
            cout << "How many of your campaigns went viral this month?: ";
            cin >> viral_campaigns;
            return viral_campaigns >= 4;
        case Department::it:
            int trouble_tickets;
            cout << "How many trouble tickets did you close this month?: ";
            cin >> trouble_tickets;
            return trouble_tickets >= 10;
        case Department::sales:
            double sales;
            cout << "What were your total sales this month?: ";
            cin >> sales;
            return sales >= 1000;
        case Department::other:
            char supervisor_grade;
            cout << "What was your grade from your supervisor this month?: ";
            cin >> supervisor_grade;
            return tolower(supervisor_grade) == 'a';
    }
}