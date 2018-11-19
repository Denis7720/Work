#include <iostream>
#include <ctime>
using namespace std;

struct mystruct
{
	int number;
	float pernumber;
	char words[11];
};

void print_int(mystruct* obj1, int N) {
	for (int i = 0; i < N; i++) {
		cout << obj1[i].number << "|";
	}
	cout << endl;
}

void print_float(mystruct* obj1, int N) {
	for (int i = 0; i < N; i++) {
		cout << obj1[i].pernumber << "|";
	}
	cout << endl;
}

void print_char(mystruct* obj1, int N) {
	for (int i = 0; i < N; i++) {
		cout << obj1[i].words << "|";
	}
	cout  << endl << endl;
}

int str_cmp(char *str1, char *str2)
{
	int l1 = 0, l2 = 0;
	while(*str1) {
		if(*str1 < 'Z' && *str1 > 'A') {
			l1++;
		}
		str1++;
	}
	while(*str2) {
		if(*str2 < 'Z' && *str2 > 'A') {
			l2++;
		}
		str2++;
	}

	return l1-l2;
}

void swap(mystruct *s1, mystruct *s2)
{
	mystruct tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

int diff(mystruct ex1, mystruct ex2) 
{
	int difference = str_cmp(ex1.words, ex2.words);
	if(difference == 0) {
		if(ex1.number > ex2.number) {
			return 0;
		}
		else if(ex1.pernumber > ex2.pernumber) {
			return 0;
		}
	}
	else if(difference > 0) {
		return 0;
	}
	return 1;
}

void sort(mystruct* obj1, int N) 
{	
	for (int i = 0; i < N - 1; i++) {
		if (diff(obj1[i], obj1[i+1]) == 1) {
			swap(&obj1[i], &obj1[i+1]);
			i = 0;
		}
	}
}

void getdata(mystruct* obj1, int N) 
{
	char letters[52];
	char L = 'A';
	char l = 'a';
	int r;
	srand (time(NULL));
	for (int u = 0; u < 26; u++) {
		letters[u] = L;
		L++;
	}
	for (int y = 26; y < 52; y++) {
		letters[y] = l;
		l++;
	}
	for (int i = 0; i < N; i++) {
		obj1[i].number = rand() % 10;
		obj1[i].pernumber = (rand() % 100) / 10.0;
		for  (int t = 0; t < 10; t++) {
			r = rand() % 52;
			obj1[i].words[t] = letters[r];
		}
	}
}

int main() 
{
	int N;

	cout << "Введите N: ";

	cin >> N;

	mystruct* obj1 = new mystruct[N];

	getdata(obj1, N);

	print_int(obj1, N);
	print_float(obj1, N);
	print_char(obj1, N);

	sort(obj1, N);

	print_int(obj1, N);
	print_float(obj1, N);
	print_char(obj1, N);

	delete []obj1;

	return 0;
}