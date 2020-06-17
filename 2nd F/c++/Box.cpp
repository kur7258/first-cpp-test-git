#include<iostream>
#include "Box.h"
using namespace std;
//길이들 구하는 함수
int get_input1(int w)
{
	cout << "가로 길이 입력 : ";
	cin >> w;

	return w;
}

int get_input2(int l)
{
	cout << "세로 길이 입력 : ";
	cin >> l;

	return l;
}

int get_input3(int h)
{
	cout << "높이 입력 : ";
	cin >> h;

	return h;
}

//가로, 세로, 높이
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
//부피
int Box::getVolume()
{
	return volume;
}
void Box::setVolume(int v)
{
	v = width * length * height;
	volume = v;
}
//출력
void Box::Print()
{
	cout << endl << "박스의 가로 길이 : " << width << endl;
	cout << "박스의 세로 길이 : " << length << endl;
	cout << "박스의 높이 : " << height << endl;
	cout << "박스의 부피 : " << volume << endl;
}