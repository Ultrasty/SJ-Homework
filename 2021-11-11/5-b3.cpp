/* 1851521 沈天宇 软工 */
#include<iostream>
using namespace std;

bool is_run_nian(int year) {
	//是闰年
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
		return true;
	}
	//不是闰年
	else {
		return false;
	}
}

int di_ji_tian(int year,int month,int day) {
	int run_nian[] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
	int not_run_nian[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int sum = 0;
	if (is_run_nian(year)) {
		for (int i = 0; i < month; i++) {
			sum += run_nian[i];
		}
		sum += day;
	}
	else {
		for (int i = 0; i < month; i++) {
			sum += not_run_nian[i];
		}
		sum += day;
	}
	return sum;
}

int main() {
	

	cout << "请输入年，月，日" << endl;
	int year, month, day;
	int count;
	cin >> year >> month >> day;
	

	count = di_ji_tian(year, month, day);
	

	cout << year << "-" << month << "-" << day << "是" << year << "年的第" << count << "天" << endl;

	return 0;
}