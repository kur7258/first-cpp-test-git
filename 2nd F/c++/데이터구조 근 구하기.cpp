#include<iostream>
#include<math.h>
using namespace std;
double z();

int main()
{
    double a = 0.0, b = 0.0, c = 0.0, d = 0.0, x1 = 0.0, x2 = 0.0;

    cout << "a의 값을 입력해주세요(a는 0이 아니다) = ";
    cin >> a;

    cout << "b의 값을 입력해주세요 = ";
    cin >> b;

    cout << "c의 값을 입력해주세요 = ";
    cin >> c;



    d = b * b - 4 * a * c;
    if (d < 0)
        cout << "허근" << endl;

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