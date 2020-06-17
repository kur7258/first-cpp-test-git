#include<iostream>
using namespace std;
int main()
{
	int size;
	cout << "컵 사이즈 입력(ml) = ";
	cin >> size;
	if (size < 100)
	{
		cout << "small";
	}
	else if (100 <= size < 200) cout << "medium";
	else cout << "large";
}