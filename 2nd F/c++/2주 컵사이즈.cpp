#include<iostream>
using namespace std;
int main()
{
	int size;
	cout << "�� ������ �Է�(ml) = ";
	cin >> size;
	if (size < 100)
	{
		cout << "small";
	}
	else if (100 <= size < 200) cout << "medium";
	else cout << "large";
}