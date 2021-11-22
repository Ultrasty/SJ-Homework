/* 1851521 ������ �� */
#include <iostream>

using namespace std;

int is_base(int number, int base) {
	if (number == 1) {
		return  1;
	}
	if (number % base == 0) {
		return is_base(number / base, base);
	}
	if (number % base != 0) {
		return 0;
	}
	return 0;
}


int main() {
	int number[10000];
	int n, base;
	int result = 0;
	cout << "���������ݵĸ���[1..10000]" << endl;
	cin >> n;
	cout << "������" << n << "��������" << endl;

	for (int i = 0; i < n; i++) {
		cin >> number[i];
	}

	cout << "���������[2..9]" << endl;
	cin >> base;

	for (int i = 0; i < n; i++) {
		if (is_base(number[i], base)) {
			result++;
		}
	}

	cout << n << "�����л���" << base << "���ݵĸ��� : " << result << endl;

	return 0;
}