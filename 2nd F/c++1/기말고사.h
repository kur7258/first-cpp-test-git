1번

#include<iostream>
#include<string>
using namespace std;

int main() {
	string c1;
	string c2;

	cout << "첫 번째 문자 입력 : ";
	cin >> c1;
	cout << "두 번째 문자 입력 : ";
	cin >> c2;

	if (c1 == c2) {
		cout << "같습니다." << endl;
	}
	else cout << "같지 않습니다." << endl;

	return 0;
}

2번

#include<iostream>
#include<string>
using namespace std;

class Dog {
private:
	string name; //이름
	string type; //종류
	int age; //나이
public:
	Dog();
	Dog(string n, string t, int a);
	void set_dog(string name, string type, int age);
	string get_name();
	string get_type();
	int get_age();
	void print();
};

Dog::Dog() :name(""), type(""), age(0) {}

Dog::Dog(string n, string t, int a) {
	this->name = n;
	this->type = t;
	this->age = a;
}

void Dog::set_dog(string name, string type, int age) {
	this->name = name;
	this->type = type;
	this->age = age;
}

string Dog::get_name() {
	return name;
}

string Dog::get_type() {
	return type;
}

int Dog::get_age() {
	return age;
}

void Dog::print() {
	cout << "이름 : " << name << endl;
	cout << "타입 : " << type << endl;
	cout << "나이 : " << age << endl;
}

int main() {

	Dog dog("김석진", "A", 23);

	dog.print();
	return 0;
}

3번

#include<iostream>
using namespace std;

class Info {
	int value;
public:
	Info() :value(0) {}
	Info(int v) { this->value = v; }
	void display() { cout << value << endl; }
};

void swap(Info& a, Info& b) {
	Info temp = 0;
	temp = a;
	a = b;
	b = temp;
}
int main() {
	Info A(100), B(200);
	A.display();
	B.display();

	swap(A, B);

	A.display();
	B.display();
	return 0;
}


6번

#include<iostream>
using namespace std;

class Circle {
private:
	int radius;
public:
	Circle() :radius(0) {}
	Circle(int r) { radius = r; }
	void setRadius(int r) { this->radius = r; }
	double getArea() { return 3.14 * radius * radius; }
};
int main() {
	Circle circle;
	Circle& refc = circle;
	refc.setRadius(10);
	cout << refc.getArea() << " " << circle.getArea() << endl;
	return 0;
}

7번

#include<iostream>
using namespace std;


class CPerson {
public:
	string m_Name;
	int m_ID;
	CPerson() :m_Name(""), m_ID(0) {}
	CPerson(string name, int id)
	{
		this->m_Name = name; this->m_ID = id;
	}
	CPerson(CPerson& obj) :m_Name(obj.m_Name), m_ID(obj.m_ID) {}
};
int main() {

	CPerson p1("김석진", 1);
	CPerson p2(p1);

	cout << p1.m_Name << endl;
	cout << p2.m_Name << endl;
	return 0;
}

2-1번

#include<iostream>
using namespace std;

class Circle {
private:
	double radius;
public:
	Circle(double r = 0.0) :radius(r) {}
	double getRadius() { return radius; }
	void print() { cout << "radius : " << radius << endl; }
};

bool is_equal(Circle& c1, Circle& c2) {
	if (c1.getRadius() == c2.getRadius()) {
		return true;
	}
	else return false;
}

int main() {
	Circle* p = new Circle(10.5);
	Circle* p2 = new Circle(6.0);

	is_equal(*p, *p2);
	p->print();

	return 0;
}

2-2번

#include<iostream>
using namespace std;

class Time {
	friend Time operator+(Time& t1, Time& t2);
	friend ostream& operator<<(ostream& os, Time& t);

private:
	int hours;
public:
	Time() { hours = 0; }
	Time(int h) { hours = h; }
	void print() { cout << "합 : " << hours << endl; }

	bool operator==(Time t);
};

Time operator+(Time& t1, Time& t2) {
	Time temp;
	temp.hours = t1.hours + t2.hours;
	return temp;
}

bool Time::operator==(Time t) {
	if (this->hours == t.hours) { return true; }
	else return false;
}

ostream& operator<<(ostream& os, Time& t) {
	os << "hours : " << t.hours << endl;
	return os;
}

int main() {
	Time a(4), b(4);
	Time c = a + b;
	c.print();
	cout << a << b << c;
	if (a == b) { cout << "같다" << endl; }
	else cout << "다르다" << endl;
	return 0;
}

클래스 상속 다형성 연산자중복 템플릿