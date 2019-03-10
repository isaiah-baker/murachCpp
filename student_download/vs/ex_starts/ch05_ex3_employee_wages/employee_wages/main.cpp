#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>

using namespace std;

int main()
{
	ifstream infile;
	infile.open("wages.txt");
	if (infile) {
		infile.close();
	}
}

