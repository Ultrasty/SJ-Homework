/* 1851521 �� ������ */
#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>

int main()
{
	printf("������[0-100��)֮�������:\n");
	double n;
	scanf("%lf", &n);
	int a, b, c, d, e, f, g, h, i, j, k, l;
	a = (int)(n / 1000000000) % 10;
	b = (int)(n / 100000000) % 10;
	c = (int)(n / 10000000) % 10;
	d = (int)(n / 1000000) % 10;
	e = (int)(n / 100000) % 10;
	f = (int)(n / 10000) % 10;
	g = (int)(n / 1000) % 10;
	h = (int)(n / 100) % 10;
	i = (int)(n / 10) % 10;
	j = (int)(fmod(n+0.001, 10));
	k = (int)(fmod(n+0.001, 1)*10);
	l = (int)(fmod(n+0.001, 0.1)*100);
	printf("ʮ��λ : %d\n", a);
	printf("��λ   : %d\n", b);
	printf("ǧ��λ : %d\n", c);
	printf("����λ : %d\n", d);
	printf("ʮ��λ : %d\n", e);
	printf("��λ   : %d\n", f);
	printf("ǧλ   : %d\n", g);
	printf("��λ   : %d\n", h);
	printf("ʮλ   : %d\n", i);
	printf("Բ     : %d\n", j);
	printf("��     : %d\n", k);
	printf("��     : %d\n", l);
	return 0;
}