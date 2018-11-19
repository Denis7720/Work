#include <iostream>
#include <ctime>
using namespace std;

int* genRandArray(int size, int maxValue) {
	int* arr = new int[size];
	arr[0] = size;
	srand (time(NULL));

	for ( int i = 1; i < size + 1; i++) {
		arr[i] = rand() % maxValue;
	}

	return arr;
	delete[] arr;
}

void print(int* arr) {
	cout << arr[0] << ":";
	
	for ( int i = 1; i < arr[0] + 1; i++) {
	cout << " " << arr[i];	
	}
}

int main() {
	srand(time(NULL));
	int size = rand() % 10;
	int maxValue = 100;
	int* arr = genRandArray(size, maxValue);
	print(arr);
	delete[] arr;
	return 0;
}