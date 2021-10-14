/* 1851521 软工 沈天宇 */
#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>

int main()
{
	printf("请输入[0-100亿)之间的数字:\n");
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
	printf("十亿位 : %d\n", a);
	printf("亿位   : %d\n", b);
	printf("千万位 : %d\n", c);
	printf("百万位 : %d\n", d);
	printf("十万位 : %d\n", e);
	printf("万位   : %d\n", f);
	printf("千位   : %d\n", g);
	printf("百位   : %d\n", h);
	printf("十位   : %d\n", i);
	printf("圆     : %d\n", j);
	printf("角     : %d\n", k);
	printf("分     : %d\n", l);
	return 0;
}