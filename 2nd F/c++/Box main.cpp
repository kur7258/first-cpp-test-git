#include<iostream>
#include "Box.h"
using namespace std;

int main()
{
	int width = 0, length = 0, height = 0;
	int volume =0;
	Box box;
	box.setThree(width, length, height);
	box.setVolume(volume);
	box.Print();
	
	return 0;
}