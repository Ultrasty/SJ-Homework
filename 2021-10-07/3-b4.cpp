/* 1851521 �� ������ */
#define pi 3.14159
#include <iostream>
#include <cmath>
#include<iomanip>
using namespace std;
int main()
{
	int a, b, angle;
	cout<<"�����������ε����߼���н�(�Ƕ�)\n";
	cin>>a>>b>>angle;
	float ans = (float)(sin(pi * angle / 180) * a * b / 2);
	cout << setiosflags(ios::fixed) << setprecision(3);
	cout<<"���������Ϊ : "<<ans<<endl;
	return 0;
}