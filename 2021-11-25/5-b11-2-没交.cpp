/* 1851521 ������ �� */

/*	
*	��ע�������ҵ�ٽ��ˣ�ʵ���ǲ�����˼
*	ʵϰ�е�æ�������е���������
*	Ϊʲô�ٽ������أ���Ϊ��ǿ��֢������������û���������= =
*	��л������⣡
*/

#include <iostream>
#include <string>
#include <cmath>
//�ɰ���������Ҫ��ͷ�ļ�
using namespace std;

const char chnstr[] = "��Ҽ��������½��ƾ�"; /* ���������д "��" ~ "��" �ĵط���ֻ��������������ȡֵ */
string result;  /* ��result�⣬�����������κ���ʽ��ȫ�ֱ��� */

/* --���������Ҫ�ĺ��� --*/
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
    /* --���������Ҫ������ --*/
    
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

	/* ������� */
	cout << "��д�����:" << endl;

	if (a > 0) {
		first_number_flag = 1;
		zero_flag = 0;
		daxie(a, 0);
		result = result + "ʰ";
	}

	if (b > 0) {
		first_number_flag = 1;
		zero_flag = 0;
		daxie(b, 0);
	}
	if (first_number_flag)
		result = result +"��";

	if (c > 0) {
		first_number_flag = 1;
		zero_flag = 0;
		wan_flag = 1;
		daxie(c, 0);
		result = result +"Ǫ";
	}
	else
		zero_flag = 1;

	if (d > 0) {
		daxie(0, first_number_flag && zero_flag);
		first_number_flag = 1;
		zero_flag = 0;
		wan_flag = 1;
		daxie(d, 0);
		result = result +"��";
	}
	else
		zero_flag = 1;

	if (e > 0) {
		daxie(0, first_number_flag && zero_flag);
		first_number_flag = 1;
		zero_flag = 0;
		wan_flag = 1;
		daxie(e, 0);
		result = result +"ʰ";
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
		result = result +"��";

	zero_flag = 0;


	if (g > 0) {
		first_number_flag = 1;
		zero_flag = 0;
		daxie(g, 0);
		result = result +"Ǫ";
	}
	else
		zero_flag = 1;

	if (h > 0) {
		daxie(0, first_number_flag && zero_flag);
		first_number_flag = 1;
		zero_flag = 0;
		daxie(h, 0);
		result = result +"��";
	}
	else
		zero_flag = 1;

	if (i > 0) {
		daxie(0, first_number_flag && zero_flag);
		first_number_flag = 1;
		zero_flag = 0;
		daxie(i, 0);
		result = result +"ʰ";
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
		result = result +"Բ";
	if (!first_number_flag && k == 0 && l == 0) {
		daxie(0, 1);
		result = result +"Բ��";
	}

	if (k > 0) {
		daxie(k, 0);
		result = result +"��";
	}
	else
		zero_flag = 1;

	if (l > 0) {
		daxie(0, first_number_flag && zero_flag);
		daxie(l, 0);
		result = result +"��";
	}
	else
		result = result +"��";

    cout << result << endl;  /* ת���õ��Ĵ�д�����ֻ�����ñ���������֮ǰ�������κ���ʽ�Ĳ������ */
    return 0;
}