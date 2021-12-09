/* 1851521 沈天宇 软工 */
#include<iostream>
using namespace std;

int main()
{
	char input[50];
	cout << "请输入一个0/1组成的字符串，长度不超过32" << endl;
	cin.getline(input,100);
	char* p = input;
	int result = 0;

	while (*p != 0) {
		result = result * 2 + *p - '0';
		p++;
	}

	cout << result << endl;
}