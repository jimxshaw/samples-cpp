#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;
typedef char Str[15];

void SelectionSort(Str names[], int grades[], int count) {
	for (int i = 0; i < count; i++) {
		int largest = i;
		for (int j = largest + 1; j < count; j++)
			if (grades[j] > grades[largest]) largest = j;
		// temp2 is declared as a string but underneath it's still char
		// thus strcpy() is still needed
		Str temp;
		strcpy(temp, names[largest]);
		strcpy(names[largest], names[i]);
		strcpy(names[i], temp);
		int temp2 = grades[largest];
		grades[largest] = grades[i];
		grades[i] = temp2;
	}
}

void BubbleSort(Str names[], int grades[], int count) {
	for (int i = 0; i < count; i++)
		for (int j = 0; j < count; j++)
			if (grades[j + 1] > grades[j]) {
				Str temp;
				strcpy(temp, names[j]);
				strcpy(names[j], names[j + 1]);
				strcpy(names[j + 1], temp);
				int temp2 = grades[j];
				grades[j] = grades[j + 1];
				grades[j + 1] = temp2;
			}
}

void Print(Str names[], int grades[], int count) {
	for (int i = 0; i < count; i++) {
		cout << setw(15) << left << names[i] << setw(4) << right << grades[i] << endl;
	}
}

int main() {
	Str names[15];
	int grades[15],
		i = 0;
	char fn[30];

	cout << endl;

	cout << "Enter a file name: ";
	cin >> fn;
	ifstream infile(fn);

	if (infile) {
		for (; infile >> names[i] >> grades[i]; i++);
		infile.close();

		Print(names, grades, i);

		cout << endl;

		BubbleSort(names, grades, i);
		Print(names, grades, i);
	}
	else cout << "Invalid file" << endl;




	return 0;
}
