/* 1851521 软工 沈天宇 */
#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
	cout << "请输入一个[1..30000]间的整数" << endl;
	int n, a, b, c, d, e;
	cin >> n;
	a = n % 10;
	b = n / 10 % 10;
	c = n / 100 % 10;
	d = n / 1000 % 10;
	e = n / 10000 % 10;
	cout << "万位 : " << e << endl;
	cout << "千位 : " << d << endl;
	cout << "百位 : " << c << endl;
	cout << "十位 : " << b << endl;
	cout << "个位 : " << a << endl;
	return 0;
}
