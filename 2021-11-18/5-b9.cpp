/* 1851521 �� ������ */
#include <iostream>
using namespace std;

void clear_number_there(bool number_there[]) {
	for (int i = 1; i <= 9; i++) {
		number_there[i] = 0;
	}
}

int is_thats_good(bool number_there[]) {
	int temp = 0;
	for (int j = 1; j <= 9; j++) {
		temp += number_there[j];
	}
	if (temp != 9)
		return 0;
	else
		return 1;
}

int main()
{
	cout << "������9*9�ľ���ֵΪ1-9֮��" << endl;
	char c;
	int sudoku[10][10];
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			while (1) {
				cin >> sudoku[i][j];
				if (cin.fail()) {
					cin.clear();
					while ((c = getchar()) != '\n' && c != EOF)
						;
					cout << "�����������" << i << "��" << j << "��(���о���1��ʼ����)��ֵ" << endl;
				}
				else
					break;
			}
		}
	}

	bool thats_good = 1;
	bool number_there[10];



	for (int i = 1; i <= 9; i++) {
		clear_number_there(number_there);
		for (int j = 1; j <= 9; j++) {
			number_there[sudoku[i][j]] = 1;
		}
		if (!is_thats_good(number_there))
			thats_good = 0;
	}

	for (int i = 1; i <= 9; i++) {
		clear_number_there(number_there);
		for (int j = 1; j <= 9; j++) {
			number_there[sudoku[j][i]] = 1;
		}
		if (!is_thats_good(number_there))
			thats_good = 0;
	}

	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			clear_number_there(number_there);
			for (int k = 1; k <= 9; k++) {
				number_there[sudoku[(i - 1) * 3 + (k - 1) / 3 + 1][(j - 1) * 3 + (k - 1) % 3 + 1]] = 1;
			}
			if (!is_thats_good(number_there))
				thats_good = 0;
		}
	}

	if (thats_good)
		cout << "�������Ľ�" << endl;
	else
		cout << "���������Ľ�" << endl;

	return 0;
}
