#include <iostream>
using namespace std;

class FirstClass
{
protected: int value;

public:
	FirstClass() {
		value = 0;
	}

	FirstClass(int input) {
		value = input;
	}

	~FirstClass() {
		cout << "Destructing first class" << endl;
	}

	void show_value() {
		cout << value << endl;
	}
};

class SecondClass : public FirstClass
{
public:
	SecondClass() : FirstClass() {}
	SecondClass(int inputS) : FirstClass(inputS) {}
	~SecondClass() {
		cout << "Destructing second class" << endl;
	}

	void valueSqr() {
		value *= value;
	}
};

int main() {
	FirstClass F_object(3);
	cout << "Syka";
	F_object.show_value();

	SecondClass S_object(4);
	cout << "GAvno";
	S_object.show_value();

	S_object.valueSqr();
	cout << "Pizdec";
	S_object.show_value();

	cout << endl;
	return 0;
}