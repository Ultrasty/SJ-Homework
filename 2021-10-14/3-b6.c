/* 1851521 �� ������ */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	printf("������[0-100��)֮�������:\n");
	double n;
	scanf("%lf", &n);

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
	//printf("ʮ��λ : " << a << endl;
	//printf("��λ   : " << b << endl;
	//printf("ǧ��λ : " << c << endl;
	//printf("����λ : " << d << endl;
	//printf("ʮ��λ : " << e << endl;
	//printf("��λ   : " << f << endl;
	//printf("ǧλ   : " << g << endl;
	//printf("��λ   : " << h << endl;
	//printf("ʮλ   : " << i << endl;
	//printf("Բ     : " << j << endl;
	//printf("��     : " << k << endl;
	//printf("��     : " << l << endl;

	printf("��д�����:\n");

	if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0 && g == 0 && h == 0 && i == 0 && j == 0 && k == 0 && l == 0) {
		printf("��Բ��\n");
		return 0;
	}

	int zero_flag = 0;

	//ʮ��
	if (a > 0) {
		if (a == 1) {
			printf("Ҽ");
		}
		if (a == 2) {
			printf("��");
		}
		if (a == 3) {
			printf("��");
		}
		if (a == 4) {
			printf("��");
		}
		if (a == 5) {
			printf("��");
		}
		if (a == 6) {
			printf("½");
		}
		if (a == 7) {
			printf("��");
		}
		if (a == 8) {
			printf("��");
		}
		if (a == 9) {
			printf("��");
		}
		printf("ʰ");
	}


	//��
	if (b == 1) {
		printf("Ҽ");
	}
	if (b == 2) {
		printf("��");
	}
	if (b == 3) {
		printf("��");
	}
	if (b == 4) {
		printf("��");
	}
	if (b == 5) {
		printf("��");
	}
	if (b == 6) {
		printf("½");
	}
	if (b == 7) {
		printf("��");
	}
	if (b == 8) {
		printf("��");
	}
	if (b == 9) {
		printf("��");
	}

	if (a > 0 || b > 0) {
		printf("��");
		if (c == 0) {
			zero_flag = 1;
		}
	}


	//ǧ��
	if (c > 0) {
		if (c == 1) {
			printf("Ҽ");
		}
		if (c == 2) {
			printf("��");
		}
		if (c == 3) {
			printf("��");
		}
		if (c == 4) {
			printf("��");
		}
		if (c == 5) {
			printf("��");
		}
		if (c == 6) {
			printf("½");
		}
		if (c == 7) {
			printf("��");
		}
		if (c == 8) {
			printf("��");
		}
		if (c == 9) {
			printf("��");
		}
		printf("Ǫ");
	}

	//����
	if (d == 0) {
		if (a > 0 || b > 0 || c > 0) {
			zero_flag = 1;
		}
	}

	if (d > 0) {

		if (zero_flag == 1) {
			printf("��");
			zero_flag = 0;
		}

		if (d == 1) {
			printf("Ҽ");
		}
		if (d == 2) {
			printf("��");
		}
		if (d == 3) {
			printf("��");
		}
		if (d == 4) {
			printf("��");
		}
		if (d == 5) {
			printf("��");
		}
		if (d == 6) {
			printf("½");
		}
		if (d == 7) {
			printf("��");
		}
		if (d == 8) {
			printf("��");
		}
		if (d == 9) {
			printf("��");
		}
		printf("��");
	}


	//ʮ��
	if (e == 0) {
		if (a > 0 || b > 0 || c > 0 || d > 0) {
			zero_flag = 1;
		}
	}

	if (e > 0) {

		if (zero_flag == 1) {
			printf("��");
			zero_flag = 0;
		}

		if (e == 1) {
			printf("Ҽ");
		}
		if (e == 2) {
			printf("��");
		}
		if (e == 3) {
			printf("��");
		}
		if (e == 4) {
			printf("��");
		}
		if (e == 5) {
			printf("��");
		}
		if (e == 6) {
			printf("½");
		}
		if (e == 7) {
			printf("��");
		}
		if (e == 8) {
			printf("��");
		}
		if (e == 9) {
			printf("��");
		}
		printf("ʰ");
	}

	//��
	if (f == 0) {
		if (a > 0 || b > 0 || c > 0 || d > 0 || e > 0) {
			zero_flag = 1;
		}
	}

	if (f > 0) {

		if (zero_flag == 1) {
			printf("��");
			zero_flag = 0;
		}

		if (f == 1) {
			printf("Ҽ");
		}
		if (f == 2) {
			printf("��");
		}
		if (f == 3) {
			printf("��");
		}
		if (f == 4) {
			printf("��");
		}
		if (f == 5) {
			printf("��");
		}
		if (f == 6) {
			printf("½");
		}
		if (f == 7) {
			printf("��");
		}
		if (f == 8) {
			printf("��");
		}
		if (f == 9) {
			printf("��");
		}
	}

	if (c > 0 || d > 0 || e > 0 || f > 0) {
		printf("��");
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
			printf("��");
			zero_flag = 0;
		}

		if (g == 1) {
			printf("Ҽ");
		}
		if (g == 2) {
			printf("��");
		}
		if (g == 3) {
			printf("��");
		}
		if (g == 4) {
			printf("��");
		}
		if (g == 5) {
			printf("��");
		}
		if (g == 6) {
			printf("½");
		}
		if (g == 7) {
			printf("��");
		}
		if (g == 8) {
			printf("��");
		}
		if (g == 9) {
			printf("��");
		}
		printf("Ǫ");
	}


	//��
	if (h == 0) {
		if (a > 0 || b > 0 || c > 0 || d > 0 || e > 0 || f > 0 || g > 0) {
			zero_flag = 1;
		}
	}

	if (h > 0) {

		if (zero_flag == 1) {
			printf("��");
			zero_flag = 0;
		}

		if (h == 1) {
			printf("Ҽ");
		}
		if (h == 2) {
			printf("��");
		}
		if (h == 3) {
			printf("��");
		}
		if (h == 4) {
			printf("��");
		}
		if (h == 5) {
			printf("��");
		}
		if (h == 6) {
			printf("½");
		}
		if (h == 7) {
			printf("��");
		}
		if (h == 8) {
			printf("��");
		}
		if (h == 9) {
			printf("��");
		}
		printf("��");
	}

	//ʮ
	if (i == 0) {
		if (a > 0 || b > 0 || c > 0 || d > 0 || e > 0 || f > 0 || g > 0 || h > 0) {
			zero_flag = 1;
		}
	}

	if (i > 0) {

		if (zero_flag == 1) {
			printf("��");
			zero_flag = 0;
		}

		if (i == 1) {
			printf("Ҽ");
		}
		if (i == 2) {
			printf("��");
		}
		if (i == 3) {
			printf("��");
		}
		if (i == 4) {
			printf("��");
		}
		if (i == 5) {
			printf("��");
		}
		if (i == 6) {
			printf("½");
		}
		if (i == 7) {
			printf("��");
		}
		if (i == 8) {
			printf("��");
		}
		if (i == 9) {
			printf("��");
		}
		printf("ʰ");
	}

	//��
	if (j == 0) {
		if (a > 0 || b > 0 || c > 0 || d > 0 || e > 0 || f > 0 || g > 0 || h > 0 || i > 0) {
			zero_flag = 1;
		}
	}

	if (j > 0) {

		if (zero_flag == 1) {
			printf("��");
			zero_flag = 0;
		}

		if (j == 1) {
			printf("Ҽ");
		}
		if (j == 2) {
			printf("��");
		}
		if (j == 3) {
			printf("��");
		}
		if (j == 4) {
			printf("��");
		}
		if (j == 5) {
			printf("��");
		}
		if (j == 6) {
			printf("½");
		}
		if (j == 7) {
			printf("��");
		}
		if (j == 8) {
			printf("��");
		}
		if (j == 9) {
			printf("��");
		}
	}

	if ((a > 0 || b > 0 || c > 0 || d > 0 || e > 0 || f > 0 || g > 0 || h > 0 || i > 0 || j > 0) && k == 0 && l == 0) {
		printf("Բ��\n");
	}
	else {
		if (a > 0 || b > 0 || c > 0 || d > 0 || e > 0 || f > 0 || g > 0 || h > 0 || i > 0 || j > 0) {
			printf("Բ");
		}

		if (k == 0) {
			if (a > 0 || b > 0 || c > 0 || d > 0 || e > 0 || f > 0 || g > 0 || h > 0 || i > 0 || j > 0) {
				printf("��");
			}

			if (l == 1) {
				printf("Ҽ");
			}
			if (l == 2) {
				printf("��");
			}
			if (l == 3) {
				printf("��");
			}
			if (l == 4) {
				printf("��");
			}
			if (l == 5) {
				printf("��");
			}
			if (l == 6) {
				printf("½");
			}
			if (l == 7) {
				printf("��");
			}
			if (l == 8) {
				printf("��");
			}
			if (l == 9) {
				printf("��");
			}
			printf("��\n");
		}
		if (k > 0) {
			if (k == 1) {
				printf("Ҽ");
			}
			if (k == 2) {
				printf("��");
			}
			if (k == 3) {
				printf("��");
			}
			if (k == 4) {
				printf("��");
			}
			if (k == 5) {
				printf("��");
			}
			if (k == 6) {
				printf("½");
			}
			if (k == 7) {
				printf("��");
			}
			if (k == 8) {
				printf("��");
			}
			if (k == 9) {
				printf("��");
			}
			printf("��");
			if (l == 0) {
				printf("��\n");
			}
			else {
				if (l == 1) {
					printf("Ҽ");
				}
				if (l == 2) {
					printf("��");
				}
				if (l == 3) {
					printf("��");
				}
				if (l == 4) {
					printf("��");
				}
				if (l == 5) {
					printf("��");
				}
				if (l == 6) {
					printf("½");
				}
				if (l == 7) {
					printf("��");
				}
				if (l == 8) {
					printf("��");
				}
				if (l == 9) {
					printf("��");
				}
				printf("��\n");
			}
		}
	}

	return 0;
}