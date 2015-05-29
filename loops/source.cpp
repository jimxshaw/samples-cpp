#include <iostream>
#include <fstream>

using namespace std;

int main() {
	char fn[100];
	int vowels = 0,
		consonants = 0,
		digits = 0,
		blanks = 0;

	cout << "Enter an input file name: ";
	cin >> fn;
	ifstream infile(fn);

	if (infile) {
		while (infile.getline(fn, 100)) {
			for (int i = 0; i < strlen(fn); i++) {
				if (fn[i] == 'a' || fn[i] == 'e' || fn[i] == 'i' || fn[i] == 'o' || fn[i] == 'u' || fn[i] == 'A' || fn[i] == 'E' || fn[i] == 'I' || fn[i] == 'O' || fn[i] == 'U')
					vowels++;
				else if (fn[i] >= 'a' && fn[i] <= 'z' || fn[i] >= 'A' && fn[i] <= 'Z') consonants++;
				else if (fn[i] >= '0' && fn[i] <= '9') digits++;
				else if (fn[i] == ' ') blanks++;
			}
		}
		infile.close();
	}
	else {
		cout << "Invalid file" << endl;
	}

	cout << endl;
	cout << "Input file info" << endl;
	cout << "Vowels: " << vowels << endl;
	cout << "Consonants: " << consonants << endl;
	cout << "Digits: " << digits << endl;
	cout << "Blanks: " << blanks << endl;

	cout << endl;

	return 0;
}
