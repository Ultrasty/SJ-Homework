/* 1851521 �� ������ */
#include<iostream>
#include<cmath>
using namespace std;

int main() {

	cout << "������x��ֵ" << endl;
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