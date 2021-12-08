/* �� 1851521 ������ */
#include"hanoi.h"

/* ----------------------------------------------------------------------------------

	 ���ļ����ܣ�
	1����ű� hanoi_main.cpp �и��ݲ˵�����ֵ���õĸ��˵����Ӧ��ִ�к���

	 ���ļ�Ҫ��
	1�����������ⲿȫ�ֱ�����const��#define�������Ʒ�Χ�ڣ�
	2�������徲̬ȫ�ֱ�����������Ҫ��������Ҫ�����ĵ���ʾ��ȫ�ֱ�����ʹ��׼���ǣ����á����á��ܲ��þ������ã�
	3����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
	4���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------------------------------------------------- */

static int countt = 0;
static int stackA[] = { 0,0,0,0,0,0,0,0,0,0 };
static int stackB[] = { 0,0,0,0,0,0,0,0,0,0 };
static int stackC[] = { 0,0,0,0,0,0,0,0,0,0 };
static int A = 0, B = 0, C = 0;
static int delay;

void draw_column()
{
	cct_showch(0, 15, ' ', COLOR_YELLOW, COLOR_YELLOW, 25);
	cct_showch(45, 15, ' ', COLOR_YELLOW, COLOR_YELLOW, 25);
	cct_showch(90, 15, ' ', COLOR_YELLOW, COLOR_YELLOW, 25);

	for (int i = 0; i < 3; i++) {
		for (int j = 14; j >= 5; j--) {
			cct_showch(i*45 + 12 , j, ' ', COLOR_YELLOW, COLOR_YELLOW, 1);
			Sleep(20);
		}
	}
}

//����ȫ�ֱ���
void clear_global()
{
	countt = 0;

	for (int i = 0; i < 10; i++) {
		stackA[i] = 0;
		stackB[i] = 0;
		stackC[i] = 0;
	}

	A = 0;
	B = 0;
	C = 0;
}

//��ʱ
void delay_sometime()
{
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

//����
void get_input(int* n, char* src, char* tmp, char* dst, int* display_stack, char choice)
{

	char c;
	while (1) {
		cout << "�����뺺ŵ���Ĳ���(1-10)��" << endl;
		cin >> *n;

		if (cin.fail()) {
			cin.clear();
			while ((c = getchar()) != '\n' && c != EOF)
				;
			continue;
		}
		else if (*n < 1 || *n>10) {
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
		cin >> *src;

		//תΪ��д
		if (*src == 'a' || *src == 'b' || *src == 'c') {
			*src -= 0x20;
		}

		if (cin.fail()) {
			cin.clear();
			while ((c = getchar()) != '\n' && c != EOF)
				;
			continue;
		}
		else if (*src < 'A' || *src>'C') {
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
		cin >> *dst;

		//תΪ��д
		if (*dst == 'a' || *dst == 'b' || *dst == 'c') {
			*dst -= 0x20;
		}

		if (cin.fail()) {
			cin.clear();
			while ((c = getchar()) != '\n' && c != EOF)
				;
			continue;
		}
		else if (*dst < 'A' || *dst>'C') {
			while ((c = getchar()) != '\n' && c != EOF)
				;
			continue;
		}
		else if (*dst == *src) {
			cout << "Ŀ����(" << *dst << ")��������ʼ��(" << *src << ")��ͬ" << endl;
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


	//��������� �ò�������
	if (choice == '4') {
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
			cin >> *display_stack;
			if (cin.fail()) {
				cin.clear();
				while ((c = getchar()) != '\n' && c != EOF)
					;
				continue;
			}
			else if (*display_stack < 0 || *display_stack > 1) {
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
	}
	

	*tmp = 3 * 'B' - *src - *dst;

	//��ʼ��ջ
	if (*src == 'A') {
		for (int i = 0; i < *n; i++) {
			stackA[i] = *n - i;
		}
		A = *n;
	}
	if (*src == 'B') {
		for (int i = 0; i < *n; i++) {
			stackB[i] = *n - i;
		}
		B = *n;
	}
	if (*src == 'C') {
		for (int i = 0; i < *n; i++) {
			stackC[i] = *n - i;
		}
		C = *n;
	}
}

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

//�����ӡstack��������
void print_stack(char choice)
{
	cct_setcolor();

	if (choice == '4') {
		cct_gotoxy(20, 17);
	}

	if (choice == '8' || choice =='7' || choice == '9') {
		cct_gotoxy(20, 32);
	}
	
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
	if (choice == '4') {
		delay_sometime();
	}
	
}

//��ӡ�ڼ���
void print_step(int n, char src, char dst,char choice)
{
	cct_setcolor();

	if (choice == '4') {
		cct_gotoxy(0, 17);
	}

	if (choice == '8' || choice =='7' || choice == '9') {
		cct_gotoxy(0, 32);
	}
	
	cout << "��" << setfill(' ') << setw(4) << countt << " ��(";
	if (n < 10) {
		cout << " ";
	}
	cout << n << "): " << src << "-->" << dst;
	push(dst, pop(src));
}

//�����ӡstack��������
void print_stack_vertical(char choice)
{
	cct_setcolor();

	int x = 11;
	int y = 11;

	if (choice == '8' || choice =='7' || choice == '9') {
		y += 15;
	}

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
	delay_sometime();
}


void horizontal_move(int n, char src, char tmp, char dst, char way)
{
	int stack_pointer[] = { A,B,C };
	int start_x, start_y = 4;
	int end_x;
	
	start_x = (src - 'A') * 45 + 12;
	end_x = (dst - 'A') * 45 + 12;

	int i = start_x;
	int direction = dst - src > 0 ? 1 : -1;
	Sleep(10);
	while (1) {
		cct_showch(i - n, start_y, ' ', n, n, 2 * n + 1);
		Sleep(10);
		if (i != end_x) {
			cct_showch(i - n, start_y, ' ', COLOR_BLACK, COLOR_WHITE, 2 * n + 1);
			cct_showch(i, start_y, ' ', COLOR_YELLOW, COLOR_WHITE, 1);
		}
		if (i == end_x) {
			break;
		}
		i += direction;
	}
}

void vertical_move(int n, char src, char tmp, char dst, char way ,int up)
{
	int stack_pointer[] = { A,B,C };
	int start_x, start_y;
	int end_y, end_x;

	Sleep(30);
	if (up == 1) {
		start_x = (src - 'A') * 45 + 12;
		start_y = 14 - stack_pointer[src - 'A'];
		end_y = 4;

		for (int i = start_y; i >= end_y; i--) {
			cct_showch(start_x - n, i, ' ', n, n, 2 * n + 1);
			Sleep(30);
			if (i > end_y) {
				cct_showch(start_x - n, i, ' ', COLOR_BLACK, COLOR_WHITE, 2 * n + 1);
				if (i != 4) {
					cct_showch(start_x, i, ' ', COLOR_YELLOW, COLOR_WHITE, 1);
				}
				
			}
		}
	}
	
	if (up == 0) {
		end_x = (dst - 'A') * 45 + 12;
		start_y = 4;
		end_y = 15 - stack_pointer[dst - 'A'];

		for (int i = start_y; i <= end_y; i++) {
			cct_showch(end_x - n, i, ' ', n, n, 2 * n + 1);
			Sleep(30);
			if (i < end_y) {
				cct_showch(end_x - n, i, ' ', COLOR_BLACK, COLOR_WHITE, 2 * n + 1);
				if (i != 4) {
					cct_showch(end_x, i, ' ', COLOR_YELLOW, COLOR_WHITE, 1);
				}
				
			}
		}

	}
}

//�ƶ�
void move(int n, char src, char tmp, char dst, int display_stack, char way)
{
	countt++;
	if (way == '1') {
		cout << n << "# " << src << "---->" << dst << endl;
	}
	if (way == '2') {
		cout << "��" << setfill(' ') << setw(4) << countt << " ��(" << setw(2) << n << "#: " << src << "-->" << dst << ")" << endl;
	}
	if (way == '3') {
		print_step(n, src, dst, way);
		print_stack(way);
	}
	if (way == '4') {
		print_step(n, src, dst, way);
		if (display_stack)
			print_stack(way);
		print_stack_vertical(way);
	}
	if (way == '8' || way == '7' || way =='9') {

		print_step(n, src, dst, way);
		if (display_stack)
			print_stack(way);
		print_stack_vertical(way);

		vertical_move(n, src, tmp, dst, way, 1);
		horizontal_move(n, src, tmp, dst, way);
		vertical_move(n, src, tmp, dst, way, 0);
		
	}
}

//ֻ����һ���ݹ麯��
void hanoi(int n, char src, char tmp, char dst, int display_stack, char way)
{
	if (n == 1) {
		move(n, src, tmp, dst, display_stack, way);
	}
	else {
		hanoi(n - 1, src, dst, tmp, display_stack, way);
		if (way == '7') {
			return;
		}
		move(n, src, tmp, dst, display_stack, way);
		hanoi(n - 1, tmp, src, dst, display_stack, way);
	}
}

void draw_initial_plate(int n,char src)
{
	for (int i = n; i >= 1; i--) {
		delay = 5;
		delay_sometime();
		cct_showch((src - 'A') * 45 + 12 - i, 14 - (n - i), ' ', i, i, 2 * i + 1);
	}
}

//��main���ã�������choice
void play(char choice)
{
	int n;
	char src, tmp, dst;
	int display_stack;

	clear_global();

	if (choice != '5') {
		get_input(&n, &src, &tmp, &dst, &display_stack, choice);
	}
	
	if (choice == '1' || choice == '2' || choice == '3') {
		hanoi(n, src, tmp, dst, display_stack, choice);
	}

	if (choice == '4') {
		cct_cls();
		cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " �㣬��ʱ����Ϊ " << delay << "��" << (display_stack ? "" : "��") << "��ʾ�ڲ�����ֵ" << endl;
		cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
		cout << "         =========================" << endl;
		cout << "           A         B         C" << endl;
		cout << endl << endl << endl;

		cct_gotoxy(0, 17);


		if (display_stack) {
			cout << "��ʼ:                ";
			print_stack(choice);
		}

		print_stack_vertical(choice);
		hanoi(n, src, tmp, dst, display_stack, choice);
	}

	if (choice == '5') {
		cct_cls();
		draw_column();
		cct_gotoxy(0, 30);
	}

	if (choice == '6') {
		cct_cls();
		draw_column();

		draw_initial_plate(n,src);
		cct_gotoxy(0, 30);
	}

	if (choice == '8' || choice == '7') {
		cct_cls();
		draw_column();

		cct_gotoxy(0, 27);
		cct_setcolor();
		cout << "         =========================" << endl;
		cout << "           A         B         C" << endl;

		draw_initial_plate(n, src);

		hanoi(n, src, tmp, dst, 1, choice);
		cct_gotoxy(0, 37);
	}

	if (choice == '9') {
		cct_cls();
		draw_column();

		cct_gotoxy(0, 27);
		cct_setcolor();
		cout << "         =========================" << endl;
		cout << "           A         B         C" << endl;

		draw_initial_plate(n, src);
		print_stack_vertical(choice);



		char temp[1000];

		while (1) {
			cct_gotoxy(0, 35);
			cct_setcolor();
			cout << "�������ƶ�������(������ʽ��AC=A���˵������ƶ���C��Q=�˳�) ��                 ";

			int current_n = INT_MAX;
			int to_n = INT_MAX;
			cct_gotoxy(60, 35);
			cin.getline(temp, 1000);
			if (temp[0] == 'q' || temp[0] == 'Q') {
				break;
			}
			if (temp[0] >= 'a' && temp[0] <= 'c') {
				temp[0] -= 0x20;
			}
			if (temp[1] >= 'a' && temp[1] <= 'c') {
				temp[1] -= 0x20;
			}
			if (temp[0] >= 'A' && temp[0] <= 'C' && temp[1] >= 'A' && temp[1] <= 'C') {

				if (temp[0] == 'A' && A > 0) {
					current_n = stackA[A - 1];
				}
				else if (temp[0] == 'B' && B > 0) {
					current_n = stackB[B - 1];
				}
				else if (temp[0] == 'C' && C > 0) {
					current_n = stackC[C - 1];
				}
				else {
					cct_gotoxy(0, 36);
					cct_setcolor();
					cout << "�Ƿ��ƶ�����ʼ��Ϊ�գ�       ";
					continue;
				}

				if (temp[1] == 'A' && A > 0) {
					to_n = stackA[A - 1];
				}
				if (temp[1] == 'B' && B > 0) {
					to_n = stackB[B - 1];
				}
				if (temp[1] == 'C' && C > 0) {
					to_n = stackC[C - 1];
				}
				
				if (to_n < current_n) {
					cct_gotoxy(0, 36);
					cct_setcolor();
					cout << "�Ƿ��ƶ�������ѹС�̣�        ";
					continue;
				}
				else {
					cct_gotoxy(0, 36);
					cct_setcolor();
					cout << "                                                      ";
					move(current_n, temp[0], tmp, temp[1], display_stack, choice);
				}
				
			}
			
			
			
		}

	}

	cct_setcolor();
	cout << endl;
	system("pause");
}