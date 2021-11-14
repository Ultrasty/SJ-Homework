/* 1851521 沈天宇 软工 */
#include<iostream>
using namespace std;


int min(int a = INT_MAX, int b = INT_MAX, int c = INT_MAX, int d = INT_MAX)
{
	int num_min = INT_MAX;
	if (num_min > a)
		num_min = a;
	if (num_min > b)
		num_min = b;
	if (num_min > c)
		num_min = c;
	if (num_min > d)
		num_min = d;
	return num_min;
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
		cout << "min=" << min(a, b) << endl;
	if (_count == 3)
		cout << "min=" << min(a, b, c) << endl;
	if (_count == 4)
		cout << "min=" << min(a, b, c, d) << endl;
	return 0;

}