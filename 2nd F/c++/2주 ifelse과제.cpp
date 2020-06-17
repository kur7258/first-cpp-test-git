#include<iostream>
using namespace std;

int main()
{
	int n;
	cout << "변수n 입력 : ";
	cin >> n;
	if (n >= 100)
	{
		cout << "large" << endl;
	}
	else cout << "small" << endl;
	return 0;
}