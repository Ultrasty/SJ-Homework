/* 1851521 软工 沈天宇 */
#include <iostream>
#include <limits>
using namespace std;

int main()
{
	int year, month, week, total;
	int count = 1;

	while (1) {
		cout << "请输入年份(2000-2030)和月份(1-12) : ";
		cin >> year >> month;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			cout << "输入非法，请重新输入" << endl;
		}
		else if (year >= 2000 && year <= 2030 && month >= 1 && month <= 12)
			break;
		else
			cout << "输入非法，请重新输入" << endl;
	}

	while (1) {
		cout << "请输入" << year << "年" << month << "月1日的星期(0-6表示星期日-星期六) : ";
		cin >> week;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			cout << "输入非法，请重新输入" << endl;
		}
		else if (week >= 0 && week <= 6)
			break;
		else
			cout << "输入非法，请重新输入" << endl;
	}

	cout << endl << year << "年" << month << "月的月历为:" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;

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

	if (week)
		cout << endl;

	return 0;
}
