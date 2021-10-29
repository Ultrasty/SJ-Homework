/* 1851521 软工 沈天宇 */
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
		printf("请输入年[1900-2100]、月、日：\n");
		ret = scanf("%d%d%d", &year, &month, &day);

		if (ret != 3) {
			scanf("%*[^\n]");
			scanf("%*c");
			printf("输入错误，请重新输入\n");
			continue;
		}
		else if (year < 1900 || year > 2100) {
			printf("年份不正确，请重新输入\n");
			scanf("%*[^\n]");
			scanf("%*c");
			continue;
		}
		else if (month > 12 || month < 1) {
			printf("月份不正确，请重新输入\n");
			scanf("%*[^\n]");
			scanf("%*c");
			continue;
		}
		else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
			if (day < 1 || day>31) {
				printf("日不正确，请重新输入\n");
				scanf("%*[^\n]");
				scanf("%*c");
				continue;
			}
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11) {
			if (day < 1 || day>30) {
				printf("日不正确，请重新输入\n");
				scanf("%*[^\n]");
				scanf("%*c");
				continue;
			}
		}
		else if (month == 2) {
			if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
				if (day < 1 || day>29) {
					printf("日不正确，请重新输入\n");
					scanf("%*[^\n]");
					scanf("%*c");
					continue;
				}
			}

			else if (day < 1 || day>28) {
				printf("日不正确，请重新输入\n");
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
			printf("星期日\n");
			break;
		case 1:
			printf("星期一\n");
			break;
		case 2:
			printf("星期二\n");
			break;
		case 3:
			printf("星期三\n");
			break;
		case 4:
			printf("星期四\n");
			break;
		case 5:
			printf("星期五\n");
			break;
		case 6:
			printf("星期六\n");
			break;
		default:
			break;
	}


	return 0;
}
