#include <iostream>
using namespace std;

int main() {
    int player, start, i;

    cout << "�� ���� ���� = ";
    cin >> start;

    for (; start > 0; start) {
        cout << "������ ���� ���Ͻÿ� (1~3��) = ";
        cin >> player;
        if (player > 0) {
            if (player < 4) {
                start = start - player;
                if (start <= 0) {
                    cout << "You lose!!";
                }
            }
        }
    }

    return 0;
}