/* 1851521 ������ �� */
#include<iostream>
using namespace std;

void s1();
void s2();
void s3();
void s4();

double a, b, c;
double delta;

int main()
{
	
	cout << "������һԪ���η��̵�����ϵ��a,b,c:" << endl;
	cin >> a >> b >> c;
	delta = b * b - 4 * a * c;
	if (abs(a) < 1e-6) {
		s1();
	}
	else if (abs(delta) < 1e-6) {
		s2();
	}
	else if (delta > 0) {
		s3();
	}
	else if (delta < 0) {
		s4();
	}
	return 0;
}