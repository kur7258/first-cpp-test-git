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
        cout << "�����͸� �Է��Ͻÿ� : (������ ����)";
        cin >> num;
        if (num >= 0)
        {
            n[k] = num;
            k++;
        }
    }
    cout << "����� ��� : ";
    for (i = 0; i < k; i++)
    {
        cout << n[i] << " ";
    }
    cout << "������ �ִ밪 = " << max(n, numbers) << endl;
    cout << "������ �ּڰ� = " << min(n, numbers) << endl;
    cout << "������ ��� = " << avg(n, numbers) << endl;

}