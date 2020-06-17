#include<iostream>
#include<string>
using namespace std;

class Human {
protected:
	string name;
	int age;
public:
	Human() { cout << endl << "Human 호출" << endl; }; //매개변수 없는 생성자
	Human(string name, int age);

	string getName();
	void setName(string name);
	int getAge();
	void setAge(int age);
	void print();
	~Human() { cout << "Human 소멸자 호출" << endl; };
};

Human::Human(string name, int age):name(""),age(0){ // 초기화 생성자
}

string Human:: getName() { //name 접근자
	return name;
}
void Human::setName(string name) { //name 생성자
	this->name = name;
}

int Human::getAge() { //age 접근자
	return age;
}
void Human::setAge(int age) { //age 생성자
	this->age = age;
}

void Human::print() { //출력
	cout << "이름 : " << this->name << endl << "나이 : " << this->age << "세" << endl << endl;
}

class Student :public Human {
protected:
	string major;
public:
	Student() { cout << endl << "Student 호출" << endl; }; //매개변수 없는 생성자
	Student(string name, int age, string major);

	string getName();
	void setName(string name);
	int getAge();
	void setAge(int age);
	string getMajor();
	void setMajor(string major);
	void print();
	~Student() { cout << "Student 소멸자 호출" << endl; };
};

Student::Student(string name, int age, string major):Human(name,age), major(""){ //초기화 생성자
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

void Student::print() { //출력
	cout << "이름 : " << this->name << endl << "나이 : " << this->age << "세 " << endl << "전공 : " << this->major << endl << endl;
}

int main() {
	Human human;
	human.setName("춘향");
	human.setAge(18);
	human.print();

	human.setName("몽룡");
	human.setAge(21);
	human.print();

	human.setName("사또");
	human.setAge(50);
	human.print();

	Student student;
	student.setName("명진");
	student.setAge(21);
	student.setMajor("컴퓨터");
	student.print();

	student.setName("미현");
	student.setAge(22);
	student.setMajor("경영");
	student.print();

	student.setName("용준");
	student.setAge(24);
	student.setMajor("전자");
	student.print();
	return 0;
}