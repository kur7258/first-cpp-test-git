#include<iostream>
using namespace std;

class Time {
	friend ostream& operator <<(ostream& os, Time& t);
	friend istream& operator >>(istream& is, Time& t);
	friend bool operator<(const Time& t1,const Time& t2);
	friend bool operator>(const Time& t1,const  Time& t2);
	friend bool operator==(const Time& t1, const Time& t2);
	friend bool operator!=(const Time& t1, const Time& t2);

private:
	int hour, minute, second;
public:
	Time(int hour = 0, int minute = 0, int second = 0) {
		this->hour = hour;
		this->minute = minute;
		this->second=second;
	}
	Time operator+(int sec); //������ �ð� ���� +
	Time operator+(Time& plusT); // t1 + t2 ���� +
	Time operator-(Time& minusT);
};

istream& operator >>(istream& is, Time& t){
	cout << "�� �� �� �Է� : " << endl;
	is >> t.hour >> t.minute >> t.second;
	return is;
}
ostream& operator <<(ostream& os, Time& t) {
	os << t.hour << "�� " << t.minute << "�� " << t.second << "��" << endl;
	return os;
}
Time Time::operator+(int sec) {  //������ �ð� ���� +
	Time end(0, 0, 0);
	end.hour = this->hour;
	end.minute = this->minute;
	end.second = this->second + sec;
	while (end.second > 60) {
		end.second -= 60;
		end.minute++;
	}
	while (end.minute > 60) {
		end.minute -= 60;
		end.hour++;
	}
	return end;
}

Time Time::operator+(Time& plusT) // t1 + t2 ���� +
{
	Time t(0, 0, 0);
	t.hour = this->hour + plusT.hour;
	t.minute = this->minute + plusT.minute;
	t.second = this->second + plusT.second;
	return t;
}
Time Time::operator-(Time& minusT)
{
	Time t(0, 0, 0);
	t.hour = this->hour - minusT.hour;
	t.minute = this->minute - minusT.minute;
	t.second = this->second - minusT.second;
	return t;
}

bool operator<(const Time& t1,const Time& t2) {
	if (t1.hour < t2.hour) {
		return true;
	}
	else if (t1.hour == t2.hour) {
		if (t1.minute < t2.minute) {
			return true;
		}
		else if (t1.minute == t2.minute) {
			if (t1.second < t2.second) {
				return true;
			}
			else if (t1.second == t2.second) {
				return false;
			}
			else return false;
		}
		else return false;
	}
	else return false;
}
bool operator>(const Time& t1,const Time& t2) {
	if (t1.hour > t2.hour) {
		return true;
	}
	else if (t1.hour == t2.hour) {
		if (t1.minute > t2.minute) {
			return true;
		}
		else if (t1.minute == t2.minute) {
			if (t1.second > t2.second) {
				return true;
			}
			else if (t1.second == t2.second) {
				return false;
			}
			else return false;
		}
		else return false;
	}
	else return false;
}

bool operator==(const Time& t1, const Time& t2) {
	return t1.hour == t2.hour && t1.minute == t2.minute && t1.second == t2.second;
}
bool operator!=(const Time& t1, const Time& t2) {
	return !(t1.hour == t2.hour && t1.minute == t2.minute && t1.second == t2.second);
}


int main() {
	//start end �� (4) << >> ������
	Time start;
	cin >> start;
	cout << "���� �ð� : " << start;
	Time end = start + 1000; //1000�� ��
	cout << "������ �ð� : " << end;

	//(1) + - ������
	Time t1(10,11,12);
	Time t2(5,6,7);
	cout << endl << "�ð� 1 : " << t1;
	cout << "�ð� 2 : " << t2 << endl;

	Time t3 = t1 + t2;
	cout << "�� �ð��� �� : " << t3 << endl;

	Time t4 = t1 - t2;
	cout << "�� �ð��� �� : " << t4 << endl;

	//(2) < > ������
	cout.setf(cout.boolalpha);
	cout << "�ð� 1 < �ð� 2 ? "<< (t1 < t2) << endl;
	cout << "�ð� 1 > �ð� 2 ? "<< (t1 > t2) << endl;

	//(3) == != ������
	cout << endl << "�ð� 1 == �ð� 2 ? " << (t1 == t2) << endl;
	cout << "�ð� 1 != �ð� 2 ? " << (t1 != t2) << endl;

	return 0;
}