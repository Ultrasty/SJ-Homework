/* 1851521 软工 沈天宇 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	printf("请输入年，月，日\n");
	int year, month, day;
	int count;
	scanf("%d%d%d",&year,&month,&day);
	if (month > 12 || month < 1) {
		printf("输入错误-月份不正确\n");
		return 0;
	}
	else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
		if (day < 1 || day>31) {
			printf("输入错误-日与月的关系非法\n");
			return 0;
		}
	}
	else if (month == 2) {
		//是闰年
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
			if (day < 1 || day>29) {
				printf("输入错误-日与月的关系非法\n");
				return 0;
			}
		}
		//不是闰年
		else if (day < 1 || day>28) {
			printf("输入错误-日与月的关系非法\n");
			return 0;
		}
	}
	else if (day < 1 || day>30) {
		printf("输入错误-日与月的关系非法\n");
		return 0;
	}

	//是闰年
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
		switch (month) {
			case 1:
				count = day;
				break;
			case 2:
				count = day + 31;
				break;
			case 3:
				count = day + 31 + 29;
				break;
			case 4:
				count = day + 31 + 29 + 31;
				break;
			case 5:
				count = day + 31 + 29 + 31 + 30;
				break;
			case 6:
				count = day + 31 + 29 + 31 + 30 + 31;
				break;
			case 7:
				count = day + 31 + 29 + 31 + 30 + 31 + 30;
				break;
			case 8:
				count = day + 31 + 29 + 31 + 30 + 31 + 30 + 31;
				break;
			case 9:
				count = day + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31;
				break;
			case 10:
				count = day + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
				break;
			case 11:
				count = day + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
				break;
			case 12:
				count = day + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
				break;
		}
	}
	//不是闰年
	else {
		switch (month) {
			case 1:
				count = day;
				break;
			case 2:
				count = day + 31;
				break;
			case 3:
				count = day + 31 + 28;
				break;
			case 4:
				count = day + 31 + 28 + 31;
				break;
			case 5:
				count = day + 31 + 28 + 31 + 30;
				break;
			case 6:
				count = day + 31 + 28 + 31 + 30 + 31;
				break;
			case 7:
				count = day + 31 + 28 + 31 + 30 + 31 + 30;
				break;
			case 8:
				count = day + 31 + 28 + 31 + 30 + 31 + 30 + 31;
				break;
			case 9:
				count = day + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31;
				break;
			case 10:
				count = day + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
				break;
			case 11:
				count = day + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
				break;
			case 12:
				count = day + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
				break;
		}
	}

	printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, count);

	return 0;
}
