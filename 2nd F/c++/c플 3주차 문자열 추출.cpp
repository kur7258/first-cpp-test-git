#include<iostream>
using namespace std;
const int NUMBER = 100; //�迭
char word[NUMBER];
void sub_string(char* s, int start, int n, char* result);
int main()
{
	int start;
	int n;
	char result[NUMBER] = { 0 };
	cout << "���ڿ��� �Է��Ͻÿ�: ";
	cin >> word;
	cout << "������ġ : ";
	cin >> start;
	cout << "���� : ";
	cin >> n;
	sub_string(word, start - 1, n, result);
	cout << "��� : " << result;
}
void sub_string(char* s, int start, int n, char* result)
{
	for (int i = start, p = 0; i < start + n; i++, p++)
	{
		result[p] = s[i];
	}
}