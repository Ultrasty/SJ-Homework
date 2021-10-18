/* 1851521 »Ìπ§ …ÚÃÏ”Ó */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

int main()
{
	int sum = 0;
	int isfirst = 0;
	for (int i = 2; i <= 1000; i++) {
		sum = 0;
		for (int j = 1; j < i; j++) {
			if (i % j == 0) {
				sum += j;
			}
		}
		if (sum == i) {
			printf("%d,its factors are ", sum);
			isfirst = 0;
			for (int j = 1; j < i; j++) {
				if (i % j == 0) {
					if (isfirst == 0) {
						printf("%d", j);
						isfirst = 1;
					}
					else
						printf(",%d", j);
				}
			}
			printf("\n");
		}
		
	}

	return 0;
}