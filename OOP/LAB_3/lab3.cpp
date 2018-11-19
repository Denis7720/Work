#include <iostream>
using namespace std;

class A
{
private:
	int a, b, c;
private:
	char d, e, f;
public:
	A() {
		cout << "Constructing class A_one" << endl;
	}
	A(int date_a, int date_b, int date_c) {
		cout << "Constructing class A_two" << endl;
		setOne(date_a, date_b, date_c);
	}
	~A() {
		cout << "Destructing class A" << endl;
	}

	void setOne(int date_a, int date_b, int date_c) {
		a = date_a;
		b = date_b;
		c = date_c;
	}

	void getOne() {
		cout << "a: " << a << "\t" << "b: " << b << "\t" << "c: " << c << endl;
	}

	void setTwo(char date_d, char date_e, char date_f) {
		d = date_d;
		e = date_e;
		f = date_f;
	}

	void getTwo() {
		cout << "d: " << d << "\t" << "e: " << e << "\t" << "f: " << f << endl;
	}

	void print() {
		cout << "I am a base class method!" << endl;
		getOne();
		getTwo();
	}
	
};

void statics() {

	A objA, objB(1, 2, 3);

	char d = 'd';
	char e = 'e';
	char f = 'f';

	objB.setTwo(d, e, f);
	objB.print();
}

void dinamics() {

	A *objA = new A;
	A *objB = new A(4, 5, 6);

	char d = 'g';
	char e = 'h';
	char f = 'j';

	objB->setTwo(d, e, f);
	objB->print();

	delete objA;
	delete objB;
}

int main() {

	statics();

	cout << endl;

	dinamics();
	
	return 0;
}