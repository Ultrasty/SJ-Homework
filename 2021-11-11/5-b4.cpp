/* 1851521 沈天宇 软工 */
#include<iostream>
using namespace std;

int main() {
	int num[1005];
	int sum[105];
	int n;
	char c;

	cout << "请输入成绩（最多1000个），以-1结束" << endl;
	for (int i = 0; i < 1000; i++) {
		cin >> num[i];
		if (num[i] == -1)
			break;
	}

	if (num[0] == -1) {
		cout << "无有效输入" << endl;
		return 0;
	}

	cout << "输入的数组为:";
	for (int i = 0; i < 1000; i++) {
		if (num[i] == -1) {
			break;
		}
		if (i % 10 == 0) {
			cout << endl;
		}
		cout << num[i] << " ";
	}
	cout << endl;


	while ((c = getchar()) != '\n' && c != EOF);
	cout << "分数与人数的对应关系为:" << endl;

	for (int i = 0; i <= 100; i++) {
		sum[i] = 0;
	}

	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j < 1000; j++) {
			if (num[j] == i) {
				sum[i]++;
			}
		}
	}

	for (int i = 100; i >= 0; i--) {
		if (sum[i]) {
			cout << i << " " << sum[i] << endl;
		}
	}


	return 0;
}