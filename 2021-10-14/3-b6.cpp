/* 1851521 �� ������ */
#include <cmath>
#include <iostream>
using namespace std;
int main()
{
	cout << "������[0-100��)֮�������:\n";
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
	//cout << "ʮ��λ : " << a << endl;
	//cout << "��λ   : " << b << endl;
	//cout << "ǧ��λ : " << c << endl;
	//cout << "����λ : " << d << endl;
	//cout << "ʮ��λ : " << e << endl;
	//cout << "��λ   : " << f << endl;
	//cout << "ǧλ   : " << g << endl;
	//cout << "��λ   : " << h << endl;
	//cout << "ʮλ   : " << i << endl;
	//cout << "Բ     : " << j << endl;
	//cout << "��     : " << k << endl;
	//cout << "��     : " << l << endl;

	cout << "��д�����:" << endl;

	if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0 && g == 0 && h == 0 && i == 0 && j == 0 && k == 0 && l == 0) {
		cout << "��Բ��" << endl;
		return 0;
	}

	bool zero_flag = 0;

	//ʮ��
	if (a > 0) {
		if (a == 1) {
			cout << "Ҽ";
		}
		if (a == 2) {
			cout << "��";
		}
		if (a == 3) {
			cout << "��";
		}
		if (a == 4) {
			cout << "��";
		}
		if (a == 5) {
			cout << "��";
		}
		if (a == 6) {
			cout << "½";
		}
		if (a == 7) {
			cout << "��";
		}
		if (a == 8) {
			cout << "��";
		}
		if (a == 9) {
			cout << "��";
		}
		cout << "ʰ";
	}


	//��
	if (b == 1) {
		cout << "Ҽ";
	}
	if (b == 2) {
		cout << "��";
	}
	if (b == 3) {
		cout << "��";
	}
	if (b == 4) {
		cout << "��";
	}
	if (b == 5) {
		cout << "��";
	}
	if (b == 6) {
		cout << "½";
	}
	if (b == 7) {
		cout << "��";
	}
	if (b == 8) {
		cout << "��";
	}
	if (b == 9) {
		cout << "��";
	}

	if (a > 0 || b > 0) {
		cout << "��";
		if (c == 0) {
			zero_flag = 1;
		}
	}

	
	//ǧ��
	if (c > 0) {
		if (c == 1) {
			cout << "Ҽ";
		}
		if (c == 2) {
			cout << "��";
		}
		if (c == 3) {
			cout << "��";
		}
		if (c == 4) {
			cout << "��";
		}
		if (c == 5) {
			cout << "��";
		}
		if (c == 6) {
			cout << "½";
		}
		if (c == 7) {
			cout << "��";
		}
		if (c == 8) {
			cout << "��";
		}
		if (c == 9) {
			cout << "��";
		}
		cout << "Ǫ";
	}

	//����
	if (d == 0) {
		if (a > 0 || b > 0 || c > 0) {
			zero_flag = 1;
		}
	}

	if (d > 0) {

		if (zero_flag == 1) {
			cout << "��";
			zero_flag = 0;
		}

		if (d == 1) {
			cout << "Ҽ";
		}
		if (d == 2) {
			cout << "��";
		}
		if (d == 3) {
			cout << "��";
		}
		if (d == 4) {
			cout << "��";
		}
		if (d == 5) {
			cout << "��";
		}
		if (d == 6) {
			cout << "½";
		}
		if (d == 7) {
			cout << "��";
		}
		if (d == 8) {
			cout << "��";
		}
		if (d == 9) {
			cout << "��";
		}
		cout << "��";
	}


	//ʮ��
	if (e == 0) {
		if (a > 0 || b > 0 || c > 0 || d > 0) {
			zero_flag = 1;
		}
	}

	if (e > 0) {

		if (zero_flag == 1) {
			cout << "��";
			zero_flag = 0;
		}

		if (e == 1) {
			cout << "Ҽ";
		}
		if (e == 2) {
			cout << "��";
		}
		if (e == 3) {
			cout << "��";
		}
		if (e == 4) {
			cout << "��";
		}
		if (e == 5) {
			cout << "��";
		}
		if (e == 6) {
			cout << "½";
		}
		if (e == 7) {
			cout << "��";
		}
		if (e == 8) {
			cout << "��";
		}
		if (e == 9) {
			cout << "��";
		}
		cout << "ʰ";
	}

	//��
	if (f == 0) {
		if (a > 0 || b > 0 || c > 0 || d > 0 || e > 0) {
			zero_flag = 1;
		}
	}

	if (f > 0) {

		if (zero_flag == 1) {
			cout << "��";
			zero_flag = 0;
		}

		if (f == 1) {
			cout << "Ҽ";
		}
		if (f == 2) {
			cout << "��";
		}
		if (f == 3) {
			cout << "��";
		}
		if (f == 4) {
			cout << "��";
		}
		if (f == 5) {
			cout << "��";
		}
		if (f == 6) {
			cout << "½";
		}
		if (f == 7) {
			cout << "��";
		}
		if (f == 8) {
			cout << "��";
		}
		if (f == 9) {
			cout << "��";
		}
	}

	if (c > 0 || d > 0 || e > 0 || f > 0) {
		cout << "��";
	}
	
	zero_flag = 0;
	

	//ǧ
	if (g == 0) {
		if (a > 0 || b > 0 || c > 0 || d > 0 || e > 0 || f > 0) {
			zero_flag = 1;
		}
	}

	if (g > 0) {

		if (zero_flag == 1) {
			cout << "��";
			zero_flag = 0;
		}

		if (g == 1) {
			cout << "Ҽ";
		}
		if (g == 2) {
			cout << "��";
		}
		if (g == 3) {
			cout << "��";
		}
		if (g == 4) {
			cout << "��";
		}
		if (g == 5) {
			cout << "��";
		}
		if (g == 6) {
			cout << "½";
		}
		if (g == 7) {
			cout << "��";
		}
		if (g == 8) {
			cout << "��";
		}
		if (g == 9) {
			cout << "��";
		}
		cout << "Ǫ";
	}


	//��
	if (h == 0) {
		if (a > 0 || b > 0 || c > 0 || d > 0 || e > 0 || f > 0 || g > 0) {
			zero_flag = 1;
		}
	}

	if (h > 0) {

		if (zero_flag == 1) {
			cout << "��";
			zero_flag = 0;
		}

		if (h == 1) {
			cout << "Ҽ";
		}
		if (h == 2) {
			cout << "��";
		}
		if (h == 3) {
			cout << "��";
		}
		if (h == 4) {
			cout << "��";
		}
		if (h == 5) {
			cout << "��";
		}
		if (h == 6) {
			cout << "½";
		}
		if (h == 7) {
			cout << "��";
		}
		if (h == 8) {
			cout << "��";
		}
		if (h == 9) {
			cout << "��";
		}
		cout << "��";
	}

	//ʮ
	if (i == 0) {
		if (a > 0 || b > 0 || c > 0 || d > 0 || e > 0 || f > 0 || g > 0 || h > 0) {
			zero_flag = 1;
		}
	}

	if (i > 0) {

		if (zero_flag == 1) {
			cout << "��";
			zero_flag = 0;
		}

		if (i == 1) {
			cout << "Ҽ";
		}
		if (i == 2) {
			cout << "��";
		}
		if (i == 3) {
			cout << "��";
		}
		if (i == 4) {
			cout << "��";
		}
		if (i == 5) {
			cout << "��";
		}
		if (i == 6) {
			cout << "½";
		}
		if (i == 7) {
			cout << "��";
		}
		if (i == 8) {
			cout << "��";
		}
		if (i == 9) {
			cout << "��";
		}
		cout << "ʰ";
	}

	//��
	if (j == 0) {
		if (a > 0 || b > 0 || c > 0 || d > 0 || e > 0 || f > 0 || g > 0 || h > 0 || i > 0) {
			zero_flag = 1;
		}
	}

	if (j > 0) {

		if (zero_flag == 1) {
			cout << "��";
			zero_flag = 0;
		}

		if (j == 1) {
			cout << "Ҽ";
		}
		if (j == 2) {
			cout << "��";
		}
		if (j == 3) {
			cout << "��";
		}
		if (j == 4) {
			cout << "��";
		}
		if (j == 5) {
			cout << "��";
		}
		if (j == 6) {
			cout << "½";
		}
		if (j == 7) {
			cout << "��";
		}
		if (j == 8) {
			cout << "��";
		}
		if (j == 9) {
			cout << "��";
		}
	}

	if ((a > 0 || b > 0 || c > 0 || d > 0 || e > 0 || f > 0 || g > 0 || h > 0 || i > 0 || j > 0) && k == 0 && l == 0) {
		cout << "Բ��" << endl;
	}
	else {
		if (a > 0 || b > 0 || c > 0 || d > 0 || e > 0 || f > 0 || g > 0 || h > 0 || i > 0 || j > 0) {
			cout << "Բ";
		}
		
		if (k == 0) {
			if (a > 0 || b > 0 || c > 0 || d > 0 || e > 0 || f > 0 || g > 0 || h > 0 || i > 0 || j > 0) {
				cout << "��";
			}
			
			if (l == 1) {
				cout << "Ҽ";
			}
			if (l == 2) {
				cout << "��";
			}
			if (l == 3) {
				cout << "��";
			}
			if (l == 4) {
				cout << "��";
			}
			if (l == 5) {
				cout << "��";
			}
			if (l == 6) {
				cout << "½";
			}
			if (l == 7) {
				cout << "��";
			}
			if (l == 8) {
				cout << "��";
			}
			if (l == 9) {
				cout << "��";
			}
			cout << "��" << endl;
		}
		if (k > 0) {
			if (k == 1) {
				cout << "Ҽ";
			}
			if (k == 2) {
				cout << "��";
			}
			if (k == 3) {
				cout << "��";
			}
			if (k == 4) {
				cout << "��";
			}
			if (k == 5) {
				cout << "��";
			}
			if (k == 6) {
				cout << "½";
			}
			if (k == 7) {
				cout << "��";
			}
			if (k == 8) {
				cout << "��";
			}
			if (k == 9) {
				cout << "��";
			}
			cout << "��";
			if (l == 0) {
				cout << "��" << endl;
			}
			else {
				if (l == 1) {
					cout << "Ҽ";
				}
				if (l == 2) {
					cout << "��";
				}
				if (l == 3) {
					cout << "��";
				}
				if (l == 4) {
					cout << "��";
				}
				if (l == 5) {
					cout << "��";
				}
				if (l == 6) {
					cout << "½";
				}
				if (l == 7) {
					cout << "��";
				}
				if (l == 8) {
					cout << "��";
				}
				if (l == 9) {
					cout << "��";
				}
				cout << "��" << endl;
			}
		}
	}

	return 0;
}