/* 1851521 沈天宇 软工 */

#define _CRT_SECURE_NO_WARNINGS
#define STU_COUNT 10
#define CODE_LEN 8
#define NAME_LEN 9
#include <stdio.h>
#include <string.h>

void read_data(char studentID[STU_COUNT][CODE_LEN],char name[STU_COUNT][NAME_LEN],int grade[STU_COUNT]) 
{
    for (int i = 0; i < STU_COUNT; i++) {
        printf("请输入第%d个人的学号、姓名、成绩\n", i + 1);
        scanf("%s", studentID[i]);
        scanf("%s", name[i]);
        scanf("%d", &grade[i]);
    }
}

void bubble_sort(char studentID[STU_COUNT][CODE_LEN], char name[STU_COUNT][NAME_LEN], int grade[STU_COUNT])
{
    for (int i = STU_COUNT-1; i >=0; i--) {
        for (int j = 0; j < i; j++) {
            char temp[CODE_LEN + NAME_LEN];
            int tempgrade;

            int comp;
            if (grade[j] > grade[j + 1]) {
                comp = -1;
            }
            else if (grade[j] < grade[j + 1]) {
                comp = 1;
            }
            else
                comp = 0;

            if (comp > 0) {
                strcpy(temp,studentID[j]);
                strcpy(studentID[j], studentID[j+1]);
                strcpy(studentID[j+1], temp);

                strcpy(temp, name[j]);
                strcpy(name[j], name[j+1]);
                strcpy(name[j+1], temp);

                tempgrade = grade[j];
                grade[j] = grade[j + 1];
                grade[j + 1] = tempgrade;
            }
        }
    }
}

void print_data(char studentID[STU_COUNT][CODE_LEN], char name[STU_COUNT][NAME_LEN], int grade[STU_COUNT])
{
    printf("\n全部学生(成绩降序):\n");
    for (int i = 0; i < STU_COUNT; i++) {

        printf("%s %s %d\n", name[i], studentID[i], grade[i]);

    }
}

int main()
{
    char studentID[STU_COUNT][CODE_LEN];
    char name[STU_COUNT][NAME_LEN];
    int grade[STU_COUNT];

    read_data(studentID, name, grade);
    bubble_sort(studentID, name, grade);
    print_data(studentID, name, grade);

    return 0;
}
