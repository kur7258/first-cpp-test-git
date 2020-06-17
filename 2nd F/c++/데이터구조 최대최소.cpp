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
		cout << "정수 입력 = ";
		cin >> num;
		n[i] = num;
	}
	cout << "지정된 정수 = ";
	for (i = 0; i <10; i++)
	{
		cout << n[i] << " ";
	}
	cout << "정수의 최댓값 = " << max(n, numbers) << endl;
	cout << "정수의 최솟값 = " << min(n, numbers) << endl;
	return 0;
}