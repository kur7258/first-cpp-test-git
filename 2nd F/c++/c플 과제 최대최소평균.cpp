#include <iostream>
using namespace std;
int k = 0;
int max(int n[], int x)
{
    int i;
    int max = n[0];
    for (i = 0; i < k; i++)
    {
        if (n[i] > max)
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
    for (i = 0; i < k; i++)
    {
        if (n[i] < min)
        {
            min = n[i];

        }


    }
    return min;


}
int avg(int n[], int x)
{
    int i;
    int sum = 0;
    int avg = 0;
    for (i = 0; i < k; i++)
    {
        sum += n[i];
    }
    avg = sum / k;

    return avg;
}
int main()
{
    int num = 0;
    const int numbers = 1000;
    int n[numbers];
    int i;
    while (num >= 0) {
        cout << "데이터를 입력하시오 : (음수면 종료)";
        cin >> num;
        if (num >= 0)
        {
            n[k] = num;
            k++;
        }
    }
    cout << "저장된 양수 : ";
    for (i = 0; i < k; i++)
    {
        cout << n[i] << " ";
    }
    cout << "정수의 최대값 = " << max(n, numbers) << endl;
    cout << "정수의 최솟값 = " << min(n, numbers) << endl;
    cout << "정수의 평균 = " << avg(n, numbers) << endl;

}