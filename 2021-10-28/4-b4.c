/* 1851521 ������ �� */
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

const int MAX_X = 69;	//����*��ɵı߿�Ŀ��
const int MAX_Y = 17;	//����*��ɵı߿�ĸ߶�

/***************************************************************************
  �������ƣ�
  ��    �ܣ������system("cls")һ���Ĺ��ܣ���Ч�ʸ�
  ���������
  �� �� ֵ��
  ˵    �������������Ļ���������������ǿɼ���������(ʹ�õ�ǰ��ɫ)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* ȡ��ǰ��������Ϣ */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* ����ַ� */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* ������� */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* ���ص�(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  �������ƣ�gotoxy
  ��    �ܣ�������ƶ���ָ��λ��
  ���������HANDLE hout ������豸���
			int X       ��ָ��λ�õ�x����
			int Y       ��ָ��λ�õ�y����
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  �������ƣ�showch
  ��    �ܣ���ָ��λ�ô���ӡһ��ָ�����ַ�
  ���������HANDLE hout ������豸���
			int X       ��ָ��λ�õ�x����
			int Y       ��ָ��λ�õ�y����
			char ch     ��Ҫ��ӡ���ַ�
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  �������ƣ�init_border
  ��    �ܣ���ʾ��ʼ�ı߿�����ַ�
  ���������HANDLE hout������豸���
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//����ƻ����Ͻ�(0,0)
	printf("***********************************************************************\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("***********************************************************************\n");

	/* �����ʾ20����д��ĸ����ĸ��ֵ��XY���궼�����ʾ
	   rand()�����Ĺ��ܣ��������һ���� 0-32767 ֮�������
	   ˼������ʲô����£��������ѭ��ִ�����ɺ��㿴����ʵ����ĸ��������20���� */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- �������ӵ����ɺ������Է��ڴ˴� --*/
int menu() {
	char ch;
	int choose;
	ch = _getch();
	if (ch == '0')
		return 0;
	choose = ch - '1' + 1;
	return choose;
}

//�ϲ���һ������
void move_by_ijkl_or_arrow(int choose, int x, int y, HANDLE hout) {

	while (1) {
		//����or����
		int direction;
		direction = _getch();
		//����
		if (direction == 32)
			putchar(32);

		if (direction == 'q' || direction == 'Q') {
			gotoxy(hout, 0, 23);
			printf("��Ϸ���������س����˳�.\n");
			while (1) {
				direction = _getch();
				if (direction == 13)
					break;
			}
			break;
		}

		//���Ʒ���,1,2,5,6ʹ��
		if (choose == 1 || choose == 2 || choose == 5 || choose == 6) {

			/*********����5�д�����ɼӷ�**********/
			if (choose == 5 || choose == 6) {     //
				if (direction == 224) {           //
					_getch();                     //
				}                                 //
			}                                     //
			/*********����5�д�����ɼӷ�**********/

			if (direction == 'j' || direction == 'J') {
				if (x == 1) {
					if (choose == 2 || choose == 4 || choose == 6)
						x = 69;
				}
				else
					x = x - 1;
			}
			if (direction == 'k' || direction == 'K') {
				if (y == 17) {
					if (choose == 2 || choose == 4 || choose == 6)
						y = 1;
				}
				else
					y = y + 1;
			}
			if (direction == 'l' || direction == 'L') {
				if (x == 69) {
					if (choose == 2 || choose == 4 || choose == 6)
						x = 1;
				}
				else
					x = x + 1;
			}
			if (direction == 'i' || direction == 'I') {
				if (y == 1) {
					if (choose == 2 || choose == 4 || choose == 6)
						y = 17;
				}
				else
					y = y - 1;
			}
		}
		//���Ʒ���,3,4ʹ��
		if (choose == 3 || choose == 4) {
			if (direction == 224) {
				direction = _getch();
				//��
				if (direction == 75) {
					if (x == 1) {
						if (choose == 2 || choose == 4 || choose == 6)
							x = 69;
					}
					else
						x = x - 1;
				}
				//��
				if (direction == 80) {
					if (y == 17) {
						if (choose == 2 || choose == 4 || choose == 6)
							y = 1;
					}
					else
						y = y + 1;
				}
				//��
				if (direction == 77) {
					if (x == 69) {
						if (choose == 2 || choose == 4 || choose == 6)
							x = 1;
					}
					else
						x = x + 1;
				}
				//��
				if (direction == 72) {
					if (y == 1) {
						if (choose == 2 || choose == 4 || choose == 6)
							y = 17;
					}
					else
						y = y - 1;
				}
			}
		}

		gotoxy(hout, x, y);
	}
}


/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main���������ڳ�ʼ��ʾ�����԰���ĿҪ��ȫ���Ʒ���д
***************************************************************************/
int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��

	/* ����α����������ӣ�ֻ���ڳ���ʼʱִ��һ�μ��� */
	srand((unsigned int)(time(0)));




	while (1) {

		/* �˾�������ǵ���ϵͳ��cls�������� */
		cls(hout);

		printf("1.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)���������ͷ��ʱ�����ƶ���\n");
		printf("2.��I��J��K��L��������������(��Сд���ɣ��߽����)���������ͷ��ʱ�����ƶ���\n");
		printf("3.�ü�ͷ�������������ң��߽�ֹͣ������дHPKMʱ��׼�ƶ���\n");
		printf("4.�ü�ͷ�������������ң��߽���ƣ�����дHPKMʱ��׼�ƶ���\n");
		printf("5.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)�������ͷ����׼�����ƶ���\n");
		printf("6.��I��J��K��L��������������(��Сд���ɣ��߽����)�������ͷ����׼�����ƶ���\n");
		printf("0.�˳�\n");
		printf("[��ѡ��0 - 6]\n");

		//ch��choose��������,ch�Ƕ���˵��ַ�,choose��ѡ�������

		int choose;


		//coord
		int x, y;


		choose = menu();

		if (choose == 0) {
			return 0;
		}

		if (choose >= 1 && choose <= 6) {
			cls(hout);
			/* ��ʾ��ʼ�ı߿����е�����ַ� */
			init_border(hout);
			x = 35;
			y = 9;
			gotoxy(hout, x, y);

			//�ƶ�
			move_by_ijkl_or_arrow(choose, x, y, hout);

		}

	}


	return 0;
}
