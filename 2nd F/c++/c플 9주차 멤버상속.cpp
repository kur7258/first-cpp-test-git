#include<iostream>
#include<string>
using namespace std;


class Printer {
protected:
	string md; //�𵨸�
	string mf; //������
	int pc; //�μ�ż�
	int ac; //�μ����� �ܷ�
public:
	Printer(string model, string manufacturer, int availableCount):md(model),mf(manufacturer),ac(availableCount) {};
	void print(int pages);
	void inform(); //����Ʈ ����
	int getAvailableCount() { return ac; }
};

void Printer::print(int pages) {
	pc += pages;
	ac -= pages;
	cout << "����Ʈ�Ͽ����ϴ�." << endl;
}
void Printer::inform() {
	cout << md << "," << mf << "," << " ���� ���� " << ac << "��, ";
}


class InkJet :public Printer { //��ũ�� ������
private:
	int availableInk;  //��ũ �ܷ�
public:
	InkJet(string md, string mf, int ac, int ai) :Printer(md, mf, ac) {
		this->availableInk = ai;
	}
	void printInkJet(int pages); //+���� ��
	void inform(); //+���� ��ũ
	int getAvailableInk() { return availableInk; }
};

void InkJet::printInkJet(int pages) {
	print(pages);
	this->availableInk -= pages;
}
void InkJet::inform() {
	cout << "��ũ�� : ";
	Printer::inform();
	cout << "���� ��ũ " << availableInk << endl;
}

class Laser :public Printer { //������ ������
private:
	int availableToner;  //��� �ܷ�
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
	cout << "������ : ";
	Printer::inform();
	cout << "���� ��� " << availableToner << endl;
}



int main() {
	cout << "���� �۵����� 2���� �����ʹ� �Ʒ��� ����." << endl;
	InkJet InkJet("Officejet V40 ", "Hp", 5, 10);//��ũ ����
	Laser Laser("SCX-6x45 ", "�Ｚ����", 3, 20);//������ ����
	InkJet.inform(); //��������
	Laser.inform(); //��������

	char choise = 'y'; //  y/n
	int choiseType = 0; // 1 or 2
	int pages = 0;  // �ż� �Է�
	while (choise != 'n') {
		cout << endl << "������(1:��ũ��, 2:������)�� �ż� �Է�>>";
		cin >> choiseType;
		cin >> pages;
		switch (choiseType) {
		case 1:
			if (InkJet.getAvailableCount() - pages < 0) {
				cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
			}
			else if (InkJet.getAvailableInk() - pages < 0) {
				cout << "��ũ�� �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
			}
			else { InkJet.printInkJet(pages); }
			break;
		case 2:
			if (Laser.getAvailableCount() - pages < 0) {
				cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
			}
			else if (Laser.getAvailableToner() - pages < 0) {
				cout << "��ʰ� �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
			}
			else { Laser.printLaser(pages); }
			break;
		}
		InkJet.inform();//���� ����
		Laser.inform();//���� ����
		cout << "��� ����Ʈ�Ͻðڽ��ϱ�(y/n)>>";
		cin >> choise;
	}
	return 0;
}