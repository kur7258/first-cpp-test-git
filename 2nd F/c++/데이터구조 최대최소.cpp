#include<iostream>
using namespace std;
int max(int n[], int x)
{
	int i;
	int max = n[0];
	for (i = 0; i < 10; i++)
	{
		if (n[i]>max)
		{
			max = n[i];
		}
	}
	return max;
}

int min(int n[], int x)
{
	int i;
	int min = n[0];
	for (i = 0; i < 10; i++)
	{
		if (n[i] < min)
		{
			min = n[i];
		}
	}
	return min;
}

int main()
{
	int num;
	const int numbers = 10;
	int n[numbers];
	int i;
	for (i = 0; i <10; i++)
	{
		cout << "���� �Է� = ";
		cin >> num;
		n[i] = num;
	}
	cout << "������ ���� = ";
	for (i = 0; i <10; i++)
	{
		cout << n[i] << " ";
	}
	cout << "������ �ִ� = " << max(n, numbers) << endl;
	cout << "������ �ּڰ� = " << min(n, numbers) << endl;
	return 0;
}