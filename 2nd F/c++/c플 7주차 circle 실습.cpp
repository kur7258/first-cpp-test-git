#include <iostream>
#include <string>
using namespace std;

class Circle {
private:
	const double PI;//����
public:
	double radius;//������
	Circle();
	Circle(double radius);
	Circle(Circle& c);
	double getArea()const;
	double getPerimeter()const;
	void print();
};


Circle::Circle() :PI(3.14),radius(0) { //�ʱ�ȭ, ���ʻ�����
	
}
Circle::Circle(double radius):PI(3.14) {//������ ��
	this->radius = radius;
}

Circle::Circle(Circle& copy) :PI(copy.PI) {//���� ������
	radius = copy.radius;
}
double Circle::getArea()const { //����
	return radius * radius * PI;
}


double Circle::getPerimeter()const { //����
	return radius * 2 * PI;
}


void Circle::print() {		//���
	cout << "������ : " << radius << endl;
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
	cout << "�� ���� : " << p->getArea() << endl;
	cout << "���� : " <<  p->getPerimeter() << endl;
	c1.print();
	c2.print();
	result = is_equal(c1, c2);
	if ( result == 1)
	{
		cout << "�����ϴ�." << endl;
	}
	else cout << "�ٸ��ϴ�." << endl;
	
	return 0;
}