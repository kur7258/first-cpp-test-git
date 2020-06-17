#include<iostream>
using namespace std;
const int NUMBER = 100; //배열
char word[NUMBER];
void sub_string(char* s, int start, int n, char* result);
int main()
{
	int start;
	int n;
	char result[NUMBER] = { 0 };
	cout << "문자열을 입력하시오: ";
	cin >> word;
	cout << "시작위치 : ";
	cin >> start;
	cout << "길이 : ";
	cin >> n;
	sub_string(word, start - 1, n, result);
	cout << "결과 : " << result;
}
void sub_string(char* s, int start, int n, char* result)
{
	for (int i = start, p = 0; i < start + n; i++, p++)
	{
		result[p] = s[i];
	}
}