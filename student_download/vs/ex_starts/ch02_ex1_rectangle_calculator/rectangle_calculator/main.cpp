#include <iostream>

using namespace std;

int main()
{
	cout << "Rectange Calculator";
	cout << "Enter height and width";
	double height;
	double width;
	cin >> height >> width;
	double result = height * width;
	cout << "Area: " << result;

	cout << "Bye!";

    return 0;
}

