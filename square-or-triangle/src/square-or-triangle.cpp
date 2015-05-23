//============================================================================
// Name        : square-or-triangle.cpp
// Author      : Jim Shaw
// Version     :
// Copyright   : Your copyright notice
// Description : A sample C++ project, Ansi-style
//============================================================================

// Prompt the user for an integer and a symbol.
// If the integer is even, the console will print out a hollow rectangle with
// the area of that integer using the symbol as the outline. If the integer
// is odd, the console will print out a triangle using that symbol of length
// and width of that integer.

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int userNum;
	cout << "Enter an integer: ";
	cin >> userNum;
	char userChar;
	cout << "Enter a symbol: ";
	cin >> userChar;

	cout << endl;
	if (userNum % 2 == 0) {
		int x = 0;
		while (x < userNum) {
			int y = 0;
			while (y < userNum) {
				if (x == 0 || x == userNum - 1 || y == 0 || y == userNum - 1) cout << userChar;
				int counter = 1;
				while (counter <= userNum - 2) {
					if (x == counter && y < userNum - 2) cout << " ";
					counter++;
				}
				y++;
			}
			cout << endl;
			x++;
		}
	}
	else {
		int x = 0;
		while (x < userNum) {
			int y = 0;
			while (y < x) {
				cout << userChar;
				y++;
			}
			cout << userChar;
			cout << endl;
			x++;
		}
	}

	cout << endl;

	return 0;
}
