/* 1851521 �� ������ */
//���������˵����ֺ���
#include"90-b2.h"
#include<iostream>
#include<conio.h>
using namespace std;

int display_menu()
{
	char ret;
	cct_cls();

	/*cct_setcolor(COLOR_BLACK, COLOR_YELLOW);
	cout << "��������ĳЩ�ط�δ�������������������С�����룡��" << endl;
	cout << "���������������ĸȫ��Ϊ  ->Сд<-  ����" << endl;
	cout << "�����������bug���Գ�����������������~��" << endl;
	cct_setcolor();*/
	cout << "---------------------------------------" << endl;
	cout << "1.�������ҳ��ɺϳ����ʶ���ǵݹ飩" << endl;
	cout << "2.�������ҳ��ɺϳ����ʶ���ݹ飩" << endl;
	cout << "3.���������һ�κϳɣ��ֲ�����ʾ��" << endl;
	cout << "4.�����������棨�ֲ�����ʾ��" << endl;
	cout << "5.αͼ�ν�����ʾ��ʼ���飨�޷ָ��ߣ�" << endl;
	cout << "6.αͼ�ν�����ʾ��ʼ���飨�зָ��ߣ�" << endl;
	cout << "7.αͼ�ν������ü�ͷ��/���ѡ��ǰɫ��" << endl;
	cout << "8.αͼ�ν������һ�κϳɣ��ֲ��裩" << endl;
	cout << "9.αͼ�ν���������(֧�����)" << endl;
	cout << "---------------------------------------" << endl;
	cout << "0.�˳�" << endl;
	cout << "---------------------------------------" << endl;
	cout << "[��ѡ��:] ";

	while (1) {
		ret = _getche();
		if (ret >= '0' && ret <= '9') {
			break;
		}
		else
			cout << "\b \b";
	}


	cout << endl << endl << endl;

	if (ret == '0') {
		return -1;
	}
	else {
		return ret - '0';
	}

	return 0;
}

int main()
{

	/* demo������ִ�д˾䣬��cmd��������Ϊ40��x120�У����������120�У�����9000�У���cmd�����Ҳ���д�ֱ�����ˣ�*/
	cct_setconsoleborder(120, 40, 120, 9000);
	while (1) {
		int ret = display_menu();
		if (ret == -1)
			break;
		play(ret);
	}

}