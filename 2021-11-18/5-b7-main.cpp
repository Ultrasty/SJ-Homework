/* 1851521 ������ �� */
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include "5-b7.h"
using namespace std;

int countt = 0;
int stackA[] = { 0,0,0,0,0,0,0,0,0,0 };
int stackB[] = { 0,0,0,0,0,0,0,0,0,0 };
int stackC[] = { 0,0,0,0,0,0,0,0,0,0 };
int A = 0, B = 0, C = 0;
int delay;
int display_stack;
/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2����������ȫ�ֱ�������̬�ֲ�����
   3������������������������ʼ/Ŀ�����ĺ���������������ʹ��ѭ�������������
   4����������ú������У���main�в���������κ���ʽ��ѭ��
	  ���������main�н��У���main���������ѭ��
   --------------------------------------------------------------------- */

   /***************************************************************************
	 �������ƣ�
	 ��    �ܣ���ӡn�㺺ŵ�����ƶ�˳��
	 ���������int n������
			   char src����ʼ��
			   char tmp���м���
			   char dst��Ŀ����
	 �� �� ֵ��
	 ˵    ����1�����������βΡ��������;���׼��
			   2������������������κ���ʽ��ѭ��
   ***************************************************************************/

void push(char i, int j)
{
	if (i == 'A') {
		stackA[A++] = j;
	}
	if (i == 'B') {
		stackB[B++] = j;
	}
	if (i == 'C') {
		stackC[C++] = j;
	}
}

int pop(char i)
{
	int temp = 0;
	if (i == 'A') {

		temp = stackA[--A];
		stackA[A] = 0;
	}
	if (i == 'B') {

		temp = stackB[--B];
		stackB[B] = 0;
	}
	if (i == 'C') {

		temp = stackC[--C];
		stackC[C] = 0;
	}
	return temp;
}

void print_stack()
{
	cct_gotoxy(20, 17);
	cout << " A:";
	for (int i = 0; i < 10; i++) {
		if (stackA[i] == 10)
			cout << 10;
		if (stackA[i] < 10 && stackA[i]>0)
			cout << " " << stackA[i];
		if (stackA[i] == 0)
			cout << "  ";
	}
	cout << " ";


	cout << "B:";
	for (int i = 0; i < 10; i++) {
		if (stackB[i] == 10)
			cout << 10;
		if (stackB[i] < 10 && stackB[i]>0)
			cout << " " << stackB[i];
		if (stackB[i] == 0)
			cout << "  ";
	}
	cout << " ";


	cout << "C:";
	for (int i = 0; i < 10; i++) {
		if (stackC[i] == 10)
			cout << 10;
		if (stackC[i] < 10 && stackC[i]>0)
			cout << " " << stackC[i];
		if (stackC[i] == 0)
			cout << "  ";
	}
	cout << endl;
	if (delay == 0) {
		_getch();
	}
	else if (delay == 1) {
		Sleep(2000);
	}
	else if (delay == 2) {
		Sleep(1000);
	}
	else if (delay == 3) {
		Sleep(500);
	}
	else if (delay == 4) {
		Sleep(200);
	}
	else if (delay == 5) {
		Sleep(50);
	}
}

void print_step(int n, char src, char dst)
{
	cct_gotoxy(0, 17);
	countt++;
	cout << "��" << setfill(' ') << setw(4) << countt << " ��(";
	if (n < 10) {
		cout << " ";
	}
	cout << n << "): " << src << "-->" << dst;
	push(dst, pop(src));
}

//�����ӡ����
void print_stack_vertical()
{
	int x = 11;
	int y = 11;
	for (int i = 0; i < 10; i++) {
		cct_gotoxy(x, y - i);
		if (stackA[i] != 0)
			cout << stackA[i];
		else
			cout << " ";
	}
	for (int i = 0; i < 10; i++) {
		cct_gotoxy(x + 10, y - i);
		if (stackB[i] != 0)
			cout << stackB[i];
		else
			cout << " ";
	}
	for (int i = 0; i < 10; i++) {
		cct_gotoxy(x + 20, y - i);
		if (stackC[i] != 0)
			cout << stackC[i];
		else
			cout << " ";
	}
	if (delay == 0) {
		_getch();
	}
	else if (delay == 1) {
		Sleep(2000);
	}
	else if (delay == 2) {
		Sleep(1000);
	}
	else if (delay == 3) {
		Sleep(500);
	}
	else if (delay == 4) {
		Sleep(200);
	}
	else if (delay == 5) {
		Sleep(50);
	}
}

void hanoi(int n, char src, char tmp, char dst)
{



	if (n == 1) {
		print_step(1, src, dst);
		if (display_stack)
			print_stack();
		print_stack_vertical();
	}
	else if (n == 2) {
		print_step(1, src, tmp);
		if (display_stack)
			print_stack();
		print_stack_vertical();

		print_step(2, src, dst);
		if (display_stack)
			print_stack();
		print_stack_vertical();

		print_step(1, tmp, dst);
		if (display_stack)
			print_stack();
		print_stack_vertical();
	}
	else {
		hanoi(n - 1, src, dst, tmp);
		print_step(n, src, dst);
		if (display_stack)
			print_stack();
		print_stack_vertical();
		hanoi(n - 1, tmp, src, dst);
	}
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    �����������(��������뺯��)�����õݹ麯��
***************************************************************************/
int main()
{
	int n;
	char src, tmp, dst;
	//������ջ���������ʱ����
	char c;

	while (1) {
		cout << "�����뺺ŵ���Ĳ���(1-10)��" << endl;
		cin >> n;

		if (cin.fail()) {
			cin.clear();
			while ((c = getchar()) != '\n' && c != EOF)
				;
			continue;
		}
		else if (n < 1 || n>10) {
			while ((c = getchar()) != '\n' && c != EOF)
				;
			continue;
		}
		else {
			while ((c = getchar()) != '\n' && c != EOF)
				;
			break;
		}

	}

	while (1) {
		cout << "��������ʼ��(A-C)��" << endl;
		cin >> src;

		//תΪ��д
		if (src == 'a' || src == 'b' || src == 'c') {
			src -= 0x20;
		}

		if (cin.fail()) {
			cin.clear();
			while ((c = getchar()) != '\n' && c != EOF)
				;
			continue;
		}
		else if (src < 'A' || src>'C') {
			while ((c = getchar()) != '\n' && c != EOF)
				;
			continue;
		}
		else {
			while ((c = getchar()) != '\n' && c != EOF)
				;
			break;
		}
	}

	while (1) {
		cout << "������Ŀ����(A-C)��" << endl;
		cin >> dst;

		//תΪ��д
		if (dst == 'a' || dst == 'b' || dst == 'c') {
			dst -= 0x20;
		}

		if (cin.fail()) {
			cin.clear();
			while ((c = getchar()) != '\n' && c != EOF)
				;
			continue;
		}
		else if (dst < 'A' || dst>'C') {
			while ((c = getchar()) != '\n' && c != EOF)
				;
			continue;
		}
		else if (dst == src) {
			cout << "Ŀ����(" << dst << ")��������ʼ��(" << src << ")��ͬ" << endl;
			while ((c = getchar()) != '\n' && c != EOF)
				;
			continue;
		}
		else {
			while ((c = getchar()) != '\n' && c != EOF)
				;
			break;
		}
	}

	while (1) {
		cout << "�������ƶ��ٶ�(0-5: 0-���س�������ʾ 1-��ʱ� 5-��ʱ���)" << endl;
		cin >> delay;
		if (cin.fail()) {
			cin.clear();
			while ((c = getchar()) != '\n' && c != EOF)
				;
			continue;
		}
		else if (delay < 0 || delay > 5) {
			while ((c = getchar()) != '\n' && c != EOF)
				;
			continue;
		}
		else {
			while ((c = getchar()) != '\n' && c != EOF)
				;
			break;
		}
	}

	while (1) {
		cout << "�������Ƿ���ʾ�ڲ�����ֵ(0-����ʾ 1-��ʾ)" << endl;
		cin >> display_stack;
		if (cin.fail()) {
			cin.clear();
			while ((c = getchar()) != '\n' && c != EOF)
				;
			continue;
		}
		else if (display_stack < 0 || display_stack > 1) {
			while ((c = getchar()) != '\n' && c != EOF)
				;
			continue;
		}
		else {
			while ((c = getchar()) != '\n' && c != EOF)
				;
			break;
		}
	}

	tmp = 3 * 'B' - src - dst;

	//��ʼ��ջ
	if (src == 'A') {
		for (int i = 0; i < n; i++) {
			stackA[i] = n - i;
		}
		A = n;
	}
	if (src == 'B') {
		for (int i = 0; i < n; i++) {
			stackB[i] = n - i;
		}
		B = n;
	}
	if (src == 'C') {
		for (int i = 0; i < n; i++) {
			stackC[i] = n - i;
		}
		C = n;
	}



	cct_cls();
	cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " �㣬��ʱ����Ϊ " << delay << "��" << (display_stack ? "" : "��") << "��ʾ�ڲ�����ֵ" << endl;
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	cout << "         =========================" << endl;
	cout << "           A         B         C" << endl;
	cout << endl << endl << endl;

	cct_gotoxy(0, 17);
	

	if (display_stack) {
		cout << "��ʼ:                ";
		print_stack();
	}
	print_stack_vertical();
	hanoi(n, src, tmp, dst);

	cct_gotoxy(0, 27);
	system("pause");
}
