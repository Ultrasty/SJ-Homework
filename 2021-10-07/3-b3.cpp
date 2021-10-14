/* 1851521 软工 沈天宇 */
#include <cmath>
#include <iostream>
using namespace std;
int main()
{
	cout << "请输入[0-100亿)之间的数字:\n";
	double n;
	cin >> n;
	int a, b, c, d, e, f, g, h, i, j, k, l;
	a = (int)(n / 1000000000) % 10;
	b = (int)(n / 100000000) % 10;
	c = (int)(n / 10000000) % 10;
	d = (int)(n / 1000000) % 10;
	e = (int)(n / 100000) % 10;
	f = (int)(n / 10000) % 10;
	g = (int)(n / 1000) % 10;
	h = (int)(n / 100) % 10;
	i = (int)(n / 10) % 10;
	j = (int)(fmod(n + 0.001, 10));
	k = (int)(fmod(n + 0.001, 1) * 10);
	l = (int)(fmod(n + 0.001, 0.1) * 100);
	cout << "十亿位 : " << a << endl;
	cout << "亿位   : " << b << endl;
	cout << "千万位 : " << c << endl;
	cout << "百万位 : " << d << endl;
	cout << "十万位 : " << e << endl;
	cout << "万位   : " << f << endl;
	cout << "千位   : " << g << endl;
	cout << "百位   : " << h << endl;
	cout << "十位   : " << i << endl;
	cout << "圆     : " << j << endl;
	cout << "角     : " << k << endl;
	cout << "分     : " << l << endl;
	return 0;
}