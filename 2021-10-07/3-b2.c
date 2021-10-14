/* 1851521 软工 沈天宇 */
#define _CRT_SECURE_NO_WARNINGS
#define pi 3.14159
#include <stdio.h>

int main()
{
	int n, a, b, c, d, e;
	printf("请输入一个[1..30000]间的整数\n");
	scanf("%d", &n);
	a = n % 10;
	b = n / 10 % 10;
	c = n / 100 % 10;
	d = n / 1000 % 10;
	e = n / 10000 % 10;
	printf("万位 : %d\n", e);
	printf("千位 : %d\n", d);
	printf("百位 : %d\n", c);
	printf("十位 : %d\n", b);
	printf("个位 : %d\n", a);
	return 0;
}