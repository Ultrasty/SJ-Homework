/* 1851521 ������ �� */
#include<iostream>
using namespace std;

int main() {
	int num[25];
	int n;
	char c;
	bool output_flag = 0;
	cout << "��������������������������20��������-1����" << endl;
	for (int i = 0; i < 20; i++) {
		cin >> num[i];
		if (num[i] == -1)
			break;
	}

	if (num[0] == -1) {
		cout << "����Ч����" << endl;
		return 0;
	}

	cout << "ԭ����Ϊ��" << endl;
	for (int i = 0; i < 20; i++) {
		if (num[i] == -1) {
			break;
		}
		cout << num[i] << " ";
	}
	cout << endl;
	while ((c = getchar()) != '\n' && c != EOF);
	cout << "������Ҫ�����������" << endl;
	cin >> n;
	cout << "����������Ϊ��" << endl;
	for (int i = 0; i < 20; i++) {
		if (num[i] == -1) {
			break;
		}
		if (num[i] > n && output_flag == 0) {
			cout << n << " ";
			output_flag = 1;
		}
		cout << num[i] << " ";
	}
	if (output_flag == 0) {
		cout << n << " ";
	}
	cout << endl;
	return 0;
}