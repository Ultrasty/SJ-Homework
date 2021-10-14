/* 1851521 Èí¹¤ ÉòÌìÓî */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	printf("ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊý×Ö:\n");
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
	//printf("Ê®ÒÚÎ» : " << a << endl;
	//printf("ÒÚÎ»   : " << b << endl;
	//printf("Ç§ÍòÎ» : " << c << endl;
	//printf("°ÙÍòÎ» : " << d << endl;
	//printf("Ê®ÍòÎ» : " << e << endl;
	//printf("ÍòÎ»   : " << f << endl;
	//printf("Ç§Î»   : " << g << endl;
	//printf("°ÙÎ»   : " << h << endl;
	//printf("Ê®Î»   : " << i << endl;
	//printf("Ô²     : " << j << endl;
	//printf("½Ç     : " << k << endl;
	//printf("·Ö     : " << l << endl;

	printf("´óÐ´½á¹ûÊÇ:\n");

	if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0 && g == 0 && h == 0 && i == 0 && j == 0 && k == 0 && l == 0) {
		printf("ÁãÔ²Õû\n");
		return 0;
	}

	int zero_flag = 0;

	//Ê®ÒÚ
	if (a > 0) {
		if (a == 1) {
			printf("Ò¼");
		}
		if (a == 2) {
			printf("·¡");
		}
		if (a == 3) {
			printf("Èþ");
		}
		if (a == 4) {
			printf("ËÁ");
		}
		if (a == 5) {
			printf("Îé");
		}
		if (a == 6) {
			printf("Â½");
		}
		if (a == 7) {
			printf("Æâ");
		}
		if (a == 8) {
			printf("°Æ");
		}
		if (a == 9) {
			printf("¾Á");
		}
		printf("Ê°");
	}


	//ÒÚ
	if (b == 1) {
		printf("Ò¼");
	}
	if (b == 2) {
		printf("·¡");
	}
	if (b == 3) {
		printf("Èþ");
	}
	if (b == 4) {
		printf("ËÁ");
	}
	if (b == 5) {
		printf("Îé");
	}
	if (b == 6) {
		printf("Â½");
	}
	if (b == 7) {
		printf("Æâ");
	}
	if (b == 8) {
		printf("°Æ");
	}
	if (b == 9) {
		printf("¾Á");
	}

	if (a > 0 || b > 0) {
		printf("ÒÚ");
		if (c == 0) {
			zero_flag = 1;
		}
	}


	//Ç§Íò
	if (c > 0) {
		if (c == 1) {
			printf("Ò¼");
		}
		if (c == 2) {
			printf("·¡");
		}
		if (c == 3) {
			printf("Èþ");
		}
		if (c == 4) {
			printf("ËÁ");
		}
		if (c == 5) {
			printf("Îé");
		}
		if (c == 6) {
			printf("Â½");
		}
		if (c == 7) {
			printf("Æâ");
		}
		if (c == 8) {
			printf("°Æ");
		}
		if (c == 9) {
			printf("¾Á");
		}
		printf("Çª");
	}

	//°ÙÍò
	if (d == 0) {
		if (a > 0 || b > 0 || c > 0) {
			zero_flag = 1;
		}
	}

	if (d > 0) {

		if (zero_flag == 1) {
			printf("Áã");
			zero_flag = 0;
		}

		if (d == 1) {
			printf("Ò¼");
		}
		if (d == 2) {
			printf("·¡");
		}
		if (d == 3) {
			printf("Èþ");
		}
		if (d == 4) {
			printf("ËÁ");
		}
		if (d == 5) {
			printf("Îé");
		}
		if (d == 6) {
			printf("Â½");
		}
		if (d == 7) {
			printf("Æâ");
		}
		if (d == 8) {
			printf("°Æ");
		}
		if (d == 9) {
			printf("¾Á");
		}
		printf("°Û");
	}


	//Ê®Íò
	if (e == 0) {
		if (a > 0 || b > 0 || c > 0 || d > 0) {
			zero_flag = 1;
		}
	}

	if (e > 0) {

		if (zero_flag == 1) {
			printf("Áã");
			zero_flag = 0;
		}

		if (e == 1) {
			printf("Ò¼");
		}
		if (e == 2) {
			printf("·¡");
		}
		if (e == 3) {
			printf("Èþ");
		}
		if (e == 4) {
			printf("ËÁ");
		}
		if (e == 5) {
			printf("Îé");
		}
		if (e == 6) {
			printf("Â½");
		}
		if (e == 7) {
			printf("Æâ");
		}
		if (e == 8) {
			printf("°Æ");
		}
		if (e == 9) {
			printf("¾Á");
		}
		printf("Ê°");
	}

	//Íò
	if (f == 0) {
		if (a > 0 || b > 0 || c > 0 || d > 0 || e > 0) {
			zero_flag = 1;
		}
	}

	if (f > 0) {

		if (zero_flag == 1) {
			printf("Áã");
			zero_flag = 0;
		}

		if (f == 1) {
			printf("Ò¼");
		}
		if (f == 2) {
			printf("·¡");
		}
		if (f == 3) {
			printf("Èþ");
		}
		if (f == 4) {
			printf("ËÁ");
		}
		if (f == 5) {
			printf("Îé");
		}
		if (f == 6) {
			printf("Â½");
		}
		if (f == 7) {
			printf("Æâ");
		}
		if (f == 8) {
			printf("°Æ");
		}
		if (f == 9) {
			printf("¾Á");
		}
	}

	if (c > 0 || d > 0 || e > 0 || f > 0) {
		printf("Íò");
	}

	zero_flag = 0;


	//Ç§
	if (g == 0) {
		if (a > 0 || b > 0 || c > 0 || d > 0 || e > 0 || f > 0) {
			zero_flag = 1;
		}
	}

	if (g > 0) {

		if (zero_flag == 1) {
			printf("Áã");
			zero_flag = 0;
		}

		if (g == 1) {
			printf("Ò¼");
		}
		if (g == 2) {
			printf("·¡");
		}
		if (g == 3) {
			printf("Èþ");
		}
		if (g == 4) {
			printf("ËÁ");
		}
		if (g == 5) {
			printf("Îé");
		}
		if (g == 6) {
			printf("Â½");
		}
		if (g == 7) {
			printf("Æâ");
		}
		if (g == 8) {
			printf("°Æ");
		}
		if (g == 9) {
			printf("¾Á");
		}
		printf("Çª");
	}


	//°Ù
	if (h == 0) {
		if (a > 0 || b > 0 || c > 0 || d > 0 || e > 0 || f > 0 || g > 0) {
			zero_flag = 1;
		}
	}

	if (h > 0) {

		if (zero_flag == 1) {
			printf("Áã");
			zero_flag = 0;
		}

		if (h == 1) {
			printf("Ò¼");
		}
		if (h == 2) {
			printf("·¡");
		}
		if (h == 3) {
			printf("Èþ");
		}
		if (h == 4) {
			printf("ËÁ");
		}
		if (h == 5) {
			printf("Îé");
		}
		if (h == 6) {
			printf("Â½");
		}
		if (h == 7) {
			printf("Æâ");
		}
		if (h == 8) {
			printf("°Æ");
		}
		if (h == 9) {
			printf("¾Á");
		}
		printf("°Û");
	}

	//Ê®
	if (i == 0) {
		if (a > 0 || b > 0 || c > 0 || d > 0 || e > 0 || f > 0 || g > 0 || h > 0) {
			zero_flag = 1;
		}
	}

	if (i > 0) {

		if (zero_flag == 1) {
			printf("Áã");
			zero_flag = 0;
		}

		if (i == 1) {
			printf("Ò¼");
		}
		if (i == 2) {
			printf("·¡");
		}
		if (i == 3) {
			printf("Èþ");
		}
		if (i == 4) {
			printf("ËÁ");
		}
		if (i == 5) {
			printf("Îé");
		}
		if (i == 6) {
			printf("Â½");
		}
		if (i == 7) {
			printf("Æâ");
		}
		if (i == 8) {
			printf("°Æ");
		}
		if (i == 9) {
			printf("¾Á");
		}
		printf("Ê°");
	}

	//¸ö
	if (j == 0) {
		if (a > 0 || b > 0 || c > 0 || d > 0 || e > 0 || f > 0 || g > 0 || h > 0 || i > 0) {
			zero_flag = 1;
		}
	}

	if (j > 0) {

		if (zero_flag == 1) {
			printf("Áã");
			zero_flag = 0;
		}

		if (j == 1) {
			printf("Ò¼");
		}
		if (j == 2) {
			printf("·¡");
		}
		if (j == 3) {
			printf("Èþ");
		}
		if (j == 4) {
			printf("ËÁ");
		}
		if (j == 5) {
			printf("Îé");
		}
		if (j == 6) {
			printf("Â½");
		}
		if (j == 7) {
			printf("Æâ");
		}
		if (j == 8) {
			printf("°Æ");
		}
		if (j == 9) {
			printf("¾Á");
		}
	}

	if ((a > 0 || b > 0 || c > 0 || d > 0 || e > 0 || f > 0 || g > 0 || h > 0 || i > 0 || j > 0) && k == 0 && l == 0) {
		printf("Ô²Õû\n");
	}
	else {
		if (a > 0 || b > 0 || c > 0 || d > 0 || e > 0 || f > 0 || g > 0 || h > 0 || i > 0 || j > 0) {
			printf("Ô²");
		}

		if (k == 0) {
			if (a > 0 || b > 0 || c > 0 || d > 0 || e > 0 || f > 0 || g > 0 || h > 0 || i > 0 || j > 0) {
				printf("Áã");
			}

			if (l == 1) {
				printf("Ò¼");
			}
			if (l == 2) {
				printf("·¡");
			}
			if (l == 3) {
				printf("Èþ");
			}
			if (l == 4) {
				printf("ËÁ");
			}
			if (l == 5) {
				printf("Îé");
			}
			if (l == 6) {
				printf("Â½");
			}
			if (l == 7) {
				printf("Æâ");
			}
			if (l == 8) {
				printf("°Æ");
			}
			if (l == 9) {
				printf("¾Á");
			}
			printf("·Ö\n");
		}
		if (k > 0) {
			if (k == 1) {
				printf("Ò¼");
			}
			if (k == 2) {
				printf("·¡");
			}
			if (k == 3) {
				printf("Èþ");
			}
			if (k == 4) {
				printf("ËÁ");
			}
			if (k == 5) {
				printf("Îé");
			}
			if (k == 6) {
				printf("Â½");
			}
			if (k == 7) {
				printf("Æâ");
			}
			if (k == 8) {
				printf("°Æ");
			}
			if (k == 9) {
				printf("¾Á");
			}
			printf("½Ç");
			if (l == 0) {
				printf("Õû\n");
			}
			else {
				if (l == 1) {
					printf("Ò¼");
				}
				if (l == 2) {
					printf("·¡");
				}
				if (l == 3) {
					printf("Èþ");
				}
				if (l == 4) {
					printf("ËÁ");
				}
				if (l == 5) {
					printf("Îé");
				}
				if (l == 6) {
					printf("Â½");
				}
				if (l == 7) {
					printf("Æâ");
				}
				if (l == 8) {
					printf("°Æ");
				}
				if (l == 9) {
					printf("¾Á");
				}
				printf("·Ö\n");
			}
		}
	}

	return 0;
}