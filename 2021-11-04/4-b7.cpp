/* 1851521 沈天宇 软工 */
#include <iostream>
using namespace std;

/* ----具体要求----
   1、不允许添加其它头文件
   2、不允许定义全局变量、静态局部变量
   3、不允许添加其它函数
   4、整个程序不允许出现任何形式的循环
   --------------------------------------------------------------------- */

   /***************************************************************************
	 函数名称：
	 功    能：将整数n分解后输出
	 输入参数：
	 返 回 值：
	 说    明：1、函数名、形参、返回类型均不准动
			   2、不允许使用64位整数
   ***************************************************************************/
void convert(int n)
{
	if (n == INT_MIN) {
		cout << "- ";
		convert(-(n / 10));
		cout << char(-(n % 10) + '0') << " ";
	}
	else {
		if (n < 0) {
			n = -n;
			cout << "- ";
		}
		if (n / 10 != 0) {
			convert(n / 10);
			cout << char(n % 10 + '0') << " ";
		}
		if (n / 10 == 0) {
			cout << char(n + '0') << " ";
		}
	}
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准动
***************************************************************************/
int main()
{
	int n;
	cout << "请输入一个整数" << endl;
	cin >> n;

	convert(n);
	cout << endl;

	return 0;
}
