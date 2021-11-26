/* 1851521 ÉòÌìÓî Èí¹¤ */
/* 1854063 ½ªêÅ¾Å 1853022 ¹®ĞÀâù 1853539 ÑîÆæè¯ 2153690 ÎÂÜ° 2050769 ÑîÁÖ·ã 2152815 ÎâÖÇ´¾ */

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
        printf("´íÎó1\n");
        return 0;
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 26; j++) {
            if (bomb[i][j] != '0' && bomb[i][j] != '*') {
                printf("´íÎó2\n");
                return 0;
            }
        }
    }

    printf("ÕıÈ·\n");
    return 0;


}
