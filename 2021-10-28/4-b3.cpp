/* 1851521 软工 沈天宇 */
#include <iostream>
#include <limits>
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

void print_calendar(int year, int month, int week)
{
	int total;
	int count = 1;

	cout << endl << year << "年" << month << "月" << endl;
	cout << "======================================================" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
	cout << "======================================================" << endl;

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
		cout << "        ";
	}

	while (total) {

		if (count < 10) {
			cout << "   " << count << "    ";
		}
		else
			cout << "  " << count << "    ";

		if (week == 6)
			cout << endl;

		total--;
		count++;
		week = (week + 1) % 7;
	}


	cout << endl;
	cout << endl;

}

int main()
{
	int year, month, week;
	int count = 1;

	while (1) {
		cout << "请输入年[1900-2100]、月" << endl;
		cin >> year >> month;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			cout << "输入错误，请重新输入" << endl;
			continue;
		}
		else if (year < 1900 || year > 2100) {
			cout << "年份不正确，请重新输入" << endl;
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		else if (month > 12 || month < 1) {
			cout << "月份不正确，请重新输入" << endl;
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		break;
	}



	week = zeller(year, month, 1);
	print_calendar(year, month, week);



	return 0;
}
