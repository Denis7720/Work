#include <iostream>
#include <ctime>
using namespace std;

int** genRandMatrix(int size, int maxValue) {
	cout << size << endl;
	int** matrix = new int*[size];
	srand(time(NULL));

	for ( int count = 0; count < size; count++) {
		int ter = rand() % 10;
		matrix[count] = new int[ter];
		matrix[count][0] = ter;
	}

	for ( int count_row = 0; count_row < size; count_row++) {
		for ( int count_column = 1; count_column < matrix[count_row][0] + 1; count_column++) {
			matrix[count_row][count_column] = rand() % maxValue;
		}
	}
	return matrix;
	delete[] matrix;
}

void print(int** matrix) {
	for ( int count_row = 0; count_row < matrix[0][0]; count_row++) {
		cout << endl;
		cout << matrix[count_row][0] << ":";
		for ( int count_column = 1; count_column < matrix[count_row][0] + 1; count_column++) {
			cout << matrix[count_row][count_column] << " ";
		}
	}
	cout << endl;
	delete[] matrix;
}

int main() {
	srand(time(NULL));
	int size = rand() % 10;
	int maxValue = 100;
	int** matrix = genRandMatrix(size, maxValue);
	print(matrix);
	delete[] matrix;
	return 0;
}