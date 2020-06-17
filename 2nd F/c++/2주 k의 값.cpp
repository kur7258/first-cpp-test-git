#include<iostream>
using namespace std;
int main()
{
	int k,i;
	for (i = 0; i < 3; i++)
	{
		cout << "k°ª ÀÔ·Â = ";
		cin >> k;
		if (k != 0)
		{
			cout << "A" << endl;
		}
		else if (k > 3) cout << "B" << endl;
		else cout << "C" << endl;
	}
	
}