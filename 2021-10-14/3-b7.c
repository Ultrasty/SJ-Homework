/* 1851521 �� ������ */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

int main() {
	printf("����������ֵ��\n");
	double money;
	int m;
	scanf("%lf",&money);
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

	printf("��%d�����㣬�������£�\n" , m50 + m20 + m10 + m5 + m1 + m0_5 + m0_1 + m0_05 + m0_02 + m0_01);
	if (m50 != 0) {
		printf("50Ԫ : %d��\n" ,m50 );
	}
	if (m20 != 0) {
		printf("20Ԫ : %d��\n" ,m20 );
	}
	if (m10 != 0) {
		printf("10Ԫ : %d��\n" ,m10 );
	}
	if (m5 != 0) {
		printf("5Ԫ  : %d��\n" ,m5 );
	}
	if (m1 != 0) {
		printf("1Ԫ  : %d��\n" ,m1 );
	}
	if (m0_5 != 0) {
		printf("5��  : %d��\n" ,m0_5 );
	}
	if (m0_1 != 0) {
		printf("1��  : %d��\n" ,m0_1 );
	}
	if (m0_05 != 0) {
		printf("5��  : %d��\n" ,m0_05 );
	}
	if (m0_02 != 0) {
		printf("2��  : %d��\n" ,m0_02 );
	}
	if (m0_01 != 0) {
		printf("1��  : %d��\n" ,m0_01 );
	}


	return 0;
}