/* 1851521 软工 沈天宇 */
#define pi 3.14159
#include <iostream>
#include <cmath>
#include<iomanip>
using namespace std;
int main()
{
	int a, b, angle;
	cout<<"请输入三角形的两边及其夹角(角度)\n";
	cin>>a>>b>>angle;
	float ans = (float)(sin(pi * angle / 180) * a * b / 2);
	cout << setiosflags(ios::fixed) << setprecision(3);
	cout<<"三角形面积为 : "<<ans<<endl;
	return 0;
}