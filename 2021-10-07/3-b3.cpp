/* 1851521 �� ������ */
#include <cmath>
#include <iostream>
using namespace std;
int main()
{
	cout << "������[0-100��)֮�������:\n";
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
	cout << "ʮ��λ : " << a << endl;
	cout << "��λ   : " << b << endl;
	cout << "ǧ��λ : " << c << endl;
	cout << "����λ : " << d << endl;
	cout << "ʮ��λ : " << e << endl;
	cout << "��λ   : " << f << endl;
	cout << "ǧλ   : " << g << endl;
	cout << "��λ   : " << h << endl;
	cout << "ʮλ   : " << i << endl;
	cout << "Բ     : " << j << endl;
	cout << "��     : " << k << endl;
	cout << "��     : " << l << endl;
	return 0;
}