/* 1851521 �� ������ */
#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
	cout << "������һ��[1..30000]�������" << endl;
	int n, a, b, c, d, e;
	cin >> n;
	a = n % 10;
	b = n / 10 % 10;
	c = n / 100 % 10;
	d = n / 1000 % 10;
	e = n / 10000 % 10;
	cout << "��λ : " << e << endl;
	cout << "ǧλ : " << d << endl;
	cout << "��λ : " << c << endl;
	cout << "ʮλ : " << b << endl;
	cout << "��λ : " << a << endl;
	return 0;
}
