#include<iostream>
#include<string>
using namespace std;

class Human {
protected:
	string name;
	int age;
public:
	Human() { cout << endl << "Human ȣ��" << endl; }; //�Ű����� ���� ������
	Human(string name, int age);

	string getName();
	void setName(string name);
	int getAge();
	void setAge(int age);
	void print();
	~Human() { cout << "Human �Ҹ��� ȣ��" << endl; };
};

Human::Human(string name, int age):name(""),age(0){ // �ʱ�ȭ ������
}

string Human:: getName() { //name ������
	return name;
}
void Human::setName(string name) { //name ������
	this->name = name;
}

int Human::getAge() { //age ������
	return age;
}
void Human::setAge(int age) { //age ������
	this->age = age;
}

void Human::print() { //���
	cout << "�̸� : " << this->name << endl << "���� : " << this->age << "��" << endl << endl;
}

class Student :public Human {
protected:
	string major;
public:
	Student() { cout << endl << "Student ȣ��" << endl; }; //�Ű����� ���� ������
	Student(string name, int age, string major);

	string getName();
	void setName(string name);
	int getAge();
	void setAge(int age);
	string getMajor();
	void setMajor(string major);
	void print();
	~Student() { cout << "Student �Ҹ��� ȣ��" << endl; };
};

Student::Student(string name, int age, string major):Human(name,age), major(""){ //�ʱ�ȭ ������
}

string Student::getName() { //name
	return name;
}
void Student::setName(string name) {
	this->name = name;
}

int Student::getAge() { //age 
	return age;
}
void Student::setAge(int age) {
	this->age = age;
}

string Student::getMajor() { //major
	return major;
}
void Student::setMajor(string major) {
	this->major = major;
}

void Student::print() { //���
	cout << "�̸� : " << this->name << endl << "���� : " << this->age << "�� " << endl << "���� : " << this->major << endl << endl;
}

int main() {
	Human human;
	human.setName("����");
	human.setAge(18);
	human.print();

	human.setName("����");
	human.setAge(21);
	human.print();

	human.setName("���");
	human.setAge(50);
	human.print();

	Student student;
	student.setName("����");
	student.setAge(21);
	student.setMajor("��ǻ��");
	student.print();

	student.setName("����");
	student.setAge(22);
	student.setMajor("�濵");
	student.print();

	student.setName("����");
	student.setAge(24);
	student.setMajor("����");
	student.print();
	return 0;
}