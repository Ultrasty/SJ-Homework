/* 1851521 软工 沈天宇 */
#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;

int zeller(int y, int m, int d)
{
	if (m == 1 || m == 2) {
		y -= 1;
		m += 12;
	}

	int w;
	int c;
	c = y / 100;
	y = y % 100;
	w = y + y / 4 + c / 4 - 2 * c + 13 * (m + 1) / 5 + d - 1;
	while (w < 0) {
		w += 7;
	}
	w %= 7;
	return w;
}



int main()
{
	system("mode con cols=120 lines=45");

	int year;
	int count = 1;
	char c;

	// IVT
	int day_count[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int IVT[12] = { 1,1,1,1,1,1,1,1,1,1,1,1 };
	int end_flag[12] = { 0,0,0,0,0,0,0,0,0,0,0,0 };

	cout << setiosflags(ios::left) << setfill(' ');
	while (1) {
		cout << "请输入年份[1900-2100]" << endl;
		cin >> year;
		while ((c = getchar()) != '\n' && c != EOF)
			;
		if (cin.fail())
			cin.clear();
		if (year >= 1900 && year <= 2100)
			break;

	}

	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		day_count[1] += 1;
	}

	int j;
	cout << year << "年的日历:" << endl << endl;
	for (int i = 0; i < 4; i++) {
		cout << resetiosflags(ios::left);
		cout << setiosflags(ios::right);
		cout << setw(13) << i * 3 + 1 << "月" << setw(30) << i * 3 + 2 << "月" << setw(30) << i * 3 + 3 << "月" << endl;
		cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" << endl;
		cout << resetiosflags(ios::right);
		cout << setiosflags(ios::left);
		j = 0;
		while (IVT[i * 3] != day_count[i * 3] + 1 || IVT[i * 3 + 1] != day_count[i * 3 + 1] + 1 || IVT[i * 3 + 2] != day_count[i * 3 + 2] + 1) {

			while (IVT[i * 3 + j] != day_count[i * 3 + j] + 1) {
				if (IVT[i * 3 + j] == 1) {
					for (int k = 0; k < zeller(year, i * 3 + j + 1, 1); k++) {
						cout << "    ";
					}
				}

				cout << setfill(' ') << setw(4) << IVT[i * 3 + j];
				IVT[i * 3 + j]++;

				if ((IVT[i * 3 + j] != day_count[i * 3 + j] + 1) && zeller(year, i * 3 + j + 1, IVT[i * 3 + j]) == 0) {
					if(j != 2)
						cout << "    ";
					break;
				}
			}

			if (end_flag[i * 3 + j] == 1) {
				cout << "                            ";
			}

			if (end_flag[i * 3 + j] == 0 && IVT[i * 3 + j] == day_count[i * 3 + j] + 1) {
				for (int l = 0; l < 6 - zeller(year, i * 3 + j + 1, day_count[i * 3 + j]); l++) {
					cout << "    ";
				}
				if (j != 2) {
					cout << "    ";
				}
				end_flag[i * 3 + j] = 1;
			}

			if (j == 2 && (IVT[i * 3] != day_count[i * 3] + 1 || IVT[i * 3 + 1] != day_count[i * 3 + 1] + 1 || IVT[i * 3 + 2] != day_count[i * 3 + 2] + 1)) {
				cout << endl;
			}
			j = (j + 1) % 3;
		}
		cout << endl << endl;
	}

	return 0;
}
