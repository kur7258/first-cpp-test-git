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
	cout << "x�Է� = ";
	cin >> x;
	cout << "y�Է� = ";
	cin >> y;
	cout << "�� ������ �� = " << mult(x, y);
	return 0;
}