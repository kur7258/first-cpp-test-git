#include<iostream>
#include "Box.h"
using namespace std;
//���̵� ���ϴ� �Լ�
int get_input1(int w)
{
	cout << "���� ���� �Է� : ";
	cin >> w;

	return w;
}

int get_input2(int l)
{
	cout << "���� ���� �Է� : ";
	cin >> l;

	return l;
}

int get_input3(int h)
{
	cout << "���� �Է� : ";
	cin >> h;

	return h;
}

//����, ����, ����
int Box::getThree()
{
	return width, length, height;
}
void Box::setThree(int w, int l, int h)
{
	width = get_input1(w);
	length = get_input2(l);
	height = get_input3(h);
	cout << width << length << height;
}
//����
int Box::getVolume()
{
	return volume;
}
void Box::setVolume(int v)
{
	v = width * length * height;
	volume = v;
}
//���
void Box::Print()
{
	cout << endl << "�ڽ��� ���� ���� : " << width << endl;
	cout << "�ڽ��� ���� ���� : " << length << endl;
	cout << "�ڽ��� ���� : " << height << endl;
	cout << "�ڽ��� ���� : " << volume << endl;
}