/* 1851521 ������ �� */
#include <iostream>
using namespace std;

#define  N  10	/* �������ת��10������ */

/* �������ٶ�������������ȫ�ֱ��� */

int main()
{
	/* ����в���Ҫ�ı���������ɾ��������������ӻ��滻Ϊ�������͵ı��� */
	char str[256], * p;
	int  a[N] = { 0 }, * pnum, * pa;
	bool is_num;

	/* ����Ķ��岻׼��(ɾ������Ҫ�ı�������)������Ϊ����ľ���ʵ�֣�Ҫ�󲻵��ٶ����κα����������������� */
	cout << "�����������������������ֵ��ַ���" << endl;
	is_num = 0;
	gets_s(str);
	p = str;

	while (*p != 0) {
		p++;
	}
	*p = '#';
	*(p + 1) = 0;
	p = str;

	pnum = pa = a;

	pa = pa + 10;
	while (pnum != pa) {
		*pnum = 0;
		pnum++;
	}

	pnum = a;
	while (pnum != pa) {
		if (*p == 0) {
			break;
		}
		if (*p >= '0' && *p <= '9') {
			is_num = 1;
			*pnum = *pnum * 10 + *p - '0';
		}
		else if (is_num == 1) {
			is_num = 0;
			pnum++;
		}
		p++;
	}

	cout << "����" << pnum - a << "������" << endl;
	pa = a;
	while (pnum != pa) {
		cout << *pa << " ";
		pa++;
	}
	cout << endl;

	return 0;
}
