/* 1851521 ������ �� */
#include <iostream>
using namespace std;

int main()
{
	cout << "������һ������С��80���ַ��������Ĵ���" << endl;
	char input[100];
	fgets(input,100,stdin);
	char* start = input, *end = input;
	while (*end != '\n') {
		end++;
	}
	end--;
	bool is_huiwen = true;
	while (start < end) {
		if (*start != *end) {
			is_huiwen = false;
		}
		start++;
		end--;
	}
	if (is_huiwen) 
		cout << "yes";
	else
		cout << "no";
	cout << endl;
}