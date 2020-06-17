#include<iostream>
using namespace std;

class Base {
public: 
int x;
Base():x(0){}
virtual void print() = 0;/* {
	cout << "Base Class print()" << endl;
}*/
};
class Derived :public Base {
public:
int y;
Derived() :y(20) { x = 100; }
void print() {
	cout << "Derived Class print()" << endl;
}
};
int main() {
	Base* b1 = new Derived;
	//Derived* d1 = b1;   //불가능
	Derived * d2 = (Derived*)b1; //가능
	Derived* d3 = new Derived;
	Base* b2 = d3;   //가능
	Derived* d4 = (Derived*)b2;    //가능
	b1->print();
	//d1->print();
	b2->print();
	return 0;
}