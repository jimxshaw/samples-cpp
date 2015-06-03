#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;
typedef char Str[15];

void SelectionSort(int grades[], int count) {
	for (int i = 0; i < count; i++) {
		int largest = i;
		for (int j = largest + 1; j < count; j++)
			if (grades[j] > grades[largest]) largest = j;
		int temp = grades[largest];
		grades[largest] = grades[i];
		grades[i] = temp;
	}
}

void BubbleSort(int grades[], int count) {
	for (int i = 0; i < count; i++)
		for (int j = 0; j < count; j++)
			if (grades[j + 1] > grades[j]) {
				int temp = grades[j];
				grades[j] = grades[j + 1];
				grades[j + 1] = temp;
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


	}
	else cout << "Invalid file" << endl;




	return 0;
}
