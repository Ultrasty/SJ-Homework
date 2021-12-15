/* 1851521 ������ �� */

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
using namespace std;

struct KFC {
	char code;
	const char* name;
	float price;
};

struct SPECIAL {
	const char* code;
	const char* name;
	float price;
};

const struct KFC list[] = {
	{'A', "�������ȱ�",         18.5},
	{'B', "���༦�ȱ�",         18.5},
	{'C', "�°¶��������ȱ�",   19},
	{'D', "�ϱ��������",       17},
	{'E', "������ţ��",         19.5},
	{'F', "����㱤",         18.5},
	{'G', "˱ָԭζ��(1��)",    11.5},
	{'H', "֥֥����������Ƥ��", 12.5},
	{'I', "�°¶�������(2��)",  12.5},
	{'J', "�������׻�",         11.5},
	{'K', "��������(2��)",      12.0},
	{'L', "�ٽ��޹Ǵ���(2��)",12.5},
	{'M', "����ɫ��",           13},
	{'N', "����(С)",           9},
	{'O', "����(��)",           12},
	{'P', "����(��)",           14},
	{'Q', "ܽ��������",         9},
	{'R', "ԭζ��Ͳ������",     6},
	{'S', "����������",         7},
	{'T', "�������װ�",         9.0},
	{'U', "��ʽ��̢",           8.0},
	{'V', "���¿���(С)",       7.0},
	{'W', "���¿���(��)",       9.5},
	{'X', "���¿���(��)",       11.5},
	{'Y', "�����֭����",       12.5},
	{'Z', "����������",         11.5},
	{'\0', NULL,                0}
};

const struct SPECIAL special[] = {
	//	{"ANV", "�������ȱ����������",  24}, //�������Ҫ���ſ����ע�͵���һ�еġ�BMV���Żݣ��۲��Żݲ˵��Ƿ����˱仯
		{"BMV", "���༦�ȱ���ֵ�ײ�",    26},
		{"ABCGGIIKKOUWWW", "��ֵȫ��Ͱ", 115},
		{"KIIRRJUWW", "�ͷ�С��Ͱ",      65},
		{"JJ","�������׻�(2��С)",       12.5},
		{NULL, NULL, 0}
};

int main()
{
	const KFC* kp = list;
	const SPECIAL* sp = special;
	system("mode con cols=120 lines=35");
	char a[1000];
	char name_info[26][100];

	for (int i = 0; i < 26; i++) {
		name_info[i][0] = 0;
	}

	while (kp->code != 0) {
		strcpy(name_info[kp->code - 'A'],kp->name);
		kp++;
	}

	while (1) {

		kp = list;
		sp = special;
		int huanhang = 0;
		system("cls");
		cout << "=============================================================" << endl;
		cout << "                      KFC 2021�＾�˵�" << endl;
		cout << "=============================================================" << endl;
		cout << setiosflags(ios::left);
		while (kp->code != 0) {
			cout << " " << kp->code << " " << setw(21) << kp->name << setw(5)<< kp->price;
			if (huanhang == 1)
				cout << endl;
			if (huanhang == 0) {
				cout << " | ";
			}
			huanhang = (huanhang + 1) % 2;
			kp++;
		}

		cout << "���Ż���Ϣ����" << endl << endl;

		while (sp->code != NULL) {
			cout << sp->name << "=";
			for (unsigned int i = 0; i < strlen(sp->code); i++) {
				cout << "+" << name_info[sp->code[i] - 'A'];
			}
			cout << "=" << sp->price;
			cout << endl;
			sp++;
		}

		cout << "\n���������˵������\n";
		cout << "ANV=�������ȱ�+����(С)+���¿���(С) / akaak=�������ȱ�*3+��������*2" << endl;
		cout << "��ĸ���ִ�Сд������˳�򣬵�������0���˳�����" << endl;
		cout << endl;
		cout << "��㵥��";

		//������Ϣ���


		a[0] = 0;
		cin >> a;
		if (a[0] == '0')
			break;

		char* p = a;
		int diandan[26], diandan_ori[26];
		float price = 0;
		for (int i = 0; i < 26; i++) {
			diandan_ori[i] = diandan[i] = 0;
		}

		while (*p != 0) {
			if (*p >= 'a' && *p <= 'z') {
				*p -= 0x20;
			}

			diandan_ori[*p - 'A'] = ++diandan[*p - 'A'];
			p++;
		}


		kp = list;
		sp = special;


		while (sp->code != NULL) {
			while (1) {
				bool flag = true;
				for (unsigned int i = 0; i < strlen(sp->code); i++) {
					diandan[sp->code[i] - 'A']--;
				}

				for (int i = 0; i < 26; i++) {
					if (diandan[i] < 0) {
						flag = false;
					}
				}

				if (flag == true) {
					price += sp->price;
				}
				else {
					for (unsigned int i = 0; i < strlen(sp->code); i++) {
						diandan[sp->code[i] - 'A']++;
					}
					break;
				}
			}
			sp++;
		}

		while (kp->code != 0) {
			while (1) {
				if (diandan[kp->code - 'A'] > 0) {
					diandan[kp->code - 'A']--;
					price += kp->price;
				}
				else {
					break;
				}
			}
			kp++;
		}

		cout << "���ĵ��=";
		for (int i = 0; i < 26; i++) {
			if (diandan_ori[i] != 0) {
				if (diandan[i] == 1) {
					cout << "+" << name_info[i];
				}
				else {
					cout <<"+"<<name_info[i] << "*" << diandan_ori[i];
				}
			}
		}
		cout << endl;
		cout << "���ƣ�" << price << "Ԫ" << endl;

		cout << "�����ɣ������������" << endl;
		system("pause");
	}
}