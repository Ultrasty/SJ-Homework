/* 1851521 Èí¹¤ ÉòÌìÓî */
#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= i; j++) {
			cout << j << "x" << i << "=" << i * j;
			if (i * j < 10) {
				cout << "   ";
			}
			else
				cout << "  ";
		}
		cout << endl;
	}

	return 0;
}