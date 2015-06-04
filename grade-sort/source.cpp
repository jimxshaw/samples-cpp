#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;
typedef char Str[15];

// Three functions to calculate the average, highest and lowest grades
float GetAverage(int g[], int count) {
	float sum = 0;
	for (int i = 0; i < count; i++) {
		sum += g[i];
	}
	return sum / count;
}

int GetHighest(int g[], int count) {
	int hi = g[0];
	for (int i = 1; i < count; i++) {
		if (g[i] > hi) hi = g[i];
	}
	return hi;
}

int GetLowest(int g[], int count) {
	int lo = g[0];
	for (int i = 1; i < count; i++) {
		if (g[i] < lo) lo = g[i];
	}
	return lo;
}

// Two functions using different types of sorting algorithms
// Selection sort
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

// Bubble sort
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

// A function that accepts the high and low ranges of grades
// and count how many of them there are
int CountGrades(int grades[], int count, int hi, int lo) {
	int c = 0;
	for (int i = 0; i < count; i++) {
		if (grades[i] >= lo && grades[i] <= hi) c++;
	}
	return c;
}

// This function is used to print the sorted data in the file
void PrintSort(Str names[], int grades[], int count) {
	for (int i = 0; i < count; i++) {
		cout << setw(20) << left << names[i] << setw(4) << right << grades[i] << endl;
	}
	cout << endl;
	cout << "GRADE BREAKDOWN" << endl;
	cout << "A's: " << CountGrades(grades, count, 100, 90) << endl;
	cout << "B's: " << CountGrades(grades, count, 89, 80) << endl;
	cout << "C's: " << CountGrades(grades, count, 79, 70) << endl;
	cout << "D's: " << CountGrades(grades, count, 69, 60) << endl;
	cout << "F's: " << CountGrades(grades, count, 59, 0) << endl;
}

// This function is used to print the calculated data in the file
void PrintCalc(int highest, int lowest, int average) {
	cout << "Highest: " << highest << endl;
	cout << "Lowest: " << lowest << endl;
	cout << "Average: " << average << endl;
}

int main() {
	Str names[20];
	int grades[20],
		i = 0;
	char fn[30];

	cout << endl;

	cout << "Enter a file name: ";
	cin >> fn;
	ifstream infile(fn);

	if (infile) {
		for (; infile >> names[i] >> grades[i]; i++);
		infile.close();

		cout << endl;

		// Prints the unsorted data in the file
		cout << "UNSORTED: " << endl;
		PrintSort(names, grades, i);

		cout << endl;

		// Prints the sorted data in the file
		cout << "SORTED: " << endl;
		SelectionSort(names, grades, i);
		PrintSort(names, grades, i);

		cout << endl;

		// Calls the calculation functions and assign
		// them to proper variables
		int highest = GetHighest(grades, i);
		int lowest = GetLowest(grades, i);
		float average = GetAverage(grades, i);

		// Calls the print function with the above calculated
		// variables as arguments
		PrintCalc(highest, lowest, average);

		cout << endl;
	}
	else cout << "Invalid file" << endl;

	return 0;
}
