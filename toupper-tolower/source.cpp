#include <iostream>
#include <fstream>

using namespace std;

void ToUpperCase(char s[]) {
	for (int i = 0; i < strlen(s); i++) {
		s[i] = toupper(s[i]);
	}
}

void ToLowerCase(char s[]) {
	for (int i = 0; i < strlen(s); i++) {
		s[i] = tolower(s[i]);
	}
}

int CountConsonants(char s[]) {
	int c = 0;
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U');
		else if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z') c++;
	}
	return c;
}

int CountCommas(char s[]) {
	int c = 0;
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == ',') c++;
	}
	return c;
}

int main() {
	char fn[100];

	cout << "Enter an input file name: ";
	cin >> fn;
	ifstream infile(fn);

	if (infile) {
		int input,
			consonants = 0,
			commas = 0;

		cout << "How do you want your file converted?" << endl;
		cout << "Input 1 for upper case or input 2 for lower case: ";
		cin >> input;

		cout << endl;

		if (input == 1) {
			while (infile.getline(fn, 100)) {
				consonants += CountConsonants(fn);
				commas += CountCommas(fn);
				ToUpperCase(fn);
				cout << fn << endl;
				cout << endl;
				cout << "Consonants: " << consonants << endl;
				cout << "Commas: " << commas << endl;
			}
		}
		else if (input == 2) {
			while (infile.getline(fn, 100)) {
				consonants += CountConsonants(fn);
				commas += CountCommas(fn);
				ToLowerCase(fn);
				cout << fn << endl;
				cout << endl;
				cout << "Consonants: " << consonants << endl;
				cout << "Commas: " << commas << endl;
			}
		}
		else {
			cout << "Invalid input" << endl;
		}

		infile.close();
	}
	else {
		cout << "Invalid file" << endl;
	}

	return 0;
}
