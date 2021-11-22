/* 1851521 沈天宇 软工 */
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
/* ----具体要求----
   1、不允许添加其它头文件
   2、不允许定义全局变量、静态局部变量
   3、允许添加用于输入层数、起始/目标柱的函数，函数中允许使用循环处理错误输入
   4、如果输入用函数进行，则main中不允许出现任何形式的循环
	  如果输入在main中进行，则main中允许出现循环
   --------------------------------------------------------------------- */

   /***************************************************************************
	 函数名称：
	 功    能：打印n层汉诺塔的移动顺序
	 输入参数：int n：层数
			   char src：起始柱
			   char tmp：中间柱
			   char dst：目标柱
	 返 回 值：
	 说    明：1、函数名、形参、返回类型均不准动
			   2、本函数不允许出现任何形式的循环
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
	cout << "第" << setfill(' ') << setw(4) << countt << " 步(";
	if (n < 10) {
		cout << " ";
	}
	cout << n << "): " << src << "-->" << dst;
	push(dst, pop(src));
}

//竖向打印数组
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
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：完成输入(或调用输入函数)、调用递归函数
***************************************************************************/
int main()
{
	int n;
	char src, tmp, dst;
	//用于清空缓冲区的临时变量
	char c;

	while (1) {
		cout << "请输入汉诺塔的层数(1-10)：" << endl;
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
		cout << "请输入起始柱(A-C)：" << endl;
		cin >> src;

		//转为大写
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
		cout << "请输入目标柱(A-C)：" << endl;
		cin >> dst;

		//转为大写
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
			cout << "目标柱(" << dst << ")不能与起始柱(" << src << ")相同" << endl;
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
		cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)" << endl;
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
		cout << "请输入是否显示内部数组值(0-不显示 1-显示)" << endl;
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

	//初始化栈
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
	cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层，延时设置为 " << delay << "，" << (display_stack ? "" : "不") << "显示内部数组值" << endl;
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	cout << "         =========================" << endl;
	cout << "           A         B         C" << endl;
	cout << endl << endl << endl;

	cct_gotoxy(0, 17);
	

	if (display_stack) {
		cout << "初始:                ";
		print_stack();
	}
	print_stack_vertical();
	hanoi(n, src, tmp, dst);

	cct_gotoxy(0, 27);
	system("pause");
}
