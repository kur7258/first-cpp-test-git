#include <iostream>
using namespace std;

int main() {
    int player, start, i;

    cout << "돌 시작 갯수 = ";
    cin >> start;

    for (; start > 0; start) {
        cout << "가져갈 수를 정하시오 (1~3개) = ";
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