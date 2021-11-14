/* 1851521 沈天宇 软工 */
#include<iostream>
#include<cmath> 
using namespace std;
void s4(double a, double b, double c, double delta)
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
