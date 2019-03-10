#include <iostream>    // a preprocessor directive, not a statement

using namespace std;

int main()
{
    cout << "Welcome to the Calorie Calculator\n\n";
    
    // get number of servings from user
    double servings;
    cout << "Enter servings per food item: ";
    cin >> servings;
    
    // get number of calories from user
    double calories;
    cout << "Enter calories per serving: ";
    cin >> calories;
    
    // calculate total calories
    double total_calories = servings * calories;
    
    // display total calories
    cout << "Total calories: " << total_calories << endl << endl;
    
    return 0;
}

