/* 1851521 ������ �� */
#include<iostream>
using namespace std;

int main()
{
	char input[50];
	cout << "������һ��0/1��ɵ��ַ��������Ȳ�����32" << endl;
	cin.getline(input,100);
	char* p = input;
	int result = 0;

	while (*p != 0) {
		result = result * 2 + *p - '0';
		p++;
	}

	cout << result << endl;
}