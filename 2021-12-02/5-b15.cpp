/* 1851521 沈天宇 软工 */
#include<iostream>

using namespace std;

int main() {
	char str[3][128];

	int result[] = { 0,0,0,0,0 };

	for (int i = 0; i < 3; i++) {
		cout << "请输入第" << i+1 << "行" << endl;
		cin.getline(str[i], 200);
	}


	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 128; j++) {
			int temp = str[i][j];
			if (temp >= 'A' && temp <= 'Z') {
				result[0] += 1;
			}
			else if (temp >= 'a' && temp <= 'z') {
				result[1] += 1;
			}
			else if (temp >= '0' && temp <= '9') {
				result[2] += 1;
			}
			else if (temp == ' ') {
				result[3] += 1;
			}
			else if (temp!=0) {
				result[4] += 1;
			}
			if (temp == 0) {
				break;
			}
		}
	}

	cout << "大写 : " << result[0] << endl;
	cout << "小写 : " << result[1] << endl;
	cout << "数字 : " << result[2] << endl;
	cout << "空格 : " << result[3] << endl;
	cout << "其他 : " << result[4] << endl;
	
	return 0;

}
