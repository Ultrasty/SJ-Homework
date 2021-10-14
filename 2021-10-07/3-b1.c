/* 1851521 软工 沈天宇 */
#define _CRT_SECURE_NO_WARNINGS
#define pi 3.14159
#include <stdio.h>

int main()
{
	printf("请输入半径和高度\n");
	double r, h;
	scanf("%lf %lf", &r, &h);
	printf("圆周长     : %.2f\n", pi * 2 * r);
	printf("圆面积     : %.2f\n", pi * r * r);
	printf("圆球表面积 : %.2f\n", pi * 4 * r * r);
	printf("圆球体积   : %.2f\n", pi * r * r * r * 4 / 3);
	printf("圆柱体积   : %.2f\n", pi * r * r * h);
	return 0;
}