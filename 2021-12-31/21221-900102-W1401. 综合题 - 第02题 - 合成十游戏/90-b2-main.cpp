/* 1851521 软工 沈天宇 */
//主函数及菜单部分函数
#include"90-b2.h"
#include<iostream>
#include<conio.h>
using namespace std;

int display_menu()
{
	char ret;
	cct_cls();

	/*cct_setcolor(COLOR_BLACK, COLOR_YELLOW);
	cout << "【本程序某些地方未考虑输入输出错误处理，请小心输入！】" << endl;
	cout << "【程序中输入的字母全部为  ->小写<-  ！】" << endl;
	cout << "【若程序出现bug可以尝试重新启动本程序~】" << endl;
	cct_setcolor();*/
	cout << "---------------------------------------" << endl;
	cout << "1.命令行找出可合成项并标识（非递归）" << endl;
	cout << "2.命令行找出可合成项并标识（递归）" << endl;
	cout << "3.命令行完成一次合成（分步骤显示）" << endl;
	cout << "4.命令行完整版（分步骤显示）" << endl;
	cout << "5.伪图形界面显示初始数组（无分隔线）" << endl;
	cout << "6.伪图形界面显示初始数组（有分隔线）" << endl;
	cout << "7.伪图形界面下用箭头键/鼠标选择当前色块" << endl;
	cout << "8.伪图形界面完成一次合成（分步骤）" << endl;
	cout << "9.伪图形界面完整版(支持鼠标)" << endl;
	cout << "---------------------------------------" << endl;
	cout << "0.退出" << endl;
	cout << "---------------------------------------" << endl;
	cout << "[请选择:] ";

	while (1) {
		ret = _getche();
		if (ret >= '0' && ret <= '9') {
			break;
		}
		else
			cout << "\b \b";
	}


	cout << endl << endl << endl;

	if (ret == '0') {
		return -1;
	}
	else {
		return ret - '0';
	}

	return 0;
}

int main()
{

	/* demo中首先执行此句，将cmd窗口设置为40行x120列（缓冲区宽度120列，行数9000行，即cmd窗口右侧带有垂直滚动杆）*/
	cct_setconsoleborder(120, 40, 120, 9000);
	while (1) {
		int ret = display_menu();
		if (ret == -1)
			break;
		play(ret);
	}

}