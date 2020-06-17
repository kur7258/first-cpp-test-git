#include <iostream>
#include <string>
using namespace std;

class Point {
private:
	int x;
	int y;
public:
	Point();
	Point(int a, int b);
	void print();
};

Point::Point() : x(0), y(0)
{
}

Point::Point(int a, int b) : x(a), y(b)
{
}

void Point::print()
{
	cout << "( " << x << ", " << y << " )\n";
}

class Circle {
private:
	double radius;//반지름
	Point center; // 중심
public:
	Circle();//반지름 초기화
	Circle(double r);//반지름 받
	Circle(Point p, double r);//중심값
	Circle(int x, int y, double r);//중심,반지름
	~Circle();
	void print();
};

// 생성자
Circle::Circle() : radius(0.0), center(0, 0)
{
}

Circle::Circle(double r) : radius(r), center(0, 0)
{
}
Circle::Circle(Point p, double r) : radius(r), center(p)
{
}
Circle::Circle(int x, int y, double r) : radius(r), center(x, y)
{
}

Circle::~Circle(){
	cout << "소멸자 호출" << endl;
}
void Circle::print()
{
	cout << "중심 : ";
	center.print();
	cout << "반지름 : " << radius << endl;
}

int main()
{
	Point p(3, 7);

	Circle c1;
	Circle c2(5.0);
	Circle c3(c1);
	Circle c4 = Circle(5.0);
	Circle c5(p, 5.0);
	Circle c6(7, 3, 5.0);

	c1.print();
	c2.print();
	c3.print();
	c4.print();
	c5.print();
	c6.print();
	return 0;
}
