/* 1851521 ������ �� */
#include<iostream>
#include<cmath> 
using namespace std;
void s3(double a, double b, double c, double delta)
{
	cout << "����������ʵ����" << endl;
	if (a > 0) {
		cout << "x1=" << (-b + sqrt(delta)) / (2 * a) << endl;
		cout << "x2=" << (-b - sqrt(delta)) / (2 * a) << endl;
	}
	else {
		cout << "x1=" << (-b - sqrt(delta)) / (2 * a) << endl;
		cout << "x2=" << (-b + sqrt(delta)) / (2 * a) << endl;
	}
}
