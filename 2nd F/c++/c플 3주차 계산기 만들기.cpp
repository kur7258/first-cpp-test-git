#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    int i, k;
    char c[100];
    int n1, n2;
    double result = 0;
    cout << "add minus multiply divide power계산식 입력 = ";
    cin >> n1 >> c >> n2;
    if ((int)strcmp(c, "add") == 0) { result = n1 + n2; }
    else if ((int)strcmp(c, "minus") == 0) { result = n1 - n2; }
    else if ((int)strcmp(c, "multiply") == 0) { result = n1 * n2; }
    else if ((int)strcmp(c, "divide") == 0) { result = n1 / n2; }
    else if ((int)strcmp(c, "power") == 0) {
        k = n1;
        for (i = 0; i < n2 - 1; i++) {
            k = k * n1;
        }
        result = k;
    }
    else cout << "잘못된 입력" << endl;
    cout << "답 = " << result;
}