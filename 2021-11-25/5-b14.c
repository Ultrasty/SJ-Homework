/* 1851521 ������ �� */
/* 1854063 ���ž� 1853022 ������ 1853539 ����� 2153690 ��ܰ 2050769 ���ַ� 2152815 ���Ǵ� */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    char bomb[10][26];
    int count = 0;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 26; j++) {
            scanf("%c ", &bomb[i][j]);
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 26; j++) {
            if (bomb[i][j] == '*') {
                for (int k = i - 1; k <= i + 1; k++) {
                    for (int l = j - 1; l <= j + 1; l++) {
                        if (k >= 0 && k < 10 && l >= 0 && l < 26 && bomb[k][l] != '*') {
                            bomb[k][l]--;
                        }
                    }
                }
                count++;
            }
        }
    }

    if (count != 50) {
        printf("����1\n");
        return 0;
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 26; j++) {
            if (bomb[i][j] != '0' && bomb[i][j] != '*') {
                printf("����2\n");
                return 0;
            }
        }
    }

    printf("��ȷ\n");
    return 0;


}
