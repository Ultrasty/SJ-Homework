/* �� 1851521 ������ */
#pragma once
#include<iostream>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include"cmd_console_tools.h"
using namespace std;
/* ------------------------------------------------------------------------------------------------------

     ���ļ����ܣ�
	1��Ϊ�˱�֤ hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp ���໥���ʺ����ĺ�������
	2��һ�����ϵ�cpp���õ��ĺ궨�壨#define����ȫ��ֻ����const����������������
	3�����Բο� cmd_console_tools.h ��д���������Ķ�����ᣩ
   ------------------------------------------------------------------------------------------------------ */


void play(char choice);
int display_menu();
void delay_sometime();
void clear_global();
