#include<iostream>
using namespace std;
int years();
int main()
{
    cout << years() << "�� �ڿ� 2�谡 �ȴ�";
}

int years()
{
    int n = 0;
    int money = 10000000;
    double ratio = 0.07;
    int result = 0;

    while (money <= 20000000)
    {
        money = money + (money * ratio);
        n++;
        cout << money << endl;
    }
    return n;
}