#include<iostream>
using namespace std;

int main()
{
	int size;
	cout << "�� ������(����mL) : ";
	cin >> size;

	if (size < 100)
	{
		cout << "small";
	}
	else if (100 <= size && size < 200)
		cout << "midium";

	else
		cout << "large";
	return 0;
}