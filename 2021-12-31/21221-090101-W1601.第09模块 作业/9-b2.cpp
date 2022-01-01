/* 1851521 �� ������ */

/* ���������ϵͳ�ĺ궨�塢��Ҫ��ͷ�ļ��� */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#define MAX_STU_NUM			256	//Լ���������Ϊ256�ˣ����ֵ��ܺͣ�������ѡ����ѡ��
#define MAX_NAME_LEN			32	//ѧ����������󳤶Ȳ�����16������
#define MAX_FILENAME_LEN		256	//�ļ�������󳤶�

class stu_list;
/* stu_info ����ÿ��ѧ������Ϣ������ѧ�š�������������Ҫ��˽����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_info {
private:
	int  stu_no;			//ѧ��
	char stu_name[MAX_NAME_LEN];	//����
	char first[MAX_NAME_LEN];
	char second[MAX_NAME_LEN];

	/* ���������private���ݳ�Ա����Ա�����Լ�������Ҫ������ */
	friend stu_list;
public:
	/* ���಻�������κεĹ������ݳ�Ա����Ա���� */
};

/* stu_list ������ѡ����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_list {
private:
	stu_info stu[MAX_STU_NUM + 1];
	int length = 0;
	/* ���������private���ݳ�Ա�ͳ�Ա���� */
	
public:
	int read(const char* filename, const int append = 0);	//���ļ��ж���ѡ����Ϣ�����д�����2������ֵΪ0��ʾ���Ƿ�ʽ��1��ʾ׷�ӷ�ʽ
	int print(const char* prompt = NULL);			//��ӡ��ǰ�����ѡ������
	void sort();

	template <class T> void swap(T& t1, T& t2);
	/* �������������public��Ա���� */

};

template <class T>
void stu_list::swap(T& t1,T& t2)
{
	T temp;
	temp = t1;
	t1 = t2;
	t2 = temp;
}

void stu_list::sort()
{
	for (int i = length - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (stu[j].stu_no > stu[j + 1].stu_no) {
				swap(stu[j], stu[j + 1]);
			}
		}
	}
}

/* --- �˴���������������ĳ�Ա����������ʵ�� --- */
int stu_list::read(const char* filename, const int append)
{
	int temp;
	ifstream in(filename, ios::in);

	if (append == 0) {
		int count = 0;
		
		while (1) {
			in >> stu[count].stu_no;
			in >> stu[count].stu_name;
			if (in.fail()) {
				break;
			}
			strcpy(stu[count].first, "Y");
			strcpy(stu[count].second, "�˿�");
			count++;
			length++;

			if (length == 185) {
				cout << "";
			}

		}
		return count;
	}
	else {
		while (1) {
			in >> temp;
			if (in.fail()) {
				break;
			}
			int flag = 0;
			for (int i = 0; i < length; i++) {
				if (stu[i].stu_no == temp) {
					flag = 1;
					in >> stu[i].stu_name;
					strcpy(stu[i].second, "Y");
					break;
				}
			}

			if (flag == 0) {
				stu[length].stu_no = temp;
				in >> stu[length].stu_name;
				strcpy(stu[length].first, "/");
				strcpy(stu[length].second, "��ѡ");
				length++;
			}
		}
	}

	return 0;
}

int stu_list::print(const char* prompt)
{
	sort();
	cout << setiosflags(ios::left);
	cout << prompt << endl;
	cout << "===========================================================" << endl;
	cout << "��� ѧ��    ����                             ��һ�� �ڶ���" << endl;
	cout << "===========================================================" << endl;
	for (int i = 0; i < length; i++) {
		cout << setw(5) << i + 1 
			<< setw(8) << stu[i].stu_no 
			<< setw(33) << stu[i].stu_name 
			<< setw(7) << stu[i].first 
			<< stu[i].second 
			<< endl;
	}
	cout << "===========================================================" << endl;
	return 0;
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
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "������ǰһ��ѡ�ε������ļ� : ";
	cin >> file1;
	cout << "�������һ��ѡ�ε������ļ� : ";
	cin >> file2;

	stu_list list;

	/* �����һ�������ļ� */
	if (list.read(file1) < 0)
		return -1;

	/* ����ڶ��������ļ�������2��ֵΪ1��ʾ׷�ӷ�ʽ */
	if (list.read(file2, 1) < 0)
		return -1;

	list.print("����ѡ������");

	return 0;
}
