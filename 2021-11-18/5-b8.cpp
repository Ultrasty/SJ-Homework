/* 1851521 软工 沈天宇 */
#include <iostream>
using namespace std;

double area(double x[], double y[], int n)
{
	double sum = 0;
	for (int i = 0; i < n; i++) {
		sum += x[i] * y[(i + n + 1) % n] / 2;
		sum -= x[i] * y[(i + n - 1) % n] / 2;
	}
	return abs(sum);
}

bool is_convex(double x[], double y[], int n) 
{
	double vecx1, vecy1, vecx2, vecy2;
	int temp=0;
	double cross_product;
	for (int i = 0; i < n; i++) {
		vecx1 = x[i] - x[(i + n - 1) % n];
		vecy1 = y[i] - y[(i + n - 1) % n];

		vecx2 = x[i] - x[(i + n + 1) % n];
		vecy2 = y[i] - y[(i + n + 1) % n];

		cross_product = vecx1 * vecy2 - vecy1 * vecx2;
		if (cross_product < 0)
			temp += -1;
		if (cross_product == 0)
			return false;
		if (cross_product > 0)
			temp += 1;
	}
	if (temp == n || temp == -n) {
		return true;
	}
	else 
		return false;
}

int main()
{
	double x[10];
	double y[10];
	int number;
	char c;

	while (1) {
		cout << "请输入多边形的顶点数量(4-7)" << endl;
		cin >> number;
		while ((c = getchar()) != '\n' && c != EOF)
			;
		if (cin.fail())
			cin.clear();
		if (number >= 4 && number <= 7)
			break;
	}

	cout << "请按顺时针/逆时针方向输入" << number << "个顶点的x, y坐标：" << endl;
	for (int i = 0; i < number; i++) {
		while (1) {
			cout << "请输入第" << i + 1 << "个顶点的坐标：" << endl;
			cin >> x[i] >> y[i];
			while ((c = getchar()) != '\n' && c != EOF)
				;
			if (cin.fail())
				cin.clear();
			else
				break;
		}
	}

	
	if (!is_convex(x, y, number))
		cout << "不是凸4边形" << endl;
	else {
		cout << "凸" << number << "边形的面积=" << area(x, y, number) << endl;
	}

	return 0;
}
