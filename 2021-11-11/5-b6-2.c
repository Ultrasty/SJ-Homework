/* 1851521 ������ �� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>



int countt = 0;
int stack[3][10] = { { 0,0,0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0,0,0 } };
int ABCpointer[] = { 0,0,0 };
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

   /**
	 push���� ����˼��
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
		printf("��%4d ��( 1): %c-->%c", countt, src, dst);
		push(dst, pop(src));
		print_stack();
	}
	else if (n == 2) {
		countt++;
		printf("��%4d ��( 1): %c-->%c", countt, src, tmp);
		push(tmp, pop(src));
		print_stack();

		countt++;
		printf("��%4d ��( 2): %c-->%c", countt, src, dst);
		push(dst, pop(src));
		print_stack();

		countt++;
		printf("��%4d ��( 1): %c-->%c", countt, tmp, dst);
		push(dst, pop(tmp));
		print_stack();
	}
	else {
		hanoi(n - 1, src, dst, tmp);
		countt++;
		printf("��%4d ��(", countt);
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
	int ret;

	while (1) {
		printf("�����뺺ŵ���Ĳ���(1-10)��\n");
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
		printf( "��������ʼ��(A-C)��\n");
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
		printf( "������Ŀ����(A-C)��\n");
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

	//��ʼ��ջ
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

	printf( "��ʼ:               ");
	print_stack();


	hanoi(n, src, tmp, dst);

}
