/*
* Author:  Anne Boehm
* Date:    March 27, 2018
* Purpose: This program uses the console to get the
*          height and width of a rectangle from the
*	       user. Then, it calculates the area of the
*	       rectangle and displays the result.
*/

#include <iostream>

using namespace std;

int main()
{
	// print name of program
	cout << "Rectangle Calculator" << endl << endl;

	// get height and width from user
	double height;
	double width;
	cout << "Enter height and width: ";
	cin >> height >> width;

	// check height and width
	//if (height > 0) {
	//	if (width > 0) {

	//		// calculate area
	//		double area = height * width;

	//		// write output to console
	//		cout << "Area:                   " << area << endl << endl
	//			<< "Bye!" << endl << endl;
	//	}
	//	else {
	//		cout << "\nWidth must be greater than zero.\n\n";
	//	}
	//}
	//else {
	//	cout << "\nHeight must be greater than zero.\n\n";
	//}

	if (height > 0 && width > 0) {

			// calculate area
			double area = height * width;

			// write output to console
			cout << "Area:                   " << area << endl << endl
				<< "Bye!" << endl << endl;
	}
	else {
		cout << "\nHeight and width must be greater than zero.\n\n";
	}

	// return value that indicates normal program exit
    return 0;
}

