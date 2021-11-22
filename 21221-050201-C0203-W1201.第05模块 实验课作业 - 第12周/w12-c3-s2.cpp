/* 1851521 沈天宇 软工 */
#include <iostream>
#include<iomanip>
using namespace std;




int main() {
	int lines;
	int yanghui[13][13];
	cout << "请输入要打印的行数[3..13]" << endl;
	cin >> lines;


	for (int i = 0; i < lines; i++) {
		yanghui[i][0] = 1;
		yanghui[i][i] = 1;
	}

	for (int i = 2; i < lines; i++) {
		for (int j = 1; j < i; j++) {
			yanghui[i][j] = yanghui[i - 1][j - 1] + yanghui[i - 1][j];
		}
	}


	cout << setiosflags(ios::right);

	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "0         1         2         3         4         5         6         7         " << endl;
	cout << "01234567890123456789012345678901234567890123456789012345678901234567890123456789" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;


	for (int i = 0; i < lines; i++) {
		for (int j = 0; j <= i; j++) {
			cout << setfill(' ') << setw(6) << yanghui[i][j];
		}
		cout << endl;
	}




	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "01234567890123456789012345678901234567890123456789012345678901234567890123456789" << endl;
	cout << "0         1         2         3         4         5         6         7         " << endl;
	cout << "--------------------------------------------------------------------------------" << endl << endl;


	return 0;
}