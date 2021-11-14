/* 1851521 沈天宇 软工 */
#include<iostream>
#include"4-b16.h"
using namespace std;

int main()
{
	double a, b, c;
	double delta;
	cout << "请输入一元二次方程的三个系数a,b,c:" << endl;
	cin >> a >> b >> c;
	delta = b * b - 4 * a * c;
	if (abs(a) < 1e-6) {
		s1(a, b, c, delta);
	}
	else if (abs(delta) < 1e-6) {
		s2(a, b, c, delta);
	}
	else if (delta > 0) {
		s3(a, b, c, delta);
	}
	else if (delta < 0) {
		s4(a, b, c, delta);
	}
	return 0;
}