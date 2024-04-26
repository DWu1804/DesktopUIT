#include<iostream>
#include <cmath>
using namespace std;
class MyTime {
private:
	int hh, mm, ss;
public:
	MyTime(int hh = 0, int mm = 0, int ss = 0) {};
	~MyTime();
	friend istream& operator>>(istream& in, MyTime& mt) {
		in >> mt.hh >> mt.mm >> mt.ss;
		return in;
	}
	MyTime operator + (const MyTime& b, int addsec) {
		MyTime a;
		a.hh = hh + b.hh;
		a.mm = mm + b.mm;
		a.ss = ss + b.ss + addsec;
		return a;
	}
	MyTime operator ++() {
		ss++;
		return *this;
	}
	MyTime operator --() {
		ss--;
		return *this;
	}
	void test() {
		if (ss >= 60) {
			mm += ss / 60; ss %= 60;
		}
		if (mm >= 60) {
			hh += mm / 60; mm %= 60;
		}
		if (hh >= 24) hh %= 24;
		if (ss < 0) {
			mm -= abs(ss) / 60; ss = abs(ss) % 60;
		}
		if (mm < 0) {
			hh -= abs(mm) / 24; mm = abs(mm) % 60;
		}
		if (hh < 0) hh = abs(hh) % 24;
	}
	friend ostream& operator <<(ostream& out, MyTime& b) {
		b.test();
		out << b.hh << ":" << b.mm << ":" << b.ss << "\n";
		return out;
	}
};
int main() {
	MyTime mt;
	cout << mt << "\n";
	cout << "nhap gio:\n";
	cin >> mt;
	int addsec;
	cout << "addsec: \n";
	cin >> addsec;
	cout << "Cong them giay: \n" << mt + addsec;
	MyTime A = addsec + ++mt + mt--;
	cout << "Gia tri cuoi la :" << A;
	return 0;
}