#include <iostream>
using namespace std;

class A
{
protected:
	int a, b, c;

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
		print(a, b, c);
	}
	
	void print(int ba, int bb, int bc) {
		cout << "I am a base class method!" << endl;
		cout << "a: " << a << "\t" << "b: " << b << "\t" << "c: " << c << endl;
	}
	void print(char ba, char bb, char bc) {
		cout << "I am a derived class method!" << endl;
		cout << "Ba: " << ba << "\t" << "Bb: " << bb << "\t" << "Bc: " << bc << endl;
	}
	
};

class B : public A
{
private: 
	char ba, bb, bc;

public:
	using A::print;
	B(): A() {}
	B(char date_ba, char date_bb, char date_bc) {
		cout << "Constructing class B" << endl;
		setFe(date_ba, date_bb, date_bc);
	}
	~B() {
		cout << "Destructing class B";
	}

	void setFe(char date_ba, char date_bb, char date_bc) {
		ba = date_ba;
		bb = date_bb;
		bc = date_bc;
	}

	void getFe() {
		print(ba, bb, bc);
	}
};

void statics() {
	char a = 'q';
	char f = 'e';
	char z = 'z';
	A objA1, objA2(1, 2, 3);
	B objB1, objB2(a, f, z);
	objA2.getOne();
	objB2.getFe();
}

void dinamics() {
	char a = 'y';
	char f = 'u';
	char z = 'i';
	A *objA1 = new A;
	A *objA2 = new A(11, 12, 13);
	B *objB1 = new B;
	B *objB2 = new B(a, f, z);
	objA2->getOne();
	objB2->getFe();
	delete objA1;
	delete objA2;
	delete objB1;
	delete objB2;
}

int main() {
	statics();
	cout << endl;
	dinamics();
	return 0;
}