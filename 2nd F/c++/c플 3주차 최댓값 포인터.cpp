#include<iostream>
using namespace std;
int get_largest(int* parray, int n);
int main()
{
    const int NUM = 5;
    int large[NUM] = { 1,2,5,8,3 };
    int* parray = large;

    get_largest(large, NUM);
    cout << "ÃÖ´ñ°ª = " << get_largest(large, NUM) << endl;
}

int get_largest(int* parray, int n)
{
    int i;
    for (i = 0; i < 5; i++)
        if (*parray < *(parray + i)) {
            *parray = *(parray + i);
        }
    return *parray;
}