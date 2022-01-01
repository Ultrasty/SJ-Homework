/* 1851521 软工 沈天宇 */
//放一些内部数组/图形方式公用的函数，如判断结束等

#include"90-b2.h"

int get_max_num(int data[10][10],int max_x,int max_y)
{
	int max_num = 0;
	for (int i = 0; i < max_x; i++) {
		for (int j = 0; j < max_y; j++) {
			if (max_num < data[i][j]) {
				max_num = data[i][j];
			}
		}
	}
	return max_num;
}

void fall_step(int data[10][10], int i, int j)
{
	swap(data[i][j], data[i][j - 1]);
}

void fall(int data[10][10], int max_x, int max_y)
{
	while (1) {
		int anything_changed = 0;
		for (int j = max_y - 1; j >= 0; j--) {
			for (int i = max_x - 1; i >= 0; i--) {
				if (data[i][j] == 0 && j - 1 >= 0 && data[i][j - 1] != 0) {
					fall_step(data, i, j);
					anything_changed = 1;
				}
			}
		}
		if (!anything_changed) {
			break;
		}
	}
}

int merge(int data[10][10], int max_x, int max_y, int x, int y, int find_result[10][10])
{
	int score = 0;
	for (int i = 0; i < max_x; i++) {
		for (int j = 0; j < max_y; j++) {
			if (find_result[i][j] == 1) {
				score++;
			}
		}
	}
	score *= 3 * data[x][y];

	for (int i = 0; i < max_x; i++) {
		for (int j = 0; j < max_y; j++) {
			if (i == x && j == y) {
				data[i][j]++;
			}
			else if (find_result[i][j] == 1) {
				data[i][j] = 0;
			}
		}
	}

	return score;
}

void generate_data(int data[10][10], int max_x, int max_y)
{
	int max_num = 0;
	for (int i = 0; i < max_x; i++) {
		for (int j = 0; j < max_y; j++) {
			if (max_num < data[i][j]) {
				max_num = data[i][j];
			}
		}
	}

	srand((unsigned)time(NULL));
	for (int i = 0; i < max_x; i++) {
		for (int j = 0; j < max_y; j++) {
			if (data[i][j] == 0) {
				int temp = 0;
				if (max_num <= 3) {
					temp = rand() % 3 + 1;
				}
				if (max_num == 4) {
					temp = rand() % 10;
					if (temp == 9) {
						temp = 4;
					}
					else {
						temp = temp % 3 + 1;
					}
				}
				if (max_num == 5) {
					temp = rand() % 100;
					if (temp >= 90) {
						temp = 5;
					}
					else if (temp >= 75 && temp < 90) {
						temp = 4;
					}
					else {
						temp = temp % 3 + 1;
					}
				}
				if (max_num == 6) {
					temp = rand() % 100;
					if (temp >= 95) {
						temp = 6;
					}
					else if (temp >= 80 && temp < 95) {
						temp = 5;
					}
					else {
						temp = temp % 4 + 1;
					}
				}
				if (max_num > 6) {
					temp = rand() % 100;
					if (temp >= 95) {
						temp = max_num;
					}
					else if (temp >= 90 && temp < 95) {
						temp = max_num - 1;
					}
					else if (temp >= 80 && temp < 90) {
						temp = max_num - 2;
					}
					else {
						temp = rand() % (max_num - 3) + 1;
					}
				}
				data[i][j] = temp;
			}
		}
	}
}

void print_data_with_color(int data[10][10], int max_x, int max_y, int find_result[10][10])
{
	cout << endl;
	cout << "当前数组(不同色标识)：" << endl;
	cout << "  |";
	for (int i = 0; i < max_x; i++) {
		cout << setw(3) << i + 1;
	}
	cout << endl;
	cout << "--+";
	for (int i = 0; i < max_x; i++) {
		cout << "---";
	}
	cout << endl;
	for (int j = 0; j < max_y; j++) {
		cout << char('A' + j) << " |";
		for (int i = 0; i < max_x; i++) {
			if (find_result[i][j] == 1) {
				if (data[i][j] >= 10) {
					cout << " ";
				}
				if (data[i][j] < 10) {
					cout << "  ";
				}
				cct_setcolor(COLOR_YELLOW, COLOR_BLACK);
				cout << data[i][j];
				cct_setcolor();
			}
			else {
				cout << setw(3) << data[i][j];
			}

		}
		cout << endl;
	}
}

void print_find_result(int find_result[10][10], int max_x, int max_y)
{
	cout << endl;
	cout << "查找结果数组：" << endl;
	cout << "  |";
	for (int i = 0; i < max_x; i++) {
		cout << setw(3) << i + 1;
	}
	cout << endl;
	cout << "--+";
	for (int i = 0; i < max_x; i++) {
		cout << "---";
	}
	cout << endl;
	for (int j = 0; j < max_y; j++) {
		cout << char('A' + j) << " |";
		for (int i = 0; i < max_x; i++) {
			cout << setw(3) << ((find_result[i][j] == 1) ? '*' : '0');
		}
		cout << endl;
	}
}

void print_data(int data[10][10], int max_x, int max_y)
{
	cout << endl;
	cout << "当前数组：" << endl;
	cout << "  |";
	for (int i = 0; i < max_x; i++) {
		cout << setw(3) << i + 1;
	}
	cout << endl;
	cout << "--+";
	for (int i = 0; i < max_x; i++) {
		cout << "---";
	}
	cout << endl;
	for (int j = 0; j < max_y; j++) {
		cout << char('A' + j) << " |";
		for (int i = 0; i < max_x; i++) {
			cout << setw(3) << data[i][j];
		}
		cout << endl;
	}
}

void find_congener_recursion(int data[10][10], int max_x, int max_y, int x, int y, int find_result[10][10])
{
	if (x + 1 < max_x && find_result[x + 1][y] == 0 && data[x + 1][y] == data[x][y]) {
		find_result[x + 1][y] = 1;
		find_congener_recursion(data, max_x, max_y, x + 1, y, find_result);
	}
	if (x - 1 >= 0 && find_result[x - 1][y] == 0 && data[x - 1][y] == data[x][y]) {
		find_result[x - 1][y] = 1;
		find_congener_recursion(data, max_x, max_y, x - 1, y, find_result);
	}
	if (y + 1 < max_y && find_result[x][y + 1] == 0 && data[x][y + 1] == data[x][y]) {
		find_result[x][y + 1] = 1;
		find_congener_recursion(data, max_x, max_y, x, y + 1, find_result);
	}
	if (y - 1 >= 0 && find_result[x][y - 1] == 0 && data[x][y - 1] == data[x][y]) {
		find_result[x][y - 1] = 1;
		find_congener_recursion(data, max_x, max_y, x, y - 1, find_result);
	}
}

void find_congener(int data[10][10], int max_x, int max_y, int x, int y, int find_result[10][10])
{

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			find_result[i][j] = 0;
		}
	}

	find_result[x][y] = 1;

	while (1) {
		int anything_changed = 0;
		for (int i = 0; i < max_x; i++) {
			for (int j = 0; j < max_y; j++) {
				if (find_result[i][j] == 1) {
					if (i + 1 < max_x && find_result[i + 1][j] == 0 && data[i + 1][j] == data[i][j]) {
						anything_changed = 1;
						find_result[i + 1][j] = 1;
					}
					if (i - 1 >= 0 && find_result[i - 1][j] == 0 && data[i - 1][j] == data[i][j]) {
						anything_changed = 1;
						find_result[i - 1][j] = 1;
					}
					if (j + 1 < max_y && find_result[i][j + 1] == 0 && data[i][j + 1] == data[i][j]) {
						anything_changed = 1;
						find_result[i][j + 1] = 1;
					}
					if (j - 1 >= 0 && find_result[i][j - 1] == 0 && data[i][j - 1] == data[i][j]) {
						anything_changed = 1;
						find_result[i][j - 1] = 1;
					}
				}
			}
		}
		if (anything_changed == 0) {
			break;
		}
	}
}