/* 1851521 软工 沈天宇 */
#define _CRT_SECURE_NO_WARNINGS
#define pi 3.14159
#include <stdio.h>
#include <math.h>
int main()
{
	int a, b, angle;
	printf("请输入三角形的两边及其夹角(角度)\n");
	scanf("%d%d%d", &a, &b, &angle);
	float ans = (float)(sin(pi * angle / 180) * a * b / 2);
	printf("三角形面积为 : %.3f\n", ans);
	return 0;
}