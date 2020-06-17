#include<iostream>
#include<string>
using namespace std;

class Converter {  //추상
protected:
	double ratio;
	virtual double convert(double src) = 0;
	virtual string getSourceString() = 0;
	virtual string getDestString() = 0;
public:
	Converter(double ratio) { this->ratio = ratio; }
	void run() {
		double src;
		cout << getSourceString() << "을" << getDestString() << "로 바꿉니다.";
		cout <<getSourceString() << "을 입력하세요.";
		cin >> src;
		cout << "변환결과 : " << convert(src) << getDestString() << endl;
	}
};

class WonToDollar :public Converter { //상속
private:
	int won;
public:
	WonToDollar(int won) :Converter(ratio) { this->won = won; }
	double convert(double src) { return src / won; }
	string getSourceString() { return "원"; }
	string getDestString() { return "달러"; }
};

int main() {
	WonToDollar wd(1010); //1달러에 1010원
	wd.run();
	return 0;
}