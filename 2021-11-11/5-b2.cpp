/* 1851521 ÉòÌìÓî Èí¹¤ */
#include<iostream>
using namespace std;

int main() {
	bool list[105];

	for (int i = 1; i <= 100; i++) {
		list[i] = 0;
	}

	for (int i = 1; i <= 100; i++) {
		int temp = i;
		while (temp <= 100) {
			list[temp] = !list[temp];
			temp += i;
		}
	}

	for (int i = 1; i < 100; i++) {
		if (list[i])
			cout << i << " ";
	}

	if (list[100])
		cout << 100 << endl;

	return 0;
}