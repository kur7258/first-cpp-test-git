#include <iostream> 
using namespace std;
int main(void)
{
    const int SIZE = 26;
    char* n = new char((char)0);
    int eng[SIZE] = { 0 };
    cout << "문자열을 입력하시오:";
    cin >> n;
    for (int loop = 0; n[loop] != (char)0; loop++) {
        if (n[loop] < 96 && n[loop] > 123) continue;
        eng[(int)n[loop] - 97]++;
    }
    for (int loop = 0; loop < SIZE; loop++) {
        cout << (char)(loop + 97) << " : " << eng[loop] << endl;
    }
    delete n;
    return 0;
}