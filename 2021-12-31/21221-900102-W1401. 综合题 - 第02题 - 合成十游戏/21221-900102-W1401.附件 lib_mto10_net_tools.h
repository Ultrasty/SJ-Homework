#pragma once

#include <Winsock2.h>
//#include <Windows.h>		�˾��ڱ��ļ������ã�ֻ����ע�����ã����ͬʱ#include <Windows.h>��������#include <Windows.h>���ں��棬������뱨��!!!
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
		     ���� protected �µĶ���������Ҫ���� 
		   --------------------------------------- */
		SOCKET sockid;
		int    timerid;
		char sendbuf[SENDBUF_LEN];
		char recvbuf[RECVBUF_LEN];
		int  sendbuf_len;
		int  recvbuf_len;
		
		int  get_full_packet(string &pack);	//�ڲ��������ӽ��յ���������ȡһ������������ʵ�֣�
		int  get_send_packet_len() const;		//�ڲ�������ȡһ���������ĳ��ȣ���ʵ�֣�

		int  debug_switch;					//���Կ��أ���Ϊtrue���ӡ������ʾ��Ϣ������ֻ���أ��ɵ����ߴ���
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

		int make_register_string(char* send_regstr, const char* no, const char connector, const char* password, const char* security_str); //��ѧ�š����롢�������Ҫ���͵ļ�����֤��

		int create();							//��������id����ʵ�֣�
		int recv_from_server(string& spack);		//��Server��ȡ���ݣ���ʵ�֣�
		int send_to_server();					//�����ݷ��͸�Server����ʵ�֣�

		int get_security_string(string& s);					//��Server�˷�������������ȡ40�ֽڵ������ܴ�����ʵ�֣�
		int send_register_string(const char* reg_str);		//��Server�˷�����֤�������ܺ���û��������룬��ʵ�֣�

		int packet_dump(const char* prompt, const char* buffer, const int buflen) const; //���������ַ�����ӡ��hex��ʽ����ʵ�֣�
		int connect(const char* ipaddr, const int port);
		friend void CALLBACK timeout(int uTimerID, int uMsg, int dwUser, int dw1, int dw2);
	public:
		/* ---------------------------------------
			 �������ĸ���������Ҫ����
		   --------------------------------------- */
		mto10_net_tools();		//�������Ӧ�õĳ�ʼ������ʵ�֣�
		~mto10_net_tools();		//�������Ӧ���˳�ʱ����β��������ʵ�֣�
		int connect();			//��������������ӣ���ʵ�֣�
		int close();				//�ر����ӣ���ʵ�֣�

		/* ---------------------------------------
			 ������Щ�������յ��÷�������
		   --------------------------------------- */
		/* ��������������ѧ��+������Ϣ */
		int  send_parameter(const char* my_no, const char my_op, const char* my_pwd, const int row = 8, const int col = 8, const int id = -1, const int delay = 1000);
		int  send_coordinate(const char row, const int col);	//��Server�˷��͵�����
		void set_debug_switch(bool on_off);					//��debug���أ���ʵ�֣�true��򿪣����ӡ������ʾ��Ϣ��false��ֻ���أ���Ҫ���ݷ���ֵ�жϴ���
		int  wait_for_game_start();					//�ȵ����������ص���Ϸ��ʼ��Ϣ
		int  get_gameprogress_string(char* svrpack);	//��Server��ȡ��Ϸ������Ϣ����StartGame��GameOver��

		/* ȡ��ǰ��Ϸ�ĸ���ֵ */
		int get_score() const;		//��ǰ����
		int get_step() const;			//��ǰ����
		int get_row() const;			//����
		int get_col() const;			//����
		int get_gameid() const;		//��ϷID
		int get_delay() const;		//ÿ����ʱ
		int is_gameover() const;		//��Ϸ�Ƿ����
		const char *get_map() const;	//��ǰ��ͼ
		void print_map() const;		//��mapת��Ϊ������ʽ��ӡ����
};
