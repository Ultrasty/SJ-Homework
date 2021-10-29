/* 1851521 沈天宇 软工 */
#include <cmath>
#include <iostream>
using namespace std;

/* 可根据需要添加相应的内容 */

/***************************************************************************
  函数名称：
  功    能：输出大写的0~9
  输入参数：
  返 回 值：
  说    明：除本函数外，不允许任何函数中输出“零”-“玖”!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* 不允许对本函数做任何修改 */
	switch (num) {
		case 0:
			if (flag_of_zero)	//此标记什么意思请自行思考
				cout << "零";
			break;
		case 1:
			cout << "壹";
			break;
		case 2:
			cout << "贰";
			break;
		case 3:
			cout << "叁";
			break;
		case 4:
			cout << "肆";
			break;
		case 5:
			cout << "伍";
			break;
		case 6:
			cout << "陆";
			break;
		case 7:
			cout << "柒";
			break;
		case 8:
			cout << "捌";
			break;
		case 9:
			cout << "玖";
			break;
		default:
			cout << "error";
			break;
	}
}

/* 可根据需要自定义其它函数(也可以不定义) */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
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
	/*cout << "十亿位 : " << a << endl;
	cout << "亿位   : " << b << endl;
	cout << "千万位 : " << c << endl;
	cout << "百万位 : " << d << endl;
	cout << "十万位 : " << e << endl;
	cout << "万位   : " << f << endl;
	cout << "千位   : " << g << endl;
	cout << "百位   : " << h << endl;
	cout << "十位   : " << i << endl;
	cout << "圆     : " << j << endl;
	cout << "角     : " << k << endl;
	cout << "分     : " << l << endl;*/
	/* 按需完成 */
	cout << "大写结果是:" << endl;

	if (a > 0){
		first_number_flag = 1;
		zero_flag = 0;
		daxie(a, 0);
		cout << "拾";
	}

	if (b > 0){
		first_number_flag = 1;
		zero_flag = 0;
		daxie(b, 0);
	}
	if (first_number_flag)
		cout << "亿";

	if (c > 0){
		first_number_flag = 1;
		zero_flag = 0;
		wan_flag = 1;
		daxie(c, 0);
		cout << "仟";
	}
	else
		zero_flag = 1;

	if (d > 0){
		daxie(0, first_number_flag && zero_flag);
		first_number_flag = 1;
		zero_flag = 0;
		wan_flag = 1;
		daxie(d, 0);
		cout << "佰";
	}
	else
		zero_flag = 1;

	if (e > 0){
		daxie(0, first_number_flag && zero_flag);
		first_number_flag = 1;
		zero_flag = 0;
		wan_flag = 1;
		daxie(e, 0);
		cout << "拾";
	}
	else
		zero_flag = 1;

	if (f > 0){
		daxie(0, first_number_flag && zero_flag);
		first_number_flag = 1;
		zero_flag = 0;
		wan_flag = 1;
		daxie(f, 0);
	}

	if (wan_flag)
		cout << "万";

	zero_flag = 0;


	if (g > 0){
		first_number_flag = 1;
		zero_flag = 0;
		daxie(g, 0);
		cout << "仟";
	}
	else
		zero_flag = 1;

	if (h > 0){
		daxie(0, first_number_flag && zero_flag);
		first_number_flag = 1;
		zero_flag = 0;
		daxie(h, 0);
		cout << "佰";
	}
	else
		zero_flag = 1;

	if (i > 0){
		daxie(0, first_number_flag && zero_flag);
		first_number_flag = 1;
		zero_flag = 0;
		daxie(i, 0);
		cout << "拾";
	}
	else
		zero_flag = 1;

	if (j > 0){
		daxie(0, first_number_flag && zero_flag);
		first_number_flag = 1;
		zero_flag = 0;
		daxie(j, 0);
	}

	zero_flag = 0;

	if (first_number_flag)
		cout << "圆";
	if (!first_number_flag && k == 0 && l == 0){
		daxie(0, 1);
		cout << "圆整" << endl;
	}

	if (k > 0){
		daxie(k, 0);
		cout << "角";
	}
	else
		zero_flag = 1;

	if (l > 0){
		daxie(0, first_number_flag && zero_flag);
		daxie(l, 0);
		cout << "分" << endl;
	}
	else
		cout << "整" << endl;

	return 0;
}
