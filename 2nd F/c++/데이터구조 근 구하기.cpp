#include<iostream>
#include<math.h>
using namespace std;
double z();

int main()
{
    double a = 0.0, b = 0.0, c = 0.0, d = 0.0, x1 = 0.0, x2 = 0.0;

    cout << "a�� ���� �Է����ּ���(a�� 0�� �ƴϴ�) = ";
    cin >> a;

    cout << "b�� ���� �Է����ּ��� = ";
    cin >> b;

    cout << "c�� ���� �Է����ּ��� = ";
    cin >> c;



    d = b * b - 4 * a * c;
    if (d < 0)
        cout << "���" << endl;

    else if (d == 0) {
        x1 = -b / (2 * a);
        cout << x1 << endl;
    }
    else {
        x1 = (-b + z()) / (2 * a);
        cout << x1 << endl;
        x2 = (-b - z()) / (2 * a);
        cout << x2 << endl;
    }
    return 0;
}
double z() {
    double a = 0.0, b = 0.0, c = 0.0;
    double root = sqrt((b * b) - (4 * a * c));

    return root;
}