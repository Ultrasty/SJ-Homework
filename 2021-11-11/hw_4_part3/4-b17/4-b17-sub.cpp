/* 1851521 沈天宇 软工 */
#include<iostream>
#include<cmath> 
using namespace std;

extern double a, b, c, delta;

void s1()
{
	cout << "不是一元二次方程" << endl;
}

void s2()
{
	cout << "有两个相等实根：" << endl;
	cout << "x1=x2=" << -b / (2 * a) << endl;
}

void s3()
{
	cout << "有两个不等实根：" << endl;
	if (a > 0) {
		cout << "x1=" << (-b + sqrt(delta)) / (2 * a) << endl;
		cout << "x2=" << (-b - sqrt(delta)) / (2 * a) << endl;
	}
	else {
		cout << "x1=" << (-b - sqrt(delta)) / (2 * a) << endl;
		cout << "x2=" << (-b + sqrt(delta)) / (2 * a) << endl;
	}
}

void s4()
{
	cout << "有两个虚根：" << endl;
	if (abs(abs(sqrt(-delta) / (2 * a)) - 1) < 1e-6) {
		if (abs(b) < 1e-6) {
			cout << "x1=" << "i" << endl;
			cout << "x2=" << "-i" << endl;
		}
		else {
			cout << "x1=" << -b / (2 * a) << "+i" << endl;
			cout << "x2=" << -b / (2 * a) << "-i" << endl;
		}
	}
	else {
		if (abs(b) < 1e-6) {
			cout << "x1=" << sqrt(-delta) / (2 * a) << "i" << endl;
			cout << "x2=" << -sqrt(-delta) / (2 * a) << "i" << endl;
		}
		else {
			cout << "x1=" << -b / (2 * a) << "+" << sqrt(-delta) / (2 * a) << "i" << endl;
			cout << "x2=" << -b / (2 * a) << "-" << sqrt(-delta) / (2 * a) << "i" << endl;
		}
	}
}
