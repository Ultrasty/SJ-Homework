/* 1851521 软工 沈天宇 */
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		允许   ：1、按需增加一个或多个函数，但是所有增加的函数中不允许任何形式的循环
				 2、定义符号常量
				 3、定义const型变量

		不允许 ：1、定义全局变量
   ----------------------------------------------------------------------------------- */


   /***************************************************************************
	 函数名称：
	 功    能：打印菱形
	 输入参数：
	 返 回 值：
	 说    明：
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
		/* 按需实现，函数中不允许任何形式的循环，但允许定义静态局部变量 */
		int padding = 0;
		print_upper(start_ch, end_ch - 1, padding + 1);

		//打印中间那行
		print_line_without_padding(start_ch, end_ch);
		cout << endl;

		//打印下三角
		print_below(start_ch, end_ch - 1, padding + 1);
	}
}



/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数中两处...允许修改，其余位置不准修改
***************************************************************************/
int main()
{
	char end_ch;

	/* 键盘输入结束字符(仅大写有效) */
	cout << "请输入结束字符(A~Z)" << endl;
	end_ch = getchar();

	/* 菱形(中间为A) */
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1) << "=" << endl; /* 按菱形最大宽度输出=(不允许用循环) */
	cout << "菱形(" << end_ch << "->A)" << endl;
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1) << "=" << endl; /* 按菱形最大宽度输出=(不允许用循环) */
	print_diamond('A', end_ch);
	cout << endl;

	return 0;
}
