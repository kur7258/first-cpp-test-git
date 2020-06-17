#include<iostream>
#define MAX 5
using namespace std;

class SearchArray {
private:
	int num;
public:
	SearchArray() { num = 1; }
	int Search(int n, int *array);
};

int SearchArray::Search(int n, int *array) {
	if (find(array, array + MAX, n) != array + MAX) {
		return 1;
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
		if (sa.Search(n, array) == 1) { cout << "Found"; }
		else throw 1;
	}
	catch (...) {
		nf.notfound();
	}

	return 0;
}