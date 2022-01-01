/* 1851521 软工 沈天宇 */

/* 允许按需加入系统的宏定义、需要的头文件等 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#define MAX_STU_NUM			256	//约定最大人数为256人（两轮的总和，包括退选、补选）
#define MAX_NAME_LEN			32	//学生姓名的最大长度不超过16个汉字
#define MAX_FILENAME_LEN		256	//文件名的最大长度

class stu_list;
/* stu_info 类存放每个学生的信息，包括学号、姓名、其它需要的私有信息，已有内容不准动，可加入符合限制要求的新内容 */
class stu_info {
private:
	int  stu_no;			//学号
	char stu_name[MAX_NAME_LEN];	//姓名
	char first[MAX_NAME_LEN];
	char second[MAX_NAME_LEN];

	/* 允许按需加入private数据成员、成员函数以及其它需要的内容 */
	friend stu_list;
public:
	/* 本类不允许定义任何的公有数据成员、成员函数 */
};

/* stu_list 类整个选课信息，已有内容不准动，可加入符合限制要求的新内容 */
class stu_list {
private:
	stu_info stu[MAX_STU_NUM + 1];
	int length = 0;
	/* 允许按需加入private数据成员和成员函数 */
	
public:
	int read(const char* filename, const int append = 0);	//从文件中读入选课信息并进行处理，第2个参数值为0表示覆盖方式，1表示追加方式
	int print(const char* prompt = NULL);			//打印当前读入的选课名单
	void sort();

	template <class T> void swap(T& t1, T& t2);
	/* 允许按需加入其它public成员函数 */

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

/* --- 此处给出上面两个类的成员函数的体外实现 --- */
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
			strcpy(stu[count].second, "退课");
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
				strcpy(stu[length].second, "补选");
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
	cout << "序号 学号    姓名                             第一轮 第二轮" << endl;
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
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准动
***************************************************************************/
int main()
{
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "请输入前一轮选课的数据文件 : ";
	cin >> file1;
	cout << "请输入后一轮选课的数据文件 : ";
	cin >> file2;

	stu_list list;

	/* 读入第一个数据文件 */
	if (list.read(file1) < 0)
		return -1;

	/* 读入第二个数据文件，参数2的值为1表示追加方式 */
	if (list.read(file2, 1) < 0)
		return -1;

	list.print("最终选课名单");

	return 0;
}
