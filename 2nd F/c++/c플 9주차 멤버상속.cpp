#include<iostream>
#include<string>
using namespace std;


class Printer {
protected:
	string md; //모델명
	string mf; //제조사
	int pc; //인쇄매수
	int ac; //인쇄종이 잔량
public:
	Printer(string model, string manufacturer, int availableCount):md(model),mf(manufacturer),ac(availableCount) {};
	void print(int pages);
	void inform(); //프린트 정보
	int getAvailableCount() { return ac; }
};

void Printer::print(int pages) {
	pc += pages;
	ac -= pages;
	cout << "프린트하였습니다." << endl;
}
void Printer::inform() {
	cout << md << "," << mf << "," << " 남은 종이 " << ac << "장, ";
}


class InkJet :public Printer { //잉크젯 프린터
private:
	int availableInk;  //잉크 잔량
public:
	InkJet(string md, string mf, int ac, int ai) :Printer(md, mf, ac) {
		this->availableInk = ai;
	}
	void printInkJet(int pages); //+남은 장
	void inform(); //+남은 잉크
	int getAvailableInk() { return availableInk; }
};

void InkJet::printInkJet(int pages) {
	print(pages);
	this->availableInk -= pages;
}
void InkJet::inform() {
	cout << "잉크젯 : ";
	Printer::inform();
	cout << "남은 잉크 " << availableInk << endl;
}

class Laser :public Printer { //레이저 프린터
private:
	int availableToner;  //토너 잔량
public:
	Laser(string md, string mf, int ac, int at) :Printer(md, mf, ac) {
		this->availableToner = at;
	}
	void printLaser(int pages);
	void inform();
	int getAvailableToner() { return availableToner; }
	
};

void Laser::printLaser(int pages) {
	print(pages);
	this->availableToner -= pages;
}
void Laser::inform() {
	cout << "레이저 : ";
	Printer::inform();
	cout << "남은 토너 " << availableToner << endl;
}



int main() {
	cout << "현재 작동중인 2대의 프린터는 아래와 같다." << endl;
	InkJet InkJet("Officejet V40 ", "Hp", 5, 10);//잉크 정보
	Laser Laser("SCX-6x45 ", "삼성전자", 3, 20);//레이저 정보
	InkJet.inform(); //갱신정보
	Laser.inform(); //갱신정보

	char choise = 'y'; //  y/n
	int choiseType = 0; // 1 or 2
	int pages = 0;  // 매수 입력
	while (choise != 'n') {
		cout << endl << "프린터(1:잉크젯, 2:레이저)와 매수 입력>>";
		cin >> choiseType;
		cin >> pages;
		switch (choiseType) {
		case 1:
			if (InkJet.getAvailableCount() - pages < 0) {
				cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
			}
			else if (InkJet.getAvailableInk() - pages < 0) {
				cout << "잉크가 부족하여 프린트할 수 없습니다." << endl;
			}
			else { InkJet.printInkJet(pages); }
			break;
		case 2:
			if (Laser.getAvailableCount() - pages < 0) {
				cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
			}
			else if (Laser.getAvailableToner() - pages < 0) {
				cout << "토너가 부족하여 프린트할 수 없습니다." << endl;
			}
			else { Laser.printLaser(pages); }
			break;
		}
		InkJet.inform();//수정 정보
		Laser.inform();//수정 정보
		cout << "계속 프린트하시겠습니까(y/n)>>";
		cin >> choise;
	}
	return 0;
}