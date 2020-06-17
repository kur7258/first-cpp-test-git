#include <iostream>
#include <string>
using namespace std;

class Circle {
private:
	const double PI;//파이
public:
	double radius;//반지름
	Circle();
	Circle(double radius);
	Circle(Circle& c);
	double getArea()const;
	double getPerimeter()const;
	void print();
};


Circle::Circle() :PI(3.14),radius(0) { //초기화, 기초생성자
	
}
Circle::Circle(double radius):PI(3.14) {//반지름 값
	this->radius = radius;
}

Circle::Circle(Circle& copy) :PI(copy.PI) {//복사 생성자
	radius = copy.radius;
}
double Circle::getArea()const { //면적
	return radius * radius * PI;
}


double Circle::getPerimeter()const { //원주
	return radius * 2 * PI;
}


void Circle::print() {		//출력
	cout << "반지름 : " << radius << endl;
}

bool is_equal(Circle c1, Circle c2){

	if ( c1.radius == c2.radius) {
		return true;
	}
	else {
		return false;
	}
}


int main()
{
	bool result = 0;

	Circle* p = new Circle(5.0);
	Circle* p2 = new Circle(8.0);
	Circle c1(*p);
	Circle c2(*p2);
	cout << "원 면적 : " << p->getArea() << endl;
	cout << "원주 : " <<  p->getPerimeter() << endl;
	c1.print();
	c2.print();
	result = is_equal(c1, c2);
	if ( result == 1)
	{
		cout << "같습니다." << endl;
	}
	else cout << "다릅니다." << endl;
	
	return 0;
}