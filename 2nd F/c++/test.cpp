#include <iostream>
#include <string>
#define MAX 5

using namespace std;

class SearchArray {
public:
    SearchArray() {}
    int finds(int x) {
        cout << x << "��(��) ã�ҽ��ϴ�." << endl;
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
        cout << "�迭�� �Է��Ͻÿ� = ";
        cin >> num[i];
    }
    cout << endl << "�迭�� ����� ���� ..." << endl;

    for (int z = 0; z < MAX; z++) {
        cout << "{" << num[z] << "}";
    }

    cout << endl << endl << "�迭���� ã�� ���� �Է��Ͻÿ� = ";
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