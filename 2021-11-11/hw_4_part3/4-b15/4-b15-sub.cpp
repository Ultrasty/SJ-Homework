/* 1851521 ������ �� */
#include<iostream>
#include<cmath>
using namespace std;

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����������롢���õݹ麯�������
***************************************************************************/
void s1(double a, double b, double c, double delta)
{
	cout << "����һԪ���η���" << endl;
}

void s2(double a, double b, double c, double delta)
{
	cout << "���������ʵ����" << endl;
	cout << "x1=x2=" << -b / (2 * a) << endl;
}

void s3(double a, double b, double c, double delta)
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

void s4(double a, double b, double c, double delta)
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
