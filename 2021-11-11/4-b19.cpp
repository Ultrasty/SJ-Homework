/* 1851521 沈天宇 软工 */
#include<iostream>
using namespace std;

int max(int a, int b)
{
	return a > b ? a : b;
}

int max(int a, int b, int c)
{
	return max(a, max(b, c));
}

int max(int a, int b, int c, int d)
{
	return max(a, max(b, max(c, d)));
}




int main()
{

	char ch;
	int _count, a, b, c, d;
	while (1) {
		cout << "请输入个数num及num个正整数：" << endl;
		cin >> _count;
		if (cin.fail()) {
			cin.clear();
			while ((ch = getchar()) != '\n' && ch != EOF);
			continue;
		}

		if (_count == 2) {
			cin >> a >> b;
			if (cin.fail() || a < 0 || b < 0) {
				cin.clear();
				while ((ch = getchar()) != '\n' && ch != EOF);
				continue;
			}
			else
				break;
		}
		else if (_count == 3) {
			cin >> a >> b >> c;
			if (cin.fail() || a < 0 || b < 0 || c < 0) {
				cin.clear();
				while ((ch = getchar()) != '\n' && ch != EOF);
				continue;
			}
			else
				break;
		}
		else if (_count == 4) {
			cin >> a >> b >> c >> d;
			if (cin.fail() || a < 0 || b < 0 || c < 0 || d < 0) {
				cin.clear();
				while ((ch = getchar()) != '\n' && ch != EOF);
				continue;
			}
			else
				break;
		}
		else {
			while ((ch = getchar()) != '\n' && ch != EOF);
			cout << "个数输入错误" << endl;
			return 0;
		}
	}

	if (_count == 2)
		cout << "max=" << max(a, b) << endl;
	if (_count == 3)
		cout << "max=" << max(a, b, c) << endl;
	if (_count == 4)
		cout << "max=" << max(a, b, c, d) << endl;
	return 0;

}