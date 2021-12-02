/* 1851521 ������ �� */
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
	cout << "���������볤��(12-16)�� ��д��ĸ����(��2)�� Сд��ĸ����(��2)�� ���ָ���(��2)�� �������Ÿ���(��2)" << endl;

	int len = read_data(12, 16);
	if (len == -1) {
		cout << "����Ƿ�" << endl;
		return 0;
	}

	int num_h = read_data(2);
	int ori_num_h = num_h;
	if (num_h == -1) {
		cout << "����Ƿ�" << endl;
		return 0;
	}

	int num_l = read_data(2);
	int ori_num_l = num_l;
	if (num_l == -1) {
		cout << "����Ƿ�" << endl;
		return 0;
	}

	int num_num = read_data(2);
	int ori_num_num = num_num;
	if (num_num == -1) {
		cout << "����Ƿ�" << endl;
		return 0;
	}

	int num_other = read_data(2);
	int ori_num_other = num_other;
	if (num_other == -1) {
		cout << "����Ƿ�" << endl;
		return 0;
	}



	if (len < 12 || len >16) {
		cout << "���볤��[" << len << "]����ȷ" << endl;
		return 0;
	}

	if (num_h < 2) {
		cout << "��д��ĸ����[" << num_h << "]����ȷ" << endl;
		return 0;
	}

	if (num_l < 2) {
		cout << "Сд��ĸ����[" << num_l << "]����ȷ" << endl;
		return 0;
	}

	if (num_num < 2) {
		cout << "���ָ���[" << num_num << "]����ȷ" << endl;
		return 0;
	}

	if (num_other < 2) {
		cout << "�������Ÿ���[" << num_other << "]����ȷ" << endl;
		return 0;
	}

	if (num_h + num_l + num_num + num_other > len) {
		cout << "�����ַ�����֮��[" << num_h << "+" << num_l << "+" << num_num << "+" << num_other << "]���������볤��[" << len << "]" << endl;
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
