/* 1851521 软工 沈天宇 */
#include <iostream>
#include <limits>
#include <iomanip>
using namespace std;

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

void add_to_calendar(int year, int month, int week, int calendar[6][21])
{
	
	int total;
	int count = 1;
	int column = 0;

	//1
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


	while (total) {

		calendar[column][week] = count;


		total--;
		count++;
		if (week % 6 == 0)
			column += 1;
		week = (week + 1) % 7;
	}
	//2
	month += 1;
	count = 1;
	column = 0;
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


	while (total) {

		calendar[column][week+7] = count;


		total--;
		count++;
		if (week % 6 == 0)
			column += 1;
		week = (week + 1) % 7;
	}


	//3
	month += 1;
	count = 1;
	column = 0;
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


	while (total) {

		calendar[column][week+14] = count;


		total--;
		count++;
		if (week % 6 == 0)
			column += 1;
		week = (week + 1) % 7;
	}
}

int main()
{
	system("mode con cols=120 lines=45");

	int year;
	int count = 1;
	char c;

	int calendar1[6][21];
	int calendar2[6][21];
	int calendar3[6][21];
	int calendar4[6][21];


	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 21; j++) {
			calendar1[i][j] = 0;
			calendar2[i][j] = 0;
			calendar3[i][j] = 0;
			calendar4[i][j] = 0;
		}
	}

	while (1) {
		cout << "请输入年份[1900-2100]" << endl;
		cin >> year;
		while ((c = getchar()) != '\n' && c != EOF)
			;
		if (cin.fail()) 
			cin.clear();
		if (year >= 1900 && year <= 2100)
			break;

	}


	for (int month = 1; month <= 3; month++) {
		add_to_calendar(year, month, zeller(year, month, 1), calendar1);
	}
	for (int month = 4; month <= 6; month++) {
		add_to_calendar(year, month, zeller(year, month, 1), calendar2);
	}
	for (int month = 7; month <= 9; month++) {
		add_to_calendar(year, month, zeller(year, month, 1), calendar3);
	}
	for (int month = 10; month <= 12; month++) {
		add_to_calendar(year, month, zeller(year, month, 1), calendar4);
	}

	cout << year << "年的日历:" << endl << endl;
	cout << "            1月                             2月                             3月" << endl;
	cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" << endl;

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 21; j++) {
			if (calendar1[i][j] == 0) {
				cout << "    ";
			}
			else
				cout << setfill(' ') << setw(4) << calendar1[i][j];

			if (j % 7 == 0)
				cout << "    ";
		}
		cout << endl;
	}


	cout << "            4月                             5月                             6月" << endl;
	cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" << endl;

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 21; j++) {
			if (calendar1[i][j] == 0) {
				cout << "    ";
			}
			else
				cout << setfill(' ') << setw(4) << calendar1[i][j];

			if (j % 7 == 0)
				cout << "    ";
		}
		cout << endl;
	}

	cout << "            7月                             8月                             9月" << endl;
	cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" << endl;

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 21; j++) {
			if (calendar1[i][j] == 0) {
				cout << "    ";
			}
			else
				cout << setfill(' ') << setw(4) << calendar1[i][j];

			if (j % 7 == 0)
				cout << "    ";
		}
		cout << endl;
	}

	cout << "           10月                            11月                            12月" << endl;
	cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" << endl;

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 21; j++) {
			if (calendar1[i][j] == 0) {
				cout << "    ";
			}
			else
				cout << setfill(' ') << setw(4) << calendar1[i][j];

			if (j % 7 == 0)
				cout << "    ";
		}
		cout << endl;
	}

	



	return 0;
}
