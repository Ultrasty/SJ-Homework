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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ���������������ο������������������Ĳ�����Ҳ�����Լ�ȫ���Ʒ���д
***************************************************************************/
int game_progress(mto10_net_tools &client)
{
	char svrpack[RECVBUF_LEN];	//��Ŵ�Server���յ�������
	char row;
	int col;

	while (1) {
		/* -------------------
			Client=>Server
		   ------------------- */
		/* ���ݷ���˷����ĵ�ͼ������һ�������꣨ĿǰΪ�ֹ�������ʽ����Ҫ��Ϊ�Զ�����ѽ����꣩
		   ��ʾ�����Խ�client.get_map()�ķ���ֵ���Ƶ��ַ������У��ٻ�ԭΪ���Լ��Ķ�ά��������
		*/
		client.print_map(); //��������Ϊʾ�⣬ͼ�ν����в��ܵ��ã�Ҫ�Լ�дת������

		/* ��Ϸ�ѽ������ٶ���*/
		if (client.is_gameover())
			break;

		cout << "��������(A-J)��(0-9)���� : ";
		cin >> row >> col; //�˴�δ�ж���ȷ�ԣ���Ҫ���д���

		/* ��պ����Ļ����� */
		cin.clear();
		cin.ignore(INT_MAX, '\n');

		if (row >= 'a' && row <= 'j')
			row -= 32; //�����Сд��תΪ��д

		client.send_coordinate(row, col);

		/* -------------------
			Server=>Client
		   ------------------- */
	   /* �ȴ�Server�˵�gameprogress */
		if (client.get_gameprogress_string(svrpack) < 0) {
			return -1;
		}

		/* ��ӡ�� svrpack �����ݣ����д�������Server�˼�������
		   ���� Content �����ݣ��������£�
			"InvalidCoordinate" : �Ƿ�����
				GameID		��������ϷID
				Step		��Ŀǰ����
				Score		��Ŀǰ����
				MaxValue	��Ŀǰ�ϳɵ����ֵ
			"MergeFailed" : ѡ���������Χ�޿ɺϳ���
				GameID		��������ϷID
				Step		��Ŀǰ����
				Score		��Ŀǰ����
				MaxValue	��Ŀǰ�ϳɵ����ֵ
			"MergeSucceeded" : ���κϳɳɹ�
				GameID		��������ϷID
				Step		��Ŀǰ����
				Score		��Ŀǰ����
				MaxValue	��Ŀǰ�ϳɵ����ֵ
				OldMap		������ѡ�������ĵ�ͼ
				NewMap		������ѡ��������ٴ����ĵ�ͼ
			"GameOver" : ��ͼ�����������Ϸ����
				GameID			��������ϷID
				FinalStep		�����ղ���
				FinalScore		�����շ���
				FinalMaxValue	�����պϳɵ����ֵ
			"GameFinished" : �Ѻϳɵ��������ޣ�16������Ϸ���
				GameID			��������ϷID
				FinalStep		�����ղ���
				FinalScore		�����շ���
				FinalMaxValue	�����պϳɵ����ֵ */

		/* ��ӡ�յ���ԭʼ�ַ��� */
		cout << "ServerӦ�� : " << endl << svrpack << endl;
	}//end of while(1)

	return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
	const char *my_no = "1234567";		//����ѧ��
	const char *my_pwd = "1234567";	//��������

	int wanted_row, wanted_col, wanted_id, wanted_delay;

#if 1 //�������룬�˴���Ϊ #if 0 ���ʾ�������� #else �е����
	wanted_row = 5;			//�˴������޸�Ϊ�����������ʽ
	wanted_col = 5;			//�˴������޸�Ϊ�����������ʽ
	wanted_id = 12345;		//idΪ�����������Ϸ��ţ������-1����ʾ���������������[0..2^31-1]���ʾ��̶���ţ���Ź̶�����ÿ�θ����ĳ�ʼ���󼰺���������ͬ��������ԣ�
	wanted_delay = 60 * 1000;	//delayΪ�����ÿ��Ӧ����ʱ�ӣ���λms
#else
	wanted_row = -1;
	wanted_col = -1;
	wanted_id = -1;
	wanted_delay = -1;
#endif
	mto10_net_tools client;

	/* ��client������е�debug���أ�����ʱ�ɴ򿪣���ͼ�ν���ʱ��رգ� */
	client.set_debug_switch(true);

	/* ���ӷ����� */
	if (client.connect() < 0) {
		/* ����ʧ����Ϣ����û��debug_switch����ӡ */
		cout << "���ӷ�����ʧ��!" << endl;
		return -1;
		}

	/* ��Server�˷�����֤��Ϣ������ */
	if (client.send_parameter(my_no, '*', my_pwd, wanted_row, wanted_col, wanted_id, wanted_delay) < 0) {
		cout << "������֤��������Ϣʧ��!" << endl;
		return -1;
		}

	/* �ȴ�Server���·���������Ϸ��ʼ��*/
	if (client.wait_for_game_start() < 0) {
		cout << "�ȴ�GameStartʧ��!" << endl;
		return -1;
		}

	/* ��ӡ�ӷ������յ��Ĳ�����������Ϸ�Դ˲���Ϊ׼����������6��6�У�����8��10�У��򱾴���Ϸ��8��10��Ϊ׼��
	   �����ӡ����Ϣ��ͼ�λ������������ȥ�� */
	cout << "������������Ϣ : " << endl;
	cout << "  ���� : " << client.get_row() << endl;
	cout << "  ���� : " << client.get_col() << endl;
	cout << "  ID�� : " << client.get_gameid() << endl;
	cout << "  ��ʱ : " << client.get_delay()/1000.0 << "(��)" << endl;
	cout << "  ��ͼ : " << client.get_map() << endl;
	/* ��ͼ���е�ֵΪ1-9��A-F���ֱ��ʾ1-15��ֵ��
		   ���磺
		     ������������=3
			 ������������=4
			 ���������ص�ͼ=123A85CF2123
		   ���ʾ��ǰ��ͼΪ(����������ʾ��)
		     1 2 3  10
			 8 5 12 15
			 2 1 2  3
			��Ϸ����������Ϊ���ϳɵ�16�����κοɺϳ�Ԫ�� */

	/* ������Ϸ��������
	   1���յ�Server��GameOver�򷵻�0����Ϸ����
	   2���������������-1��������Ϣ����ȷ�ȴ��󣩣��������ٴ��ظ�	*/
	if (game_progress(client) < 0) {
		client.close();
		return -1;
		}

	client.close();
	cout << "��Ϸ����" << endl;

	return 0;
}
