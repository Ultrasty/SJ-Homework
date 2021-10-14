/* 1851521 »Ìπ§ …ÚÃÏ”Ó */
#include <cmath>
#include <iostream>
using namespace std;
int main()
{
	cout << "«Î ‰»Î[0-100“⁄)÷Æº‰µƒ ˝◊÷:\n";
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
	//cout << " Æ“⁄Œª : " << a << endl;
	//cout << "“⁄Œª   : " << b << endl;
	//cout << "«ßÕÚŒª : " << c << endl;
	//cout << "∞ŸÕÚŒª : " << d << endl;
	//cout << " ÆÕÚŒª : " << e << endl;
	//cout << "ÕÚŒª   : " << f << endl;
	//cout << "«ßŒª   : " << g << endl;
	//cout << "∞ŸŒª   : " << h << endl;
	//cout << " ÆŒª   : " << i << endl;
	//cout << "‘≤     : " << j << endl;
	//cout << "Ω«     : " << k << endl;
	//cout << "∑÷     : " << l << endl;

	cout << "¥Û–¥Ω·π˚ «:" << endl;

	if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0 && g == 0 && h == 0 && i == 0 && j == 0 && k == 0 && l == 0) {
		cout << "¡„‘≤’˚" << endl;
		return 0;
	}

	bool zero_flag = 0;

	// Æ“⁄
	if (a > 0) {
		if (a == 1) {
			cout << "“º";
		}
		if (a == 2) {
			cout << "∑°";
		}
		if (a == 3) {
			cout << "»˛";
		}
		if (a == 4) {
			cout << "À¡";
		}
		if (a == 5) {
			cout << "ŒÈ";
		}
		if (a == 6) {
			cout << "¬Ω";
		}
		if (a == 7) {
			cout << "∆‚";
		}
		if (a == 8) {
			cout << "∞∆";
		}
		if (a == 9) {
			cout << "æ¡";
		}
		cout << " ∞";
	}


	//“⁄
	if (b == 1) {
		cout << "“º";
	}
	if (b == 2) {
		cout << "∑°";
	}
	if (b == 3) {
		cout << "»˛";
	}
	if (b == 4) {
		cout << "À¡";
	}
	if (b == 5) {
		cout << "ŒÈ";
	}
	if (b == 6) {
		cout << "¬Ω";
	}
	if (b == 7) {
		cout << "∆‚";
	}
	if (b == 8) {
		cout << "∞∆";
	}
	if (b == 9) {
		cout << "æ¡";
	}

	if (a > 0 || b > 0) {
		cout << "“⁄";
		if (c == 0) {
			zero_flag = 1;
		}
	}

	
	//«ßÕÚ
	if (c > 0) {
		if (c == 1) {
			cout << "“º";
		}
		if (c == 2) {
			cout << "∑°";
		}
		if (c == 3) {
			cout << "»˛";
		}
		if (c == 4) {
			cout << "À¡";
		}
		if (c == 5) {
			cout << "ŒÈ";
		}
		if (c == 6) {
			cout << "¬Ω";
		}
		if (c == 7) {
			cout << "∆‚";
		}
		if (c == 8) {
			cout << "∞∆";
		}
		if (c == 9) {
			cout << "æ¡";
		}
		cout << "«™";
	}

	//∞ŸÕÚ
	if (d == 0) {
		if (a > 0 || b > 0 || c > 0) {
			zero_flag = 1;
		}
	}

	if (d > 0) {

		if (zero_flag == 1) {
			cout << "¡„";
			zero_flag = 0;
		}

		if (d == 1) {
			cout << "“º";
		}
		if (d == 2) {
			cout << "∑°";
		}
		if (d == 3) {
			cout << "»˛";
		}
		if (d == 4) {
			cout << "À¡";
		}
		if (d == 5) {
			cout << "ŒÈ";
		}
		if (d == 6) {
			cout << "¬Ω";
		}
		if (d == 7) {
			cout << "∆‚";
		}
		if (d == 8) {
			cout << "∞∆";
		}
		if (d == 9) {
			cout << "æ¡";
		}
		cout << "∞€";
	}


	// ÆÕÚ
	if (e == 0) {
		if (a > 0 || b > 0 || c > 0 || d > 0) {
			zero_flag = 1;
		}
	}

	if (e > 0) {

		if (zero_flag == 1) {
			cout << "¡„";
			zero_flag = 0;
		}

		if (e == 1) {
			cout << "“º";
		}
		if (e == 2) {
			cout << "∑°";
		}
		if (e == 3) {
			cout << "»˛";
		}
		if (e == 4) {
			cout << "À¡";
		}
		if (e == 5) {
			cout << "ŒÈ";
		}
		if (e == 6) {
			cout << "¬Ω";
		}
		if (e == 7) {
			cout << "∆‚";
		}
		if (e == 8) {
			cout << "∞∆";
		}
		if (e == 9) {
			cout << "æ¡";
		}
		cout << " ∞";
	}

	//ÕÚ
	if (f == 0) {
		if (a > 0 || b > 0 || c > 0 || d > 0 || e > 0) {
			zero_flag = 1;
		}
	}

	if (f > 0) {

		if (zero_flag == 1) {
			cout << "¡„";
			zero_flag = 0;
		}

		if (f == 1) {
			cout << "“º";
		}
		if (f == 2) {
			cout << "∑°";
		}
		if (f == 3) {
			cout << "»˛";
		}
		if (f == 4) {
			cout << "À¡";
		}
		if (f == 5) {
			cout << "ŒÈ";
		}
		if (f == 6) {
			cout << "¬Ω";
		}
		if (f == 7) {
			cout << "∆‚";
		}
		if (f == 8) {
			cout << "∞∆";
		}
		if (f == 9) {
			cout << "æ¡";
		}
	}

	if (c > 0 || d > 0 || e > 0 || f > 0) {
		cout << "ÕÚ";
	}
	
	zero_flag = 0;
	

	//«ß
	if (g == 0) {
		if (a > 0 || b > 0 || c > 0 || d > 0 || e > 0 || f > 0) {
			zero_flag = 1;
		}
	}

	if (g > 0) {

		if (zero_flag == 1) {
			cout << "¡„";
			zero_flag = 0;
		}

		if (g == 1) {
			cout << "“º";
		}
		if (g == 2) {
			cout << "∑°";
		}
		if (g == 3) {
			cout << "»˛";
		}
		if (g == 4) {
			cout << "À¡";
		}
		if (g == 5) {
			cout << "ŒÈ";
		}
		if (g == 6) {
			cout << "¬Ω";
		}
		if (g == 7) {
			cout << "∆‚";
		}
		if (g == 8) {
			cout << "∞∆";
		}
		if (g == 9) {
			cout << "æ¡";
		}
		cout << "«™";
	}


	//∞Ÿ
	if (h == 0) {
		if (a > 0 || b > 0 || c > 0 || d > 0 || e > 0 || f > 0 || g > 0) {
			zero_flag = 1;
		}
	}

	if (h > 0) {

		if (zero_flag == 1) {
			cout << "¡„";
			zero_flag = 0;
		}

		if (h == 1) {
			cout << "“º";
		}
		if (h == 2) {
			cout << "∑°";
		}
		if (h == 3) {
			cout << "»˛";
		}
		if (h == 4) {
			cout << "À¡";
		}
		if (h == 5) {
			cout << "ŒÈ";
		}
		if (h == 6) {
			cout << "¬Ω";
		}
		if (h == 7) {
			cout << "∆‚";
		}
		if (h == 8) {
			cout << "∞∆";
		}
		if (h == 9) {
			cout << "æ¡";
		}
		cout << "∞€";
	}

	// Æ
	if (i == 0) {
		if (a > 0 || b > 0 || c > 0 || d > 0 || e > 0 || f > 0 || g > 0 || h > 0) {
			zero_flag = 1;
		}
	}

	if (i > 0) {

		if (zero_flag == 1) {
			cout << "¡„";
			zero_flag = 0;
		}

		if (i == 1) {
			cout << "“º";
		}
		if (i == 2) {
			cout << "∑°";
		}
		if (i == 3) {
			cout << "»˛";
		}
		if (i == 4) {
			cout << "À¡";
		}
		if (i == 5) {
			cout << "ŒÈ";
		}
		if (i == 6) {
			cout << "¬Ω";
		}
		if (i == 7) {
			cout << "∆‚";
		}
		if (i == 8) {
			cout << "∞∆";
		}
		if (i == 9) {
			cout << "æ¡";
		}
		cout << " ∞";
	}

	//∏ˆ
	if (j == 0) {
		if (a > 0 || b > 0 || c > 0 || d > 0 || e > 0 || f > 0 || g > 0 || h > 0 || i > 0) {
			zero_flag = 1;
		}
	}

	if (j > 0) {

		if (zero_flag == 1) {
			cout << "¡„";
			zero_flag = 0;
		}

		if (j == 1) {
			cout << "“º";
		}
		if (j == 2) {
			cout << "∑°";
		}
		if (j == 3) {
			cout << "»˛";
		}
		if (j == 4) {
			cout << "À¡";
		}
		if (j == 5) {
			cout << "ŒÈ";
		}
		if (j == 6) {
			cout << "¬Ω";
		}
		if (j == 7) {
			cout << "∆‚";
		}
		if (j == 8) {
			cout << "∞∆";
		}
		if (j == 9) {
			cout << "æ¡";
		}
	}

	if ((a > 0 || b > 0 || c > 0 || d > 0 || e > 0 || f > 0 || g > 0 || h > 0 || i > 0 || j > 0) && k == 0 && l == 0) {
		cout << "‘≤’˚" << endl;
	}
	else {
		if (a > 0 || b > 0 || c > 0 || d > 0 || e > 0 || f > 0 || g > 0 || h > 0 || i > 0 || j > 0) {
			cout << "‘≤";
		}
		
		if (k == 0) {
			if (a > 0 || b > 0 || c > 0 || d > 0 || e > 0 || f > 0 || g > 0 || h > 0 || i > 0 || j > 0) {
				cout << "¡„";
			}
			
			if (l == 1) {
				cout << "“º";
			}
			if (l == 2) {
				cout << "∑°";
			}
			if (l == 3) {
				cout << "»˛";
			}
			if (l == 4) {
				cout << "À¡";
			}
			if (l == 5) {
				cout << "ŒÈ";
			}
			if (l == 6) {
				cout << "¬Ω";
			}
			if (l == 7) {
				cout << "∆‚";
			}
			if (l == 8) {
				cout << "∞∆";
			}
			if (l == 9) {
				cout << "æ¡";
			}
			cout << "∑÷" << endl;
		}
		if (k > 0) {
			if (k == 1) {
				cout << "“º";
			}
			if (k == 2) {
				cout << "∑°";
			}
			if (k == 3) {
				cout << "»˛";
			}
			if (k == 4) {
				cout << "À¡";
			}
			if (k == 5) {
				cout << "ŒÈ";
			}
			if (k == 6) {
				cout << "¬Ω";
			}
			if (k == 7) {
				cout << "∆‚";
			}
			if (k == 8) {
				cout << "∞∆";
			}
			if (k == 9) {
				cout << "æ¡";
			}
			cout << "Ω«";
			if (l == 0) {
				cout << "’˚" << endl;
			}
			else {
				if (l == 1) {
					cout << "“º";
				}
				if (l == 2) {
					cout << "∑°";
				}
				if (l == 3) {
					cout << "»˛";
				}
				if (l == 4) {
					cout << "À¡";
				}
				if (l == 5) {
					cout << "ŒÈ";
				}
				if (l == 6) {
					cout << "¬Ω";
				}
				if (l == 7) {
					cout << "∆‚";
				}
				if (l == 8) {
					cout << "∞∆";
				}
				if (l == 9) {
					cout << "æ¡";
				}
				cout << "∑÷" << endl;
			}
		}
	}

	return 0;
}