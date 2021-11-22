/* 1851521 软工 沈天宇 */
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
	cout << "请输入9*9的矩阵，值为1-9之间" << endl;
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
					cout << "请重新输入第" << i << "行" << j << "列(行列均从1开始计数)的值" << endl;
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
		cout << "是数独的解" << endl;
	else
		cout << "不是数独的解" << endl;

	return 0;
}
