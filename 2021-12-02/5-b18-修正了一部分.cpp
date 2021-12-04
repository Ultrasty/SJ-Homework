/* 1851521 ÉòÌìÓî Èí¹¤ */

#include <iostream>
#include <cstring>
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

	static const char other[] = "~!@#$%^&*()-_=+[],.?";
	
	char c;
	while ((c = getchar()) != '\n' && c != EOF)
		;


	int len = read_data(12, 16);
	if (len == -1) {
		cout << "´íÎó" << endl;
		return 0;
	}

	int num_h = read_data(2);
	int ori_num_h = num_h;
	if (num_h == -1) {
		cout << "´íÎó" << endl;
		return 0;
	}

	int num_l = read_data(2);
	int ori_num_l = num_l;
	if (num_l == -1) {
		cout << "´íÎó" << endl;
		return 0;
	}

	int num_num = read_data(2);
	int ori_num_num = num_num;
	if (num_num == -1) {
		cout << "´íÎó" << endl;
		return 0;
	}

	int num_other = read_data(2);
	int ori_num_other = num_other;
	if (num_other == -1) {
		cout << "´íÎó" << endl;
		return 0;
	}



	if (len < 12 || len >16) {
		cout << "´íÎó" << endl;
		return 0;
	}

	if (num_h < 2) {
		cout << "´íÎó" << endl;
		return 0;
	}

	if (num_l < 2) {
		cout << "´íÎó" << endl;
		return 0;
	}

	if (num_num < 2) {
		cout << "´íÎó" << endl;
		return 0;
	}

	if (num_other < 2) {
		cout << "´íÎó" << endl;
		return 0;
	}

	if (num_h + num_l + num_num + num_other > len) {
		cout << "´íÎó" << endl;
		return 0;
	}

	for(int i =0;i<10;i++){

		char result[17];
		cin >> result;

		num_h = ori_num_h;
		num_l = ori_num_l;
		num_num = ori_num_num;
		num_other = ori_num_other;


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
		if (!(num_l <= 0 && num_h <= 0 && num_num <= 0 && num_other <= 0)) {
			cout << "´íÎó" << endl;
			return 0;
		}

	}

	cout << "ÕıÈ·" << endl;

	return 0;
}