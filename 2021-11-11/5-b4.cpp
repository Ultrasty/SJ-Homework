/* 1851521 ������ �� */
#include<iostream>
using namespace std;

int main() {
	int num[1005];
	int sum[105];
	int n;
	char c;

	cout << "������ɼ������1000��������-1����" << endl;
	for (int i = 0; i < 1000; i++) {
		cin >> num[i];
		if (num[i] == -1)
			break;
	}

	if (num[0] == -1) {
		cout << "����Ч����" << endl;
		return 0;
	}

	cout << "���������Ϊ:";
	for (int i = 0; i < 1000; i++) {
		if (num[i] == -1) {
			break;
		}
		if (i % 10 == 0) {
			cout << endl;
		}
		cout << num[i] << " ";
	}
	cout << endl;


	while ((c = getchar()) != '\n' && c != EOF);
	cout << "�����������Ķ�Ӧ��ϵΪ:" << endl;

	for (int i = 0; i <= 100; i++) {
		sum[i] = 0;
	}

	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j < 1000; j++) {
			if (num[j] == i) {
				sum[i]++;
			}
		}
	}

	for (int i = 100; i >= 0; i--) {
		if (sum[i]) {
			cout << i << " " << sum[i] << endl;
		}
	}


	return 0;
}