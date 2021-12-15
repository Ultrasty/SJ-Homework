#pragma once

#include <Winsock2.h>
//#include <Windows.h>		此句在本文件中无用，只是起注释作用：如果同时#include <Windows.h>，则必须把#include <Windows.h>放在后面，否则编译报错!!!
#include <string>
using namespace std;

#define SENDBUF_LEN		1024
#define RECVBUF_LEN		1024

#define	MIN_ROW_NUM		5
#define	MAX_ROW_NUM		8
#define	MIN_COL_NUM		5
#define	MAX_COL_NUM		10

class mto10_net_tools {
	protected:
		/* ---------------------------------------
		     所有 protected 下的东西都不需要看懂 
		   --------------------------------------- */
		SOCKET sockid;
		int    timerid;
		char sendbuf[SENDBUF_LEN];
		char recvbuf[RECVBUF_LEN];
		int  sendbuf_len;
		int  recvbuf_len;
		
		int  get_full_packet(string &pack);	//内部函数，从接收到的数据中取一个完整包（已实现）
		int  get_send_packet_len() const;		//内部函数，取一个完整包的长度（已实现）

		int  debug_switch;					//调试开关，设为true则打印错误提示信息，否则只返回，由调用者处理
		int  score;
		int  step;
		int  maxvalue;
		int  gameover_flag;

		int client_row, client_col, client_id, client_delay;
		int real_row, real_col, real_id, real_delay;
		int delay_count;
		char map[MAX_ROW_NUM * MAX_COL_NUM + 1];
		
		int get_string(const string& spack, const char* Type, const char* Wanted, char* value) const;
		int get_string(const string& spack, const char* Type, const char* Wanted, string &value) const;
		int get_int(const string& spack, const char* Type, const char* Wanted, int& value) const;

		int make_register_string(char* send_regstr, const char* no, const char connector, const char* password, const char* security_str); //用学号、密码、异或串生成要发送的加密认证串

		int create();							//创建网络id（已实现）
		int recv_from_server(string& spack);		//从Server中取数据（已实现）
		int send_to_server();					//将数据发送给Server（已实现）

		int get_security_string(string& s);					//从Server端发送来的数据中取40字节的异或加密串（已实现）
		int send_register_string(const char* reg_str);		//向Server端发送认证串（加密后的用户名和密码，已实现）

		int packet_dump(const char* prompt, const char* buffer, const int buflen) const; //将给定的字符串打印成hex格式（已实现）
		int connect(const char* ipaddr, const int port);
		friend void CALLBACK timeout(int uTimerID, int uMsg, int dwUser, int dw1, int dw2);
	public:
		/* ---------------------------------------
			 下面这四个函数不需要看懂
		   --------------------------------------- */
		mto10_net_tools();		//完成网络应用的初始化（已实现）
		~mto10_net_tools();		//完成网络应用退出时的收尾工作（已实现）
		int connect();			//向服务器发起连接（已实现）
		int close();				//关闭连接（已实现）

		/* ---------------------------------------
			 下面这些函数掌握调用方法即可
		   --------------------------------------- */
		/* 向服务器发送你的学号+密码信息 */
		int  send_parameter(const char* my_no, const char my_op, const char* my_pwd, const int row = 8, const int col = 8, const int id = -1, const int delay = 1000);
		int  send_coordinate(const char row, const int col);	//向Server端发送单坐标
		void set_debug_switch(bool on_off);					//打开debug开关（已实现，true则打开，会打印出错及提示信息，false则只返回，需要根据返回值判断错误）
		int  wait_for_game_start();					//等到服务器返回的游戏开始信息
		int  get_gameprogress_string(char* svrpack);	//从Server端取游戏反馈信息（从StartGame到GameOver）

		/* 取当前游戏的各种值 */
		int get_score() const;		//当前分数
		int get_step() const;			//当前步数
		int get_row() const;			//行数
		int get_col() const;			//列数
		int get_gameid() const;		//游戏ID
		int get_delay() const;		//每步延时
		int is_gameover() const;		//游戏是否结束
		const char *get_map() const;	//当前地图
		void print_map() const;		//将map转换为矩阵形式打印出来
};
