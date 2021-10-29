/* 1851521 沈天宇 软工 */
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

const int MAX_X = 69;	//定义*组成的边框的宽度
const int MAX_Y = 17;	//定义*组成的边框的高度

/***************************************************************************
  函数名称：
  功    能：完成与system("cls")一样的功能，但效率高
  输入参数：
  返 回 值：
  说    明：清除整个屏幕缓冲区，不仅仅是可见窗口区域(使用当前颜色)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* 取当前缓冲区信息 */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* 填充字符 */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* 填充属性 */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* 光标回到(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  函数名称：gotoxy
  功    能：将光标移动到指定位置
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  函数名称：showch
  功    能：在指定位置处打印一个指定的字符
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
			char ch     ：要打印的字符
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  函数名称：init_border
  功    能：显示初始的边框及随机字符
  输入参数：HANDLE hout：输出设备句柄
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//光标移回左上角(0,0)
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

	/* 随机显示20个大写字母，字母的值、XY坐标都随机显示
	   rand()函数的功能：随机生成一个在 0-32767 之间的整数
	   思考：在什么情况下，下面这个循环执行生成后，你看到的实际字母个数不足20个？ */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- 按需增加的若干函数可以放在此处 --*/
int menu() {
	char ch;
	int choose;
	ch = _getch();
	if (ch == '0')
		return 0;
	choose = ch - '1' + 1;
	return choose;
}

//合并成一个函数
void move_by_ijkl_or_arrow(int choose, int x, int y, HANDLE hout) {

	while (1) {
		//方向or操作
		int direction;
		direction = _getch();
		//消除
		if (direction == 32)
			putchar(32);

		if (direction == 'q' || direction == 'Q') {
			gotoxy(hout, 0, 23);
			printf("游戏结束，按回车键退出.\n");
			while (1) {
				direction = _getch();
				if (direction == 13)
					break;
			}
			break;
		}

		//控制方向,1,2,5,6使用
		if (choose == 1 || choose == 2 || choose == 5 || choose == 6) {

			/*********下面5行代码完成加分**********/
			if (choose == 5 || choose == 6) {     //
				if (direction == 224) {           //
					_getch();                     //
				}                                 //
			}                                     //
			/*********上面5行代码完成加分**********/

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
		//控制方向,3,4使用
		if (choose == 3 || choose == 4) {
			if (direction == 224) {
				direction = _getch();
				//左
				if (direction == 75) {
					if (x == 1) {
						if (choose == 2 || choose == 4 || choose == 6)
							x = 69;
					}
					else
						x = x - 1;
				}
				//下
				if (direction == 80) {
					if (y == 17) {
						if (choose == 2 || choose == 4 || choose == 6)
							y = 1;
					}
					else
						y = y + 1;
				}
				//右
				if (direction == 77) {
					if (x == 69) {
						if (choose == 2 || choose == 4 || choose == 6)
							x = 1;
					}
					else
						x = x + 1;
				}
				//上
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
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数仅用于初始演示，可以按题目要求全部推翻重写
***************************************************************************/
int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄

	/* 生成伪随机数的种子，只需在程序开始时执行一次即可 */
	srand((unsigned int)(time(0)));




	while (1) {

		/* 此句的作用是调用系统的cls命令清屏 */
		cls(hout);

		printf("1.用I、J、K、L键控制上下左右(大小写均可，边界停止)（允许按左箭头键时向下移动）\n");
		printf("2.用I、J、K、L键控制上下左右(大小写均可，边界回绕)（允许按左箭头键时向下移动）\n");
		printf("3.用箭头键控制上下左右，边界停止（按大写HPKM时不准移动）\n");
		printf("4.用箭头键控制上下左右，边界回绕（按大写HPKM时不准移动）\n");
		printf("5.用I、J、K、L键控制上下左右(大小写均可，边界停止)（按左箭头键不准向下移动）\n");
		printf("6.用I、J、K、L键控制上下左右(大小写均可，边界回绕)（按左箭头键不准向下移动）\n");
		printf("0.退出\n");
		printf("[请选择0 - 6]\n");

		//ch和choose是联动的,ch是读入菜单字符,choose是选项的数字

		int choose;


		//coord
		int x, y;


		choose = menu();

		if (choose == 0) {
			return 0;
		}

		if (choose >= 1 && choose <= 6) {
			cls(hout);
			/* 显示初始的边框及其中的随机字符 */
			init_border(hout);
			x = 35;
			y = 9;
			gotoxy(hout, x, y);

			//移动
			move_by_ijkl_or_arrow(choose, x, y, hout);

		}

	}


	return 0;
}
