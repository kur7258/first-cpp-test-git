#include<iostream>
using namespace std;
int get_largest(int array[], int n);
int main()
{
	const int NUM = 5;
	int large[NUM] = { 1,2,12,2,8 };

	get_largest(large, NUM);
	cout << "ÃÖ´ñ°ª = " << get_largest(large, NUM) << endl;
}

int get_largest(int array[], int n)
{
	int i,result = 0;
	for (i = 0; i < 5; i++)
	{
		if (result <= array[i])
		{
			result = array[i];
			i++;
		}
	}
	return result;
}
