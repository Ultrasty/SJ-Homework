/* 1851521 �� ������ */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int zeller(int y, int m, int d)
{
	if (m == 1 || m == 2) {
		y -= 1;
		m += 12;
	}

	int w;
	int c;
	c = y / 100;
	y = y % 100;
	w = y + y / 4 + c / 4 - 2 * c + 13 * (m + 1) / 5 + d - 1;
	while (w < 0) {
		w += 7;
	}
	w %= 7;
	return w;
}

int main()
{
	int year, month, day, week;
	int count = 1;
	int ret;

	while (1) {
		printf("��������[1900-2100]���¡��գ�\n");
		ret = scanf("%d%d%d", &year, &month, &day);

		if (ret != 3) {
			scanf("%*[^\n]");
			scanf("%*c");
			printf("�����������������\n");
			continue;
		}
		else if (year < 1900 || year > 2100) {
			printf("��ݲ���ȷ������������\n");
			scanf("%*[^\n]");
			scanf("%*c");
			continue;
		}
		else if (month > 12 || month < 1) {
			printf("�·ݲ���ȷ������������\n");
			scanf("%*[^\n]");
			scanf("%*c");
			continue;
		}
		else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
			if (day < 1 || day>31) {
				printf("�ղ���ȷ������������\n");
				scanf("%*[^\n]");
				scanf("%*c");
				continue;
			}
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11) {
			if (day < 1 || day>30) {
				printf("�ղ���ȷ������������\n");
				scanf("%*[^\n]");
				scanf("%*c");
				continue;
			}
		}
		else if (month == 2) {
			if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
				if (day < 1 || day>29) {
					printf("�ղ���ȷ������������\n");
					scanf("%*[^\n]");
					scanf("%*c");
					continue;
				}
			}

			else if (day < 1 || day>28) {
				printf("�ղ���ȷ������������\n");
				scanf("%*[^\n]");
				scanf("%*c");
				continue;
			}

		}



		break;
	}



	week = zeller(year, month, day);




	switch (week) {
		case 0:
			printf("������\n");
			break;
		case 1:
			printf("����һ\n");
			break;
		case 2:
			printf("���ڶ�\n");
			break;
		case 3:
			printf("������\n");
			break;
		case 4:
			printf("������\n");
			break;
		case 5:
			printf("������\n");
			break;
		case 6:
			printf("������\n");
			break;
		default:
			break;
	}


	return 0;
}
