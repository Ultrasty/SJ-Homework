/* 1851521 软工 沈天宇 */
#include <iomanip>
#include <iostream>
#define pi 3.14159
using namespace std;
int main()
{
    cout << "请输入半径和高度" << endl;
	double r, h;
	cin >> r;
	cin >> h;
	cout << setiosflags(ios::fixed) << setprecision(2);
	cout << "圆周长     : "  << pi * 2 * r << endl;
	cout << "圆面积     : "  << pi * r * r << endl;
	cout << "圆球表面积 : "  << pi * 4 * r * r << endl;
	cout << "圆球体积   : "  << pi * r * r * r * 4 / 3 << endl;
	cout << "圆柱体积   : "  << pi * r * r * h << endl;
    return 0;
}
