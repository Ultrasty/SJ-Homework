/* 1851521 ������ �� */
#include <cmath>
#include <iostream>
using namespace std;

/* �ɸ�����Ҫ�����Ӧ������ */

/***************************************************************************
  �������ƣ�
  ��    �ܣ������д��0~9
  ���������
  �� �� ֵ��
  ˵    �������������⣬�������κκ�����������㡱-������!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* ������Ա��������κ��޸� */
	switch (num) {
		case 0:
			if (flag_of_zero)	//�˱��ʲô��˼������˼��
				cout << "��";
			break;
		case 1:
			cout << "Ҽ";
			break;
		case 2:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 5:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 7:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 9:
			cout << "��";
			break;
		default:
			cout << "error";
			break;
	}
}

/* �ɸ�����Ҫ�Զ�����������(Ҳ���Բ�����) */

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
	//��������
	double n;
	bool zero_flag = 0;
	int first_number_flag = 0;
	int wan_flag = 0;
	int a, b, c, d, e, f, g, h, i, j, k, l;

	cout << "������[0-100��)֮�������:\n";
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
	/*cout << "ʮ��λ : " << a << endl;
	cout << "��λ   : " << b << endl;
	cout << "ǧ��λ : " << c << endl;
	cout << "����λ : " << d << endl;
	cout << "ʮ��λ : " << e << endl;
	cout << "��λ   : " << f << endl;
	cout << "ǧλ   : " << g << endl;
	cout << "��λ   : " << h << endl;
	cout << "ʮλ   : " << i << endl;
	cout << "Բ     : " << j << endl;
	cout << "��     : " << k << endl;
	cout << "��     : " << l << endl;*/
	/* ������� */
	cout << "��д�����:" << endl;

	if (a > 0){
		first_number_flag = 1;
		zero_flag = 0;
		daxie(a, 0);
		cout << "ʰ";
	}

	if (b > 0){
		first_number_flag = 1;
		zero_flag = 0;
		daxie(b, 0);
	}
	if (first_number_flag)
		cout << "��";

	if (c > 0){
		first_number_flag = 1;
		zero_flag = 0;
		wan_flag = 1;
		daxie(c, 0);
		cout << "Ǫ";
	}
	else
		zero_flag = 1;

	if (d > 0){
		daxie(0, first_number_flag && zero_flag);
		first_number_flag = 1;
		zero_flag = 0;
		wan_flag = 1;
		daxie(d, 0);
		cout << "��";
	}
	else
		zero_flag = 1;

	if (e > 0){
		daxie(0, first_number_flag && zero_flag);
		first_number_flag = 1;
		zero_flag = 0;
		wan_flag = 1;
		daxie(e, 0);
		cout << "ʰ";
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
		cout << "��";

	zero_flag = 0;


	if (g > 0){
		first_number_flag = 1;
		zero_flag = 0;
		daxie(g, 0);
		cout << "Ǫ";
	}
	else
		zero_flag = 1;

	if (h > 0){
		daxie(0, first_number_flag && zero_flag);
		first_number_flag = 1;
		zero_flag = 0;
		daxie(h, 0);
		cout << "��";
	}
	else
		zero_flag = 1;

	if (i > 0){
		daxie(0, first_number_flag && zero_flag);
		first_number_flag = 1;
		zero_flag = 0;
		daxie(i, 0);
		cout << "ʰ";
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
		cout << "Բ";
	if (!first_number_flag && k == 0 && l == 0){
		daxie(0, 1);
		cout << "Բ��" << endl;
	}

	if (k > 0){
		daxie(k, 0);
		cout << "��";
	}
	else
		zero_flag = 1;

	if (l > 0){
		daxie(0, first_number_flag && zero_flag);
		daxie(l, 0);
		cout << "��" << endl;
	}
	else
		cout << "��" << endl;

	return 0;
}
