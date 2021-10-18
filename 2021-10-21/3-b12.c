/* 1851521 �� ������ */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int ret;
	int year, month, week, total;
	int count = 1;

	while (1) {
		printf("���������(2000-2030)���·�(1-12) : ");
		ret = scanf("%d%d", &year, &month);
		if (ret != 2) {
			//������뻺����
			scanf("%*[^\n]");
			scanf("%*c");
			printf("����Ƿ�������������\n");
		}
		else if (year >= 2000 && year <= 2030 && month >= 1 && month <= 12)
			break;
		else
			printf("����Ƿ�������������\n");
	}

	while (1) {
		printf("������%d��%d��1�յ�����(0-6��ʾ������-������) : ",year,month);
		ret = scanf("%d", &week);
		if (ret != 1) {
			//������뻺����
			scanf("%*[^\n]");
			scanf("%*c");
			printf("����Ƿ�������������\n");
		}
		else if (week >= 0 && week <= 6)
			break;
		else
			printf("����Ƿ�������������\n");
	}

	printf("\n%d��%d�µ�����Ϊ:\n", year, month);
	printf("������  ����һ  ���ڶ�  ������  ������  ������  ������\n");

	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		total = 31;

	if (month == 4 || month == 6 || month == 9 || month == 11)
		total = 30;

	if (month == 2) {
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
			total = 29;
		else
			total = 28;
	}

	for (int i = 0; i < week; i++) {
		printf("        ");
	}

	while (total) {

		if (count < 10) {
			printf("   %d    ", count);
		}
		else
			printf("  %d    ", count);

		if (week == 6)
			printf("\n");

		total--;
		count++;
		week = (week + 1) % 7;
	}

	if (week)
		printf("\n");

	return 0;
}
