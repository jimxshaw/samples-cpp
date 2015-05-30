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

int main() {
	char fn[100];

	cout << "Enter an input file name: ";
	cin >> fn;
	ifstream infile(fn);

	if (infile) {
		while (infile.getline(fn, 100)) {
			ToUpperCase(fn);
			cout << fn << endl;
		}
		infile.close();
	}
	else {
		cout << "Invalid file" << endl;
	}




	return 0;
}
