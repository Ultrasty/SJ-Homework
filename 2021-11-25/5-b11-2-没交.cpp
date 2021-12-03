/* 1851521 沈天宇 软工 */

/*	
*	备注：这个作业迟交了，实在是不好意思
*	实习有点忙，事情有点做不过来
*	为什么迟交还交呢，因为有强迫症，看着这两题没交，不舒服= =
*	感谢您的理解！
*/

#include <iostream>
#include <string>
#include <cmath>
//可按需增加需要的头文件
using namespace std;

const char chnstr[] = "零壹贰叁肆伍陆柒捌玖"; /* 所有输出大写 "零" ~ "玖" 的地方，只允许从这个数组中取值 */
string result;  /* 除result外，不再允许定义任何形式的全局变量 */

/* --允许添加需要的函数 --*/
void daxie(int num, int flag_of_zero)
{
	if (num == 0 && flag_of_zero) {
		result = result + chnstr[0] + chnstr[1];
	}

	if (num != 0) {
		result = result + chnstr[num * 2] + chnstr[num * 2 + 1];
	}
	
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
    /* --允许添加需要的内容 --*/
    
	//变量定义
	double n;
	bool zero_flag = 0;
	int first_number_flag = 0;
	int wan_flag = 0;
	int a, b, c, d, e, f, g, h, i, j, k, l;

	cout << "请输入[0-100亿)之间的数字:\n";
	cin >> n;

	a = (int)(n / 1000000000) % 10;
	b = (int)(n / 100000000) % 10;
	c = (int)(n / 10000000) % 10;
	d = (int)(n / 1000000) % 10;
	e = (int)(n / 100000) % 10;
	f = (int)(n / 10000) % 10;
	g = (int)(n / 1000) % 10;
	h = (int)(n / 100) % 10;
	i = (int)(n / 10) % 10;
	j = (int)(fmod(n + 0.001, 10));
	k = (int)(fmod(n + 0.001, 1) * 10);
	l = (int)(fmod(n + 0.001, 0.1) * 100);

	/* 按需完成 */
	cout << "大写结果是:" << endl;

	if (a > 0) {
		first_number_flag = 1;
		zero_flag = 0;
		daxie(a, 0);
		result = result + "拾";
	}

	if (b > 0) {
		first_number_flag = 1;
		zero_flag = 0;
		daxie(b, 0);
	}
	if (first_number_flag)
		result = result +"亿";

	if (c > 0) {
		first_number_flag = 1;
		zero_flag = 0;
		wan_flag = 1;
		daxie(c, 0);
		result = result +"仟";
	}
	else
		zero_flag = 1;

	if (d > 0) {
		daxie(0, first_number_flag && zero_flag);
		first_number_flag = 1;
		zero_flag = 0;
		wan_flag = 1;
		daxie(d, 0);
		result = result +"佰";
	}
	else
		zero_flag = 1;

	if (e > 0) {
		daxie(0, first_number_flag && zero_flag);
		first_number_flag = 1;
		zero_flag = 0;
		wan_flag = 1;
		daxie(e, 0);
		result = result +"拾";
	}
	else
		zero_flag = 1;

	if (f > 0) {
		daxie(0, first_number_flag && zero_flag);
		first_number_flag = 1;
		zero_flag = 0;
		wan_flag = 1;
		daxie(f, 0);
	}

	if (wan_flag)
		result = result +"万";

	zero_flag = 0;


	if (g > 0) {
		first_number_flag = 1;
		zero_flag = 0;
		daxie(g, 0);
		result = result +"仟";
	}
	else
		zero_flag = 1;

	if (h > 0) {
		daxie(0, first_number_flag && zero_flag);
		first_number_flag = 1;
		zero_flag = 0;
		daxie(h, 0);
		result = result +"佰";
	}
	else
		zero_flag = 1;

	if (i > 0) {
		daxie(0, first_number_flag && zero_flag);
		first_number_flag = 1;
		zero_flag = 0;
		daxie(i, 0);
		result = result +"拾";
	}
	else
		zero_flag = 1;

	if (j > 0) {
		daxie(0, first_number_flag && zero_flag);
		first_number_flag = 1;
		zero_flag = 0;
		daxie(j, 0);
	}

	zero_flag = 0;

	if (first_number_flag)
		result = result +"圆";
	if (!first_number_flag && k == 0 && l == 0) {
		daxie(0, 1);
		result = result +"圆整";
	}

	if (k > 0) {
		daxie(k, 0);
		result = result +"角";
	}
	else
		zero_flag = 1;

	if (l > 0) {
		daxie(0, first_number_flag && zero_flag);
		daxie(l, 0);
		result = result +"分";
	}
	else
		result = result +"整";

    cout << result << endl;  /* 转换得到的大写结果，只允许用本语句输出，之前不允许任何形式的部分输出 */
    return 0;
}