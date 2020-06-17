#include<iostream>
using namespace std;

int main()
{
	int k;
	cout << "3,0,-1중 하나 입력 : ";
	cin >> k;
	if (k != 0)
	{
		cout << "A";
	}
	else if (k > 3)
		cout << "B";
	else cout << "C";

	return 0;
}