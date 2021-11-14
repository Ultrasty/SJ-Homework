/* 1851521 沈天宇 软工 */
#include<iostream>
using namespace std;

int main() {
	int num[25];
	int n;
	char c;
	bool output_flag = 0;
	cout << "请输入任意个正整数（升序，最多20个），以-1结束" << endl;
	for (int i = 0; i < 20; i++) {
		cin >> num[i];
		if (num[i] == -1)
			break;
	}

	if (num[0] == -1) {
		cout << "无有效输入" << endl;
		return 0;
	}

	cout << "原数组为：" << endl;
	for (int i = 0; i < 20; i++) {
		if (num[i] == -1) {
			break;
		}
		cout << num[i] << " ";
	}
	cout << endl;
	while ((c = getchar()) != '\n' && c != EOF);
	cout << "请输入要插入的正整数" << endl;
	cin >> n;
	cout << "插入后的数组为：" << endl;
	for (int i = 0; i < 20; i++) {
		if (num[i] == -1) {
			break;
		}
		if (num[i] > n && output_flag == 0) {
			cout << n << " ";
			output_flag = 1;
		}
		cout << num[i] << " ";
	}
	if (output_flag == 0) {
		cout << n << " ";
	}
	cout << endl;
	return 0;
}