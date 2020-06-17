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
	Time operator+(int sec); //끝나는 시간 계산용 +
	Time operator+(Time& plusT); // t1 + t2 계산용 +
	Time operator-(Time& minusT);
};

istream& operator >>(istream& is, Time& t){
	cout << "시 분 초 입력 : " << endl;
	is >> t.hour >> t.minute >> t.second;
	return is;
}
ostream& operator <<(ostream& os, Time& t) {
	os << t.hour << "시 " << t.minute << "분 " << t.second << "초" << endl;
	return os;
}
Time Time::operator+(int sec) {  //끝나는 시간 계산용 +
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

Time Time::operator+(Time& plusT) // t1 + t2 계산용 +
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
	//start end 와 (4) << >> 연산자
	Time start;
	cin >> start;
	cout << "시작 시간 : " << start;
	Time end = start + 1000; //1000초 후
	cout << "끝나는 시간 : " << end;

	//(1) + - 연산자
	Time t1(10,11,12);
	Time t2(5,6,7);
	cout << endl << "시간 1 : " << t1;
	cout << "시간 2 : " << t2 << endl;

	Time t3 = t1 + t2;
	cout << "두 시간의 합 : " << t3 << endl;

	Time t4 = t1 - t2;
	cout << "두 시간의 차 : " << t4 << endl;

	//(2) < > 연산자
	cout.setf(cout.boolalpha);
	cout << "시간 1 < 시간 2 ? "<< (t1 < t2) << endl;
	cout << "시간 1 > 시간 2 ? "<< (t1 > t2) << endl;

	//(3) == != 연산자
	cout << endl << "시간 1 == 시간 2 ? " << (t1 == t2) << endl;
	cout << "시간 1 != 시간 2 ? " << (t1 != t2) << endl;

	return 0;
}