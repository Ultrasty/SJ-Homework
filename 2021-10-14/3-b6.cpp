/* 1851521 软工 沈天宇 */
#include <cmath>
#include <iostream>
using namespace std;
int main()
{
	cout << "请输入[0-100亿)之间的数字:\n";
	double n;
	cin >> n;
	int a, b, c, d, e, f, g, h, i, j, k, l;
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
	//cout << "十亿位 : " << a << endl;
	//cout << "亿位   : " << b << endl;
	//cout << "千万位 : " << c << endl;
	//cout << "百万位 : " << d << endl;
	//cout << "十万位 : " << e << endl;
	//cout << "万位   : " << f << endl;
	//cout << "千位   : " << g << endl;
	//cout << "百位   : " << h << endl;
	//cout << "十位   : " << i << endl;
	//cout << "圆     : " << j << endl;
	//cout << "角     : " << k << endl;
	//cout << "分     : " << l << endl;

	cout << "大写结果是:" << endl;

	if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0 && g == 0 && h == 0 && i == 0 && j == 0 && k == 0 && l == 0) {
		cout << "零圆整" << endl;
		return 0;
	}

	bool zero_flag = 0;

	//十亿
	if (a > 0) {
		if (a == 1) {
			cout << "壹";
		}
		if (a == 2) {
			cout << "贰";
		}
		if (a == 3) {
			cout << "叁";
		}
		if (a == 4) {
			cout << "肆";
		}
		if (a == 5) {
			cout << "伍";
		}
		if (a == 6) {
			cout << "陆";
		}
		if (a == 7) {
			cout << "柒";
		}
		if (a == 8) {
			cout << "捌";
		}
		if (a == 9) {
			cout << "玖";
		}
		cout << "拾";
	}


	//亿
	if (b == 1) {
		cout << "壹";
	}
	if (b == 2) {
		cout << "贰";
	}
	if (b == 3) {
		cout << "叁";
	}
	if (b == 4) {
		cout << "肆";
	}
	if (b == 5) {
		cout << "伍";
	}
	if (b == 6) {
		cout << "陆";
	}
	if (b == 7) {
		cout << "柒";
	}
	if (b == 8) {
		cout << "捌";
	}
	if (b == 9) {
		cout << "玖";
	}

	if (a > 0 || b > 0) {
		cout << "亿";
		if (c == 0) {
			zero_flag = 1;
		}
	}

	
	//千万
	if (c > 0) {
		if (c == 1) {
			cout << "壹";
		}
		if (c == 2) {
			cout << "贰";
		}
		if (c == 3) {
			cout << "叁";
		}
		if (c == 4) {
			cout << "肆";
		}
		if (c == 5) {
			cout << "伍";
		}
		if (c == 6) {
			cout << "陆";
		}
		if (c == 7) {
			cout << "柒";
		}
		if (c == 8) {
			cout << "捌";
		}
		if (c == 9) {
			cout << "玖";
		}
		cout << "仟";
	}

	//百万
	if (d == 0) {
		if (a > 0 || b > 0 || c > 0) {
			zero_flag = 1;
		}
	}

	if (d > 0) {

		if (zero_flag == 1) {
			cout << "零";
			zero_flag = 0;
		}

		if (d == 1) {
			cout << "壹";
		}
		if (d == 2) {
			cout << "贰";
		}
		if (d == 3) {
			cout << "叁";
		}
		if (d == 4) {
			cout << "肆";
		}
		if (d == 5) {
			cout << "伍";
		}
		if (d == 6) {
			cout << "陆";
		}
		if (d == 7) {
			cout << "柒";
		}
		if (d == 8) {
			cout << "捌";
		}
		if (d == 9) {
			cout << "玖";
		}
		cout << "佰";
	}


	//十万
	if (e == 0) {
		if (a > 0 || b > 0 || c > 0 || d > 0) {
			zero_flag = 1;
		}
	}

	if (e > 0) {

		if (zero_flag == 1) {
			cout << "零";
			zero_flag = 0;
		}

		if (e == 1) {
			cout << "壹";
		}
		if (e == 2) {
			cout << "贰";
		}
		if (e == 3) {
			cout << "叁";
		}
		if (e == 4) {
			cout << "肆";
		}
		if (e == 5) {
			cout << "伍";
		}
		if (e == 6) {
			cout << "陆";
		}
		if (e == 7) {
			cout << "柒";
		}
		if (e == 8) {
			cout << "捌";
		}
		if (e == 9) {
			cout << "玖";
		}
		cout << "拾";
	}

	//万
	if (f == 0) {
		if (a > 0 || b > 0 || c > 0 || d > 0 || e > 0) {
			zero_flag = 1;
		}
	}

	if (f > 0) {

		if (zero_flag == 1) {
			cout << "零";
			zero_flag = 0;
		}

		if (f == 1) {
			cout << "壹";
		}
		if (f == 2) {
			cout << "贰";
		}
		if (f == 3) {
			cout << "叁";
		}
		if (f == 4) {
			cout << "肆";
		}
		if (f == 5) {
			cout << "伍";
		}
		if (f == 6) {
			cout << "陆";
		}
		if (f == 7) {
			cout << "柒";
		}
		if (f == 8) {
			cout << "捌";
		}
		if (f == 9) {
			cout << "玖";
		}
	}

	if (c > 0 || d > 0 || e > 0 || f > 0) {
		cout << "万";
	}
	
	zero_flag = 0;
	

	//千
	if (g == 0) {
		if (a > 0 || b > 0 || c > 0 || d > 0 || e > 0 || f > 0) {
			zero_flag = 1;
		}
	}

	if (g > 0) {

		if (zero_flag == 1) {
			cout << "零";
			zero_flag = 0;
		}

		if (g == 1) {
			cout << "壹";
		}
		if (g == 2) {
			cout << "贰";
		}
		if (g == 3) {
			cout << "叁";
		}
		if (g == 4) {
			cout << "肆";
		}
		if (g == 5) {
			cout << "伍";
		}
		if (g == 6) {
			cout << "陆";
		}
		if (g == 7) {
			cout << "柒";
		}
		if (g == 8) {
			cout << "捌";
		}
		if (g == 9) {
			cout << "玖";
		}
		cout << "仟";
	}


	//百
	if (h == 0) {
		if (a > 0 || b > 0 || c > 0 || d > 0 || e > 0 || f > 0 || g > 0) {
			zero_flag = 1;
		}
	}

	if (h > 0) {

		if (zero_flag == 1) {
			cout << "零";
			zero_flag = 0;
		}

		if (h == 1) {
			cout << "壹";
		}
		if (h == 2) {
			cout << "贰";
		}
		if (h == 3) {
			cout << "叁";
		}
		if (h == 4) {
			cout << "肆";
		}
		if (h == 5) {
			cout << "伍";
		}
		if (h == 6) {
			cout << "陆";
		}
		if (h == 7) {
			cout << "柒";
		}
		if (h == 8) {
			cout << "捌";
		}
		if (h == 9) {
			cout << "玖";
		}
		cout << "佰";
	}

	//十
	if (i == 0) {
		if (a > 0 || b > 0 || c > 0 || d > 0 || e > 0 || f > 0 || g > 0 || h > 0) {
			zero_flag = 1;
		}
	}

	if (i > 0) {

		if (zero_flag == 1) {
			cout << "零";
			zero_flag = 0;
		}

		if (i == 1) {
			cout << "壹";
		}
		if (i == 2) {
			cout << "贰";
		}
		if (i == 3) {
			cout << "叁";
		}
		if (i == 4) {
			cout << "肆";
		}
		if (i == 5) {
			cout << "伍";
		}
		if (i == 6) {
			cout << "陆";
		}
		if (i == 7) {
			cout << "柒";
		}
		if (i == 8) {
			cout << "捌";
		}
		if (i == 9) {
			cout << "玖";
		}
		cout << "拾";
	}

	//个
	if (j == 0) {
		if (a > 0 || b > 0 || c > 0 || d > 0 || e > 0 || f > 0 || g > 0 || h > 0 || i > 0) {
			zero_flag = 1;
		}
	}

	if (j > 0) {

		if (zero_flag == 1) {
			cout << "零";
			zero_flag = 0;
		}

		if (j == 1) {
			cout << "壹";
		}
		if (j == 2) {
			cout << "贰";
		}
		if (j == 3) {
			cout << "叁";
		}
		if (j == 4) {
			cout << "肆";
		}
		if (j == 5) {
			cout << "伍";
		}
		if (j == 6) {
			cout << "陆";
		}
		if (j == 7) {
			cout << "柒";
		}
		if (j == 8) {
			cout << "捌";
		}
		if (j == 9) {
			cout << "玖";
		}
	}

	if ((a > 0 || b > 0 || c > 0 || d > 0 || e > 0 || f > 0 || g > 0 || h > 0 || i > 0 || j > 0) && k == 0 && l == 0) {
		cout << "圆整" << endl;
	}
	else {
		if (a > 0 || b > 0 || c > 0 || d > 0 || e > 0 || f > 0 || g > 0 || h > 0 || i > 0 || j > 0) {
			cout << "圆";
		}
		
		if (k == 0) {
			if (a > 0 || b > 0 || c > 0 || d > 0 || e > 0 || f > 0 || g > 0 || h > 0 || i > 0 || j > 0) {
				cout << "零";
			}
			
			if (l == 1) {
				cout << "壹";
			}
			if (l == 2) {
				cout << "贰";
			}
			if (l == 3) {
				cout << "叁";
			}
			if (l == 4) {
				cout << "肆";
			}
			if (l == 5) {
				cout << "伍";
			}
			if (l == 6) {
				cout << "陆";
			}
			if (l == 7) {
				cout << "柒";
			}
			if (l == 8) {
				cout << "捌";
			}
			if (l == 9) {
				cout << "玖";
			}
			cout << "分" << endl;
		}
		if (k > 0) {
			if (k == 1) {
				cout << "壹";
			}
			if (k == 2) {
				cout << "贰";
			}
			if (k == 3) {
				cout << "叁";
			}
			if (k == 4) {
				cout << "肆";
			}
			if (k == 5) {
				cout << "伍";
			}
			if (k == 6) {
				cout << "陆";
			}
			if (k == 7) {
				cout << "柒";
			}
			if (k == 8) {
				cout << "捌";
			}
			if (k == 9) {
				cout << "玖";
			}
			cout << "角";
			if (l == 0) {
				cout << "整" << endl;
			}
			else {
				if (l == 1) {
					cout << "壹";
				}
				if (l == 2) {
					cout << "贰";
				}
				if (l == 3) {
					cout << "叁";
				}
				if (l == 4) {
					cout << "肆";
				}
				if (l == 5) {
					cout << "伍";
				}
				if (l == 6) {
					cout << "陆";
				}
				if (l == 7) {
					cout << "柒";
				}
				if (l == 8) {
					cout << "捌";
				}
				if (l == 9) {
					cout << "玖";
				}
				cout << "分" << endl;
			}
		}
	}

	return 0;
}
