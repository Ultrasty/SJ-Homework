/* 1851521 �� ������ */
#define _CRT_SECURE_NO_WARNINGS
#define pi 3.14159
#include <stdio.h>

int main()
{
	int n, a, b, c, d, e;
	printf("������һ��[1..30000]�������\n");
	scanf("%d", &n);
	a = n % 10;
	b = n / 10 % 10;
	c = n / 100 % 10;
	d = n / 1000 % 10;
	e = n / 10000 % 10;
	printf("��λ : %d\n", e);
	printf("ǧλ : %d\n", d);
	printf("��λ : %d\n", c);
	printf("ʮλ : %d\n", b);
	printf("��λ : %d\n", a);
	return 0;
}