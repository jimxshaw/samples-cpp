#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main() {
	char fileName[30],
		 ch;
	int vowels = 0,
		consonants = 0,
		digits = 0,
		lines = 1,
		other = 0;

	cout << "Enter a filename: ";
	cin >> fileName;
	ifstream infile;
	infile.open(fileName);

	cout << endl;

	cout << "Enter an output filename: ";
	cin >> fileName;
	ofstream outfile;
	outfile.open(fileName);

	cout << endl;

	if (infile) {
		while (infile.get(ch)) {
			cout << ch;
			outfile << ch;

			if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') vowels++;
			else if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z') consonants++;
			else if (ch >= '0' && ch <= '9') digits++;
			else if (ch == '\n') lines++;
			else other++;
		}
		infile.close();
		outfile.close();
	}
	else cout << "Input file is invalid" << endl;

	cout << endl;
	cout << endl;

	cout << "File information" << endl;
	cout << "Vowels: " << vowels << endl;
	cout << "Consonants: " << consonants << endl;
	cout << "Digits: " << digits << endl;
	cout << "Lines: " << lines << endl;
	cout << "Punctuation or symbol: " << other << endl;

	return 0;
}
