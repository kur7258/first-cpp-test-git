#include<iostream>
using namespace std;
class Box
{
	int width;
	int length;
	int height;
	int volume;

public:

	int getThree();
	void setThree(int w, int l, int h);
	int getVolume();
	void setVolume(int v);
	void Print();
};

8번 // 초기화 리스트로는 const의 영향을 받지 않고 초기화 가능

