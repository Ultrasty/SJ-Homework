/* 1851521 ������ �� */
#include <iostream>
#include <iomanip>
using namespace std;

/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2����������ȫ�ֱ�������̬�ֲ�������ȫ��ֻ��������궨�岻�ܴ����ƣ�
   3�������������������
   ---------------------------------------------------------------------
*/

#define N	10

struct course {
	float value;	//ĳ�γ̵ĳɼ����ٷ��ƣ�
	float weight;	//ĳ�γ̵�ѧ�֣�Ȩ�أ�
};

struct student {
	int   no;               //ѧ�ţ���Ȼ��int���������˴������ǣ�
	char  name[9];          //���������4������
	struct course score[3]; //��������ſεĳɼ���δʹ�ú궨�壬����ʵ��ʱ��ֱ��д3���ɣ�
	float average;                     //��������������Ϊ��Ҫ���ӵĽṹ���Ա����һ��������Ҫ��ɾ������
};

/***************************************************************************
  �������ƣ�
  ��    �ܣ�����10��ѧ������Ϣ
  ���������
  �� �� ֵ��
  ˵    ������������ֺ궨��N
***************************************************************************/
void input(struct student* stu, int num)
{
	/* �����������ͱ����⣬�����������������κ���ʽ�ı���
		 ������ã�����ɾ�������������ӻ��滻Ϊ������ʽ�ı���
		����for(int i=0; )��ʽ���±�������ͬ����ֹ */
	int i, j;
	for (i = 0; i < num; i++){
		cout << setiosflags(ios::right);
		cout << "�������"<< setfill(' ') <<setw(2) << i+1 << "��ѧ������Ϣ : ";
		cout << resetiosflags(ios::right);

		cin >> stu[i].no;
		cin >> stu[i].name;
		for (j = 0; j < 3; j++) {
			cin >> stu[i].score[j].value;
			cin >> stu[i].score[j].weight;
		}
	}

	/* ������ʵ�ֲ��� */
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ����10��ѧ���Ļ�����Ϣ
  ���������
  �� �� ֵ��
  ˵    ������������ֺ궨��N
***************************************************************************/
void output_base(struct student* stu, int num)
{
	/* ��������ָ������⣬�����������������κ���ʽ�ı���
		 ������ã�����ɾ�������������ӻ��滻Ϊ������ʽ�ı���
		����for(int i=0; )��ʽ���±�������ͬ����ֹ */
	struct student* ps;
	struct course* pc;

	ps = stu;
	cout << "\n";
	cout << num << "��ѧ���ĳɼ�Ϊ" << endl;
	cout << "��� ѧ��    ����     �ɼ�1 Ȩ��1 �ɼ�2 Ȩ��2 �ɼ�3 Ȩ��3 ��Ȩƽ���ɼ�" << endl;
	cout << "======================================================================" << endl;

	cout << setiosflags(ios::left) << setfill(' ');
	while (ps - stu != num) {
		
		cout << setw(5) << ps - stu + 1 << setw(8) << ps->no << setw(9) << ps->name;
		for (pc = ps->score; pc < ps->score + 3; pc++) {
			cout << setw(6)<< pc->value <<setw(6) << pc->weight;
		}
		cout << setiosflags(ios::fixed) << setprecision(2);
		ps->average = (ps->score[0].value * ps->score[0].weight + ps->score[1].value * ps->score[1].weight + ps->score[2].value * ps->score[2].weight) / (ps->score[0].weight + ps->score[1].weight + ps->score[2].weight);
		cout << ps -> average;
		cout << resetiosflags(ios::fixed) << setprecision(6);
		cout << endl;
		ps++;
	}
	
	/* ������ʵ�ֲ��֣��������κ���ʽ��[]���� */
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ����������ߵ�ѧ���������в��У�
  ���������
  �� �� ֵ��
  ˵    ������������ֺ궨��N
***************************************************************************/
void output_max(struct student* stu, int num)
{
	/* ��������������������͵ļ򵥱������������������� */
	float max = 0;
	student* ps = stu;
	course* pc;

	cout << "\n�ɼ���ߵ�ѧ��Ϊ" << endl;
	cout << "��� ѧ��    ����     �ɼ�1 Ȩ��1 �ɼ�2 Ȩ��2 �ɼ�3 Ȩ��3 ��Ȩƽ���ɼ�" << endl;
	cout << "======================================================================" << endl;

	for (int i = 0; i < num; i++) {
		if (ps->average > max) {
			max = ps -> average;
		}
		ps++;
	}

	ps = stu;
	for (int i = 0; i < num; i++) {
		if (ps->average == max) {
			cout << setw(5) << ps - stu + 1 << setw(8) << ps->no << setw(9) << ps->name;
			for (pc = ps->score; pc < ps->score + 3; pc++) {
				cout << setw(6) << pc->value << setw(6) << pc->weight;
			}
			cout << setiosflags(ios::fixed) << setprecision(2);
			ps->average = (ps->score[0].value * ps->score[0].weight + ps->score[1].value * ps->score[1].weight + ps->score[2].value * ps->score[2].weight) / (ps->score[0].weight + ps->score[1].weight + ps->score[2].weight);
			cout << ps->average;
			cout << resetiosflags(ios::fixed) << setprecision(6);
			cout << endl;
		}
		ps++;
	}

}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main������׼��
***************************************************************************/
int main()
{
	struct student stu[N];

	input(stu, 10);		//����10��ѧ������Ϣ
	output_base(stu, 10);	//���10��ѧ���Ļ�����Ϣ
	output_max(stu, 10);	//�����ߣ������ж����

	return 0;
}

/*
�������ݣ����Ƶ�cmd���ɣ�����ʱ����������һ�飩


2153171 ������ 76.5 4 82 5 52 2
2154063 ����� 63 4 49 1 87 6
2151626 ������ 56 3 76 4 69 5
2153178 ϯ���� 44.5 2 83.5 4 87 6
2153482 ���� 91 4 63.5 1 56 3
2151931 ���� 79 6 85.5 3 62 2
2151282 ���� 86 3 63 3 77.5 4
2153047 �ż�ľ 49.5 3 86 6 93.5 3
2151405 ��ά�� 68 2 74.5 3 60 5
2152505 ��ѧ�� 73 3 62 2 85 5

*/