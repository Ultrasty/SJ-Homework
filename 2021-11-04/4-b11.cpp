/* 1851521 �� ������ */
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		����   ��1����������һ�����������������������ӵĺ����в������κ���ʽ��ѭ��
				 2��������ų���
				 3������const�ͱ���

		������ ��1������ȫ�ֱ���
   ----------------------------------------------------------------------------------- */


   /***************************************************************************
	 �������ƣ�
	 ��    �ܣ���ӡ����
	 ���������
	 �� �� ֵ��
	 ˵    ����
   ***************************************************************************/

void print_line_without_padding(char start_ch, char end_ch) {

	if (start_ch == end_ch) {
		cout << start_ch;
	}
	else {
		cout << end_ch;
		print_line_without_padding(start_ch, end_ch - 1);
		cout << end_ch;
	}
}

void print_line(char start_ch, char end_ch, int padding) {
	cout << setfill(' ') << setw(padding) << " ";
	print_line_without_padding(start_ch, end_ch);
	cout << endl;
}


void print_upper(char start_ch, char end_ch, int padding) {

	if (start_ch != end_ch) {
		print_upper(start_ch, end_ch - 1, padding + 1);
		print_line(start_ch, end_ch, padding);
	}
	else {
		print_line(start_ch, end_ch, padding);
	}
}

void print_below(char start_ch, char end_ch, int padding) {
	if (start_ch != end_ch) {
		
		print_line(start_ch, end_ch, padding);
		print_below(start_ch, end_ch - 1, padding + 1);
	}
	else {
		print_line(start_ch, end_ch, padding);
	}
}

void print_diamond(char start_ch, char end_ch)
{

	if (start_ch == end_ch) {
		print_line_without_padding(start_ch, end_ch);
		cout << endl;
	}
	else {
		/* ����ʵ�֣������в������κ���ʽ��ѭ�����������徲̬�ֲ����� */
		int padding = 0;
		print_upper(start_ch, end_ch - 1, padding + 1);

		//��ӡ�м�����
		print_line_without_padding(start_ch, end_ch);
		cout << endl;

		//��ӡ������
		print_below(start_ch, end_ch - 1, padding + 1);
	}
}



/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main����������...�����޸ģ�����λ�ò�׼�޸�
***************************************************************************/
int main()
{
	char end_ch;

	/* ������������ַ�(����д��Ч) */
	cout << "����������ַ�(A~Z)" << endl;
	end_ch = getchar();

	/* ����(�м�ΪA) */
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1) << "=" << endl; /* ��������������=(��������ѭ��) */
	cout << "����(" << end_ch << "->A)" << endl;
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1) << "=" << endl; /* ��������������=(��������ѭ��) */
	print_diamond('A', end_ch);
	cout << endl;

	return 0;
}
