/* 1851521 ������ �� */
#include<iostream>
#include<cmath> 
using namespace std;

extern double a, b, c, delta;

void s1()
{
	cout << "����һԪ���η���" << endl;
}

void s2()
{
	cout << "���������ʵ����" << endl;
	cout << "x1=x2=" << -b / (2 * a) << endl;
}

void s3()
{
	cout << "����������ʵ����" << endl;
	if (a > 0) {
		cout << "x1=" << (-b + sqrt(delta)) / (2 * a) << endl;
		cout << "x2=" << (-b - sqrt(delta)) / (2 * a) << endl;
	}
	else {
		cout << "x1=" << (-b - sqrt(delta)) / (2 * a) << endl;
		cout << "x2=" << (-b + sqrt(delta)) / (2 * a) << endl;
	}
}

void s4()
{
	cout << "�����������" << endl;
	if (abs(abs(sqrt(-delta) / (2 * a)) - 1) < 1e-6) {
		if (abs(b) < 1e-6) {
			cout << "x1=" << "i" << endl;
			cout << "x2=" << "-i" << endl;
		}
		else {
			cout << "x1=" << -b / (2 * a) << "+i" << endl;
			cout << "x2=" << -b / (2 * a) << "-i" << endl;
		}
	}
	else {
		if (abs(b) < 1e-6) {
			cout << "x1=" << sqrt(-delta) / (2 * a) << "i" << endl;
			cout << "x2=" << -sqrt(-delta) / (2 * a) << "i" << endl;
		}
		else {
			cout << "x1=" << -b / (2 * a) << "+" << sqrt(-delta) / (2 * a) << "i" << endl;
			cout << "x2=" << -b / (2 * a) << "-" << sqrt(-delta) / (2 * a) << "i" << endl;
		}
	}
}
