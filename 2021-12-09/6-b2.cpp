/* 1851521 沈天宇 软工 */
#include <iostream>
using namespace std;

int main()
{
	cout << "请输入一个长度小于80的字符串（回文串）" << endl;
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