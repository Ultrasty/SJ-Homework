/* 1851521 软工 沈天宇 */
#include<iostream>
#include<cmath>
using namespace std;

int main() {

	cout << "请输入x的值" << endl;
	double x;
	cin >> x;
	if (x < 15) {
		cout << "y=" << 2 * x - 1 << endl;
	}
	if (x < 45 && x >= 15) {
		cout << "y=" << x * x - sin(x/180*3.14159) << endl;
	}
	if (x >= 45) {
		cout << "y=" << 3 * x - sqrt(x) << endl;
	}

	return 0;
}