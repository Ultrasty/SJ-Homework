/* 1851521 �� ������ */
#include<iostream>
#include<cmath>
using namespace std;

int main() {
	cout << "����������ֵ��\n";
	double money;
	int m;
	cin >> money;
	int m50, m20, m10, m5, m1, m0_5, m0_1, m0_05, m0_02, m0_01;
	int i, j, k, l;

	i = (int)(money / 10) % 10;
	j = (int)(fmod(money + 0.001, 10));
	k = (int)(fmod(money + 0.001, 1) * 10);
	l = (int)(fmod(money + 0.001, 0.1) * 100);

	m = i * 1000 + j * 100 + k * 10 + l;

	m50 = m / 5000;
	m = m % 5000;

	m20 = m / 2000;
	m = m % 2000;

	m10 = m / 1000;
	m = m % 1000;

	m5 = m / 500;
	m = m % 500;

	m1 = m / 100;
	m = m % 100;

	m0_5 = m / 50;
	m = m % 50;

	m0_1 = m / 10;
	m = m % 10;

	m0_05 = m / 5;
	m = m % 5;

	m0_02 = m / 2;
	m = m % 2;

	m0_01 = m / 1;
	m = m % 1;

	cout << "��" << m50 + m20 + m10 + m5 + m1 + m0_5 + m0_1 + m0_05 + m0_02 + m0_01 << "�����㣬�������£�\n";
	if (m50 != 0) {
		cout << "50Ԫ : " << m50 << "��\n";
	}
	if (m20 != 0) {
		cout << "20Ԫ : " << m20 << "��\n";
	}
	if (m10 != 0) {
		cout << "10Ԫ : " << m10 << "��\n";
	}
	if (m5 != 0) {
		cout << "5Ԫ  : " << m5 << "��\n";
	}
	if (m1 != 0) {
		cout << "1Ԫ  : " << m1 << "��\n";
	}
	if (m0_5 != 0) {
		cout << "5��  : " << m0_5 << "��\n";
	}
	if (m0_1 != 0) {
		cout << "1��  : " << m0_1 << "��\n";
	}
	if (m0_05 != 0) {
		cout << "5��  : " << m0_05 << "��\n";
	}
	if (m0_02 != 0) {
		cout << "2��  : " << m0_02 << "��\n";
	}
	if (m0_01 != 0) {
		cout << "1��  : " << m0_01 << "��\n";
	}


	return 0;
}