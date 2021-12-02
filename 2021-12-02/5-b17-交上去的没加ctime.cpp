/* 1851521 沈天宇 软工 */
#include <iostream>
#include <cstring>
#include <ctime> 
using namespace std;

int read_data(int limit_low = INT_MIN, int limit_high = INT_MAX)
{
	int temp;
	char c;
	cin >> temp;

	if (cin.fail()) {
		cin.clear();
		while ((c = getchar()) != '\n' && c != EOF)
			;
		return -1;
	}
	else
		return temp;
}


int main()
{
	srand(time(NULL));
	static const char other[] = "~!@#$%^&*()-_=+[],.?";
	cout << "请输入密码长度(12-16)， 大写字母个数(≥2)， 小写字母个数(≥2)， 数字个数(≥2)， 其它符号个数(≥2)" << endl;

	int len = read_data(12, 16);
	if (len == -1) {
		cout << "输入非法" << endl;
		return 0;
	}

	int num_h = read_data(2);
	int ori_num_h = num_h;
	if (num_h == -1) {
		cout << "输入非法" << endl;
		return 0;
	}

	int num_l = read_data(2);
	int ori_num_l = num_l;
	if (num_l == -1) {
		cout << "输入非法" << endl;
		return 0;
	}

	int num_num = read_data(2);
	int ori_num_num = num_num;
	if (num_num == -1) {
		cout << "输入非法" << endl;
		return 0;
	}

	int num_other = read_data(2);
	int ori_num_other = num_other;
	if (num_other == -1) {
		cout << "输入非法" << endl;
		return 0;
	}



	if (len < 12 || len >16) {
		cout << "密码长度[" << len << "]不正确" << endl;
		return 0;
	}

	if (num_h < 2) {
		cout << "大写字母个数[" << num_h << "]不正确" << endl;
		return 0;
	}

	if (num_l < 2) {
		cout << "小写字母个数[" << num_l << "]不正确" << endl;
		return 0;
	}

	if (num_num < 2) {
		cout << "数字个数[" << num_num << "]不正确" << endl;
		return 0;
	}

	if (num_other < 2) {
		cout << "其他符号个数[" << num_other << "]不正确" << endl;
		return 0;
	}

	if (num_h + num_l + num_num + num_other > len) {
		cout << "所有字符类型之和[" << num_h << "+" << num_l << "+" << num_num << "+" << num_other << "]大于总密码长度[" << len << "]" << endl;
		return 0;
	}

	int i = 0;
	while(i<10){
		char result[16];

		num_h = ori_num_h;
		num_l = ori_num_l;
		num_num = ori_num_num;
		num_other = ori_num_other;
		

		for (int j = 0; j < len; j++) {
			result[j] = rand() % 94 + 33;
		}
		for (int j = 0; j < len; j++) {
			if (result[j] >= 'a' && result[j] <= 'z') {
				num_l--;
			}
			if (result[j] >= 'A' && result[j] <= 'Z') {
				num_h--;
			}
			if (result[j] >= '0' && result[j] <= '9') {
				num_num--;
			}
			for (int k = 0; k < 20; k++) {
				if (result[j] == other[k]) {
					num_other--;
				}
			}
		}
		if (num_l <= 0 && num_h <= 0 && num_num <= 0 && num_other <= 0) {
			i++;
			for (int j = 0; j < len; j++) {
				cout << char(result[j]);
			}
			cout << endl;
		}
		
	}

	return 0;
}
