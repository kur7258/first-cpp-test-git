#include <iostream>
#include <string>
#define MAX 5

using namespace std;

class SearchArray {
public:
    SearchArray() {}
    int finds(int x) {
        cout << x << "을(를) 찾았습니다." << endl;
        return 0;
    }
};
class NotFound :public SearchArray {
public:
    int notfind() {
        cout << "not find" << endl;
        return 0;
    }
};
int main() {
    int num[MAX];
    int f;

    SearchArray t;
    NotFound tt;

    for (int i = 0; i < MAX; i++) {
        cout << "배열을 입력하시오 = ";
        cin >> num[i];
    }
    cout << endl << "배열에 저장된 값은 ..." << endl;

    for (int z = 0; z < MAX; z++) {
        cout << "{" << num[z] << "}";
    }

    cout << endl << endl << "배열에서 찾을 값을 입력하시오 = ";
    cin >> f;

    try {
        if (find(num, num + MAX, f) != num + MAX) {
            t.finds(f);
        }
        else throw num;
    }
    catch (int* e) {
        tt.notfind();
    }
    return 0;
}