/* 1851521 �� ������ */
#include <iomanip>
#include <iostream>
#define pi 3.14159
using namespace std;
int main()
{
    cout << "������뾶�͸߶�" << endl;
	double r, h;
	cin >> r;
	cin >> h;
	cout << setiosflags(ios::fixed) << setprecision(2);
	cout << "Բ�ܳ�     : "  << pi * 2 * r << endl;
	cout << "Բ���     : "  << pi * r * r << endl;
	cout << "Բ������ : "  << pi * 4 * r * r << endl;
	cout << "Բ�����   : "  << pi * r * r * r * 4 / 3 << endl;
	cout << "Բ�����   : "  << pi * r * r * h << endl;
    return 0;
}
