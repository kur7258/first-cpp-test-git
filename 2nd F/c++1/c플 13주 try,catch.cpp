#include<iostream>
#define MAX 5
using namespace std;

class SearchArray {
private:
	int num;
public:
	SearchArray() { num = 1; }
	bool Search(int n, int *array);
};

bool SearchArray::Search(int n, int *array) {
	if (find(array, array + MAX, n) != array + MAX) {
		return true;
	}
}

class NotFound {
public:
	NotFound() {}
	void notfound() {cout << "Not Found"; }
};

int main() {
	int n;
	int array[MAX] = { 11,22,33,44,55 };
	SearchArray sa;
	NotFound nf;

	cout << "배열에 저장된 값은..." << endl;
	for (int i = 0; i < MAX; i++){
		cout << "[" << array[i] << "] ";
	}
	cout <<endl<< "찾을 값을 입력하세요 : ";
	cin >> n;
	try {
		if (sa.Search(n, array) == true) { cout << "Found"; }
		else throw 1;
	}
	catch (int expn) {
		nf.notfound();
	}

	return 0;
}