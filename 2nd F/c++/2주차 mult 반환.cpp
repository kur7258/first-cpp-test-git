#include<iostream>
using namespace std;
int mult(int x, int y)
{
	int result;
	result = x * y;
	return result;
}
int main()
{
	int x, y;
	cout << "x입력 = ";
	cin >> x;
	cout << "y입력 = ";
	cin >> y;
	cout << "두 정수의 곱 = " << mult(x, y);
	return 0;
}