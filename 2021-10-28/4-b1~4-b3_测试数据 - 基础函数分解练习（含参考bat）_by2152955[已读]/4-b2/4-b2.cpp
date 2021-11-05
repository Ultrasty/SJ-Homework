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

int main()
{
	int year, month, day, week;
	int count = 1;

	while (1) {
		cout << "请输入年[1900-2100]、月、日：" << endl;
		cin >> year >> month >> day;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			cout << "输入错误，请重新输入" << endl;
			return 0;
		}
		else if (year < 1900 || year > 2100) {
			cout << "年份不正确，请重新输入" << endl;
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			return 0;
		}
		else if (month > 12 || month < 1) {
			cout << "月份不正确，请重新输入" << endl;
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			return 0;
		}
		else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
			if (day < 1 || day>31) {
				cout << "日不正确，请重新输入" << endl;
				cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
				return 0;
			}
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11) {
			if (day < 1 || day>30) {
				cout << "日不正确，请重新输入" << endl;
				cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
				return 0;
			}
		}
		else if (month == 2) {
			if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
				if (day < 1 || day>29) {
					cout << "日不正确，请重新输入" << endl;
					cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
					return 0;
				}
			}

			else if (day < 1 || day>28) {
				cout << "日不正确，请重新输入" << endl;
				cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
				return 0;
			}
			
		}

		

		break;
	}

	

	week = zeller(year, month, day);
	

	
	
	switch (week) {
		case 0:
			cout << "星期日" << endl;
			break;
		case 1:
			cout << "星期一" << endl;
			break;
		case 2:
			cout << "星期二" << endl;
			break;
		case 3:
			cout << "星期三" << endl;
			break;
		case 4:
			cout << "星期四" << endl;
			break;
		case 5:
			cout << "星期五" << endl;
			break;
		case 6:
			cout << "星期六" << endl;
			break;
		default:
			break;
	}


	return 0;
}
