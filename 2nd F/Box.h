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