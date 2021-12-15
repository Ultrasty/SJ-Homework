#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>
#include "lib_mto10_net_tools.h"
using namespace std;

#define		MAX_ROW_NUM		8
#define		MAX_COL_NUM		10
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：本函数仅供参考，允许增减本函数的参数，也可以自己全部推翻重写
***************************************************************************/
int game_progress(mto10_net_tools &client)
{
	char svrpack[RECVBUF_LEN];	//存放从Server端收到的数据
	char row;
	int col;

	while (1) {
		/* -------------------
			Client=>Server
		   ------------------- */
		/* 根据服务端发来的地图，返回一个解坐标（目前为手工输入形式，需要改为自动求最佳解坐标）
		   提示：可以将client.get_map()的返回值复制到字符数组中，再还原为你自己的二维数组后求解
		*/
		client.print_map(); //本函数仅为示意，图形界面中不能调用，要自己写转换函数

		/* 游戏已结束则不再读键*/
		if (client.is_gameover())
			break;

		cout << "请输入行(A-J)列(0-9)坐标 : ";
		cin >> row >> col; //此处未判断正确性，需要自行处理

		/* 清空后续的缓冲区 */
		cin.clear();
		cin.ignore(INT_MAX, '\n');

		if (row >= 'a' && row <= 'j')
			row -= 32; //如果是小写则转为大写

		client.send_coordinate(row, col);

		/* -------------------
			Server=>Client
		   ------------------- */
	   /* 等待Server端的gameprogress */
		if (client.get_gameprogress_string(svrpack) < 0) {
			return -1;
		}

		/* 打印出 svrpack 的内容，自行处理，并向Server端继续反馈
		   根据 Content 的内容，解释如下：
			"InvalidCoordinate" : 非法坐标
				GameID		：本次游戏ID
				Step		：目前步数
				Score		：目前分数
				MaxValue	：目前合成的最大值
			"MergeFailed" : 选择的坐标周围无可合成项
				GameID		：本次游戏ID
				Step		：目前步数
				Score		：目前分数
				MaxValue	：目前合成的最大值
			"MergeSucceeded" : 本次合成成功
				GameID		：本次游戏ID
				Step		：目前步数
				Score		：目前分数
				MaxValue	：目前合成的最大值
				OldMap		：消除选择坐标后的地图
				NewMap		：消除选择坐标后再次填充的地图
			"GameOver" : 地图上无消除项，游戏结束
				GameID			：本次游戏ID
				FinalStep		：最终步数
				FinalScore		：最终分数
				FinalMaxValue	：最终合成的最大值
			"GameFinished" : 已合成到设置上限（16），游戏完成
				GameID			：本次游戏ID
				FinalStep		：最终步数
				FinalScore		：最终分数
				FinalMaxValue	：最终合成的最大值 */

		/* 打印收到的原始字符串 */
		cout << "Server应答 : " << endl << svrpack << endl;
	}//end of while(1)

	return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	const char *my_no = "1234567";		//本人学号
	const char *my_pwd = "1234567";	//本人密码

	int wanted_row, wanted_col, wanted_id, wanted_delay;

#if 1 //条件编译，此处改为 #if 0 则表示启用下面 #else 中的语句
	wanted_row = 5;			//此处按需修改为键盘输入等形式
	wanted_col = 5;			//此处按需修改为键盘输入等形式
	wanted_id = 12345;		//id为本次请求的游戏序号，如果置-1，表示服务器随机产生，[0..2^31-1]则表示想固定序号（序号固定，则每次给出的初始矩阵及后续填充均相同，方便调试）
	wanted_delay = 60 * 1000;	//delay为请求的每步应答的最长时延，单位ms
#else
	wanted_row = -1;
	wanted_col = -1;
	wanted_id = -1;
	wanted_delay = -1;
#endif
	mto10_net_tools client;

	/* 打开client类对象中的debug开关（调试时可打开，到图形界面时需关闭） */
	client.set_debug_switch(true);

	/* 连接服务器 */
	if (client.connect() < 0) {
		/* 连接失败信息，有没有debug_switch都打印 */
		cout << "连接服务器失败!" << endl;
		return -1;
		}

	/* 向Server端发送认证信息及参数 */
	if (client.send_parameter(my_no, '*', my_pwd, wanted_row, wanted_col, wanted_id, wanted_delay) < 0) {
		cout << "发送认证及参数信息失败!" << endl;
		return -1;
		}

	/* 等待Server端下发参数（游戏开始）*/
	if (client.wait_for_game_start() < 0) {
		cout << "等待GameStart失败!" << endl;
		return -1;
		}

	/* 打印从服务器收到的参数，本次游戏以此参数为准（例：发送6行6列，返回8行10列，则本次游戏以8行10列为准）
	   下面打印的信息，图形化界面可以自行去除 */
	cout << "服务器返回信息 : " << endl;
	cout << "  行数 : " << client.get_row() << endl;
	cout << "  列数 : " << client.get_col() << endl;
	cout << "  ID号 : " << client.get_gameid() << endl;
	cout << "  超时 : " << client.get_delay()/1000.0 << "(秒)" << endl;
	cout << "  地图 : " << client.get_map() << endl;
	/* 地图串中的值为1-9，A-F，分别表示1-15的值，
		   例如：
		     服务器返回行=3
			 服务器返回列=4
			 服务器返回地图=123A85CF2123
		   则表示当前地图为(本例仅仅是示例)
		     1 2 3  10
			 8 5 12 15
			 2 1 2  3
			游戏结束的条件为：合成到16或无任何可合成元素 */

	/* 进入游戏交互环节
	   1、收到Server的GameOver则返回0，游戏结束
	   2、其它错误均返回-1（报文信息不正确等错误），重连，再次重复	*/
	if (game_progress(client) < 0) {
		client.close();
		return -1;
		}

	client.close();
	cout << "游戏结束" << endl;

	return 0;
}
