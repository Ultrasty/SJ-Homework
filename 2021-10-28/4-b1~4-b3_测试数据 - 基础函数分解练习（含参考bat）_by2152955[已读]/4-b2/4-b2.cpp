/* 1851521 �� ������ */
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
		cout << "��������[1900-2100]���¡��գ�" << endl;
		cin >> year >> month >> day;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			cout << "�����������������" << endl;
			return 0;
		}
		else if (year < 1900 || year > 2100) {
			cout << "��ݲ���ȷ������������" << endl;
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			return 0;
		}
		else if (month > 12 || month < 1) {
			cout << "�·ݲ���ȷ������������" << endl;
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			return 0;
		}
		else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
			if (day < 1 || day>31) {
				cout << "�ղ���ȷ������������" << endl;
				cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
				return 0;
			}
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11) {
			if (day < 1 || day>30) {
				cout << "�ղ���ȷ������������" << endl;
				cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
				return 0;
			}
		}
		else if (month == 2) {
			if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
				if (day < 1 || day>29) {
					cout << "�ղ���ȷ������������" << endl;
					cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
					return 0;
				}
			}

			else if (day < 1 || day>28) {
				cout << "�ղ���ȷ������������" << endl;
				cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
				return 0;
			}
			
		}

		

		break;
	}

	

	week = zeller(year, month, day);
	

	
	
	switch (week) {
		case 0:
			cout << "������" << endl;
			break;
		case 1:
			cout << "����һ" << endl;
			break;
		case 2:
			cout << "���ڶ�" << endl;
			break;
		case 3:
			cout << "������" << endl;
			break;
		case 4:
			cout << "������" << endl;
			break;
		case 5:
			cout << "������" << endl;
			break;
		case 6:
			cout << "������" << endl;
			break;
		default:
			break;
	}


	return 0;
}
