/* 1851521 �� ������ */
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	cout << "�������꣬�£���" << endl;
	int year, month, day;
	int count;
	cin >> year >> month >> day;
	if (month > 12 || month < 1) {
		cout << "�������-�·ݲ���ȷ" << endl;
		return 0;
	}
	else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
		if (day < 1 || day>31) {
			cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			return 0;
		}
	}
	else if (month == 2) {
		//������
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
			if (day < 1 || day>29) {
				cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				return 0;
			}
		}
		//��������
		else if (day < 1 || day>28) {
			cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			return 0;
		}
	}
	else if (day < 1 || day>30) {
		cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
		return 0;
	}

	//������
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
	//��������
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

	cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << count << "��" << endl;


	return 0;
}
