/* 1851521 �� ������ */
#include<iostream>
#include<cmath>
using namespace std;

int main() {

	int a, n,temp,sum=0;
	cout << "������a��n��ֵ" << endl;
	cin >> a >> n;
	for (int i = 0; i < n; i++) {
		temp = 0;
		for (int j = 0; j <= i; j++) {
			temp = temp *10+a;
		}
		sum += temp;
	}
	cout << "S=" << sum << endl;

	return 0;
}