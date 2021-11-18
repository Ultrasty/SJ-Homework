/* 1851521 沈天宇 软工 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>



int countt = 0;
int stack[3][10] = { { 0,0,0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0,0,0 } };
int ABCpointer[] = { 0,0,0 };
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

   /**
	 push函数 顾名思义
   */
void push(char i, int j)
{
	if (i == 'A') {
		stack[0][ABCpointer[0]++] = j;
	}
	if (i == 'B') {
		stack[1][ABCpointer[1]++] = j;
	}
	if (i == 'C') {
		stack[2][ABCpointer[2]++] = j;
	}
}

int pop(char i)
{
	int temp = 0;
	if (i == 'A') {

		temp = stack[0][--ABCpointer[0]];
		stack[0][ABCpointer[0]] = 0;
	}
	if (i == 'B') {

		temp = stack[1][--ABCpointer[1]];
		stack[1][ABCpointer[1]] = 0;
	}
	if (i == 'C') {

		temp = stack[2][--ABCpointer[2]];
		stack[2][ABCpointer[2]] = 0;
	}
	return temp;
}

void print_stack()
{
	printf( " A:");
	for (int i = 0; i < 10; i++) {
		if (stack[0][i] == 10)
			printf("%d",10);
		if (stack[0][i] < 10 && stack[0][i]>0)
			printf( " %d" ,stack[0][i]);
		if (stack[0][i] == 0)
			printf( "  ");
	}
	printf( " ");


	printf( "B:");
	for (int i = 0; i < 10; i++) {
		if (stack[1][i] == 10)
			printf("%d", 10);
		if (stack[1][i] < 10 && stack[1][i]>0)
			printf(" %d", stack[1][i]);
		if (stack[1][i] == 0)
			printf( "  ");
	}
	printf( " ");


	printf( "C:");
	for (int i = 0; i < 10; i++) {
		if (stack[2][i] == 10)
			printf("%d", 10);
		if (stack[2][i] < 10 && stack[2][i]>0)
			printf(" %d", stack[2][i]);
		if (stack[2][i] == 0)
			printf( "  ");
	}
	printf( "\n");

}

void hanoi(int n, char src, char tmp, char dst)
{
	if (n == 1) {
		countt++;
		printf("第%4d 步( 1): %c-->%c", countt, src, dst);
		push(dst, pop(src));
		print_stack();
	}
	else if (n == 2) {
		countt++;
		printf("第%4d 步( 1): %c-->%c", countt, src, tmp);
		push(tmp, pop(src));
		print_stack();

		countt++;
		printf("第%4d 步( 2): %c-->%c", countt, src, dst);
		push(dst, pop(src));
		print_stack();

		countt++;
		printf("第%4d 步( 1): %c-->%c", countt, tmp, dst);
		push(dst, pop(tmp));
		print_stack();
	}
	else {
		hanoi(n - 1, src, dst, tmp);
		countt++;
		printf("第%4d 步(", countt);
		if (n < 10) {
			printf( " ");
		}
		printf("%d): %c-->%c", n , src,dst);
		push(dst, pop(src));
		print_stack();
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
	int ret;

	while (1) {
		printf("请输入汉诺塔的层数(1-10)：\n");
		ret = scanf("%d", &n);
		if (ret!=1) {
			while ((c = getchar()) != '\n' && c != EOF);
			continue;
		}
		else if (n < 1 || n>10) {
			while ((c = getchar()) != '\n' && c != EOF);
			continue;
		}
		else {
			while ((c = getchar()) != '\n' && c != EOF);
			break;
		}

	}

	while (1) {
		printf( "请输入起始柱(A-C)：\n");
		ret = scanf("%c", &src);
		if (ret!=1) {
			while ((c = getchar()) != '\n' && c != EOF);
			continue;
		}
		else if (src < 'A' || src>'C') {
			while ((c = getchar()) != '\n' && c != EOF);
			continue;
		}
		else {
			while ((c = getchar()) != '\n' && c != EOF);
			break;
		}
	}

	while (1) {
		printf( "请输入目标柱(A-C)：\n");
		ret = scanf("%c",&dst);
		if (ret!=1) {
			while ((c = getchar()) != '\n' && c != EOF);
			continue;
		}
		else if (dst < 'A' || dst>'C') {
			while ((c = getchar()) != '\n' && c != EOF);
			continue;
		}
		else {
			while ((c = getchar()) != '\n' && c != EOF);
			break;
		}
	}

	tmp = 3 * 'B' - src - dst;

	//初始化栈
	if (src == 'A') {
		for (int i = 0; i < n; i++) {
			stack[0][i] = n - i;
		}
		ABCpointer[0] = n;
	}
	if (src == 'B') {
		for (int i = 0; i < n; i++) {
			stack[1][i] = n - i;
		}
		ABCpointer[1] = n;
	}
	if (src == 'C') {
		for (int i = 0; i < n; i++) {
			stack[2][i] = n - i;
		}
		ABCpointer[2] = n;
	}

	printf( "初始:               ");
	print_stack();


	hanoi(n, src, tmp, dst);

}
