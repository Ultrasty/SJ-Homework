/* 1851521 �� ������ */
#define _CRT_SECURE_NO_WARNINGS
#define pi 3.14159
#include <stdio.h>

int main()
{
	printf("������뾶�͸߶�\n");
	double r, h;
	scanf("%lf %lf", &r, &h);
	printf("Բ�ܳ�     : %.2f\n", pi * 2 * r);
	printf("Բ���     : %.2f\n", pi * r * r);
	printf("Բ������ : %.2f\n", pi * 4 * r * r);
	printf("Բ�����   : %.2f\n", pi * r * r * r * 4 / 3);
	printf("Բ�����   : %.2f\n", pi * r * r * h);
	return 0;
}