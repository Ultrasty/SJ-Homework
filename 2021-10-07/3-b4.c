/* 1851521 �� ������ */
#define _CRT_SECURE_NO_WARNINGS
#define pi 3.14159
#include <stdio.h>
#include <math.h>
int main()
{
	int a, b, angle;
	printf("�����������ε����߼���н�(�Ƕ�)\n");
	scanf("%d%d%d", &a, &b, &angle);
	float ans = (float)(sin(pi * angle / 180) * a * b / 2);
	printf("���������Ϊ : %.3f\n", ans);
	return 0;
}