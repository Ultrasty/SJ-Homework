/* 1851521 ������ �� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2��������һ��ȫ�ֱ������������徲̬�ֲ�����
   3������������������������ʼ/Ŀ�����ĺ���������������ʹ��ѭ�������������
   4����������ú������У���main�в���������κ���ʽ��ѭ��
      ���������main�н��У���main���������ѭ��
   --------------------------------------------------------------------- */
int count = 0;

   /***************************************************************************
     �������ƣ�
     ��    �ܣ���ӡn�㺺ŵ�����ƶ�˳��
     ���������int n������
               char src����ʼ��
               char tmp���м���
               char dst��Ŀ����
     �� �� ֵ��
     ˵    ����1�����������βΡ��������;���׼��
               2������������������κ���ʽ��ѭ��
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    
    if (n == 1) {
        count++;
        printf("%5d:  1# %c-->%c\n", count, src, dst);
    }
    else if (n == 2) {
        count++;
        printf("%5d:  1# %c-->%c\n", count, src, tmp);
        count++;
        printf("%5d:  2# %c-->%c\n", count, src, dst);
        count++;
        printf("%5d:  1# %c-->%c\n", count, tmp, dst);
    }
    else {
        hanoi(n - 1, src, dst, tmp);
        
        count++;
        printf("%5d: ", count);
        if (n < 10) {
            printf(" ");
        }
        printf("%d# %c-->%c\n", n, src, dst);
        
        hanoi(n - 1, tmp, src, dst);
    }
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    �����������(��������뺯��)�����õݹ麯��
***************************************************************************/
int main()
{
    int n, ret;
    char src, tmp, dst;
    //������ջ���������ʱ����
    char c;

    while (1) {
        printf("�����뺺ŵ���Ĳ���(1-16)\n");
        ret = scanf("%d", &n);
        if (ret!=1) {
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }
        else if (n < 1 || n>16) {
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }
        else {
            while ((c = getchar()) != '\n' && c != EOF);
            break;
        }
            
    }

    while (1) {
        printf("��������ʼ��(A-C)\n");
        ret = scanf("%c", &src);
        if (ret!=1) {
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }
        else if (src < 'A' || src>'C') {
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }
        else {
            while ((c = getchar()) != '\n' && c != EOF);
            break;
        }
            
    }

    while (1) {
        printf("������Ŀ����(A-C)\n");
        ret = scanf("%c", &dst);
        if (ret!=1) {
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }
        else if (dst < 'A' || dst>'C') {
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }
        else {
            while ((c = getchar()) != '\n' && c != EOF);
            break;
        }
            
    }

    tmp = 3 * 'B' - src - dst;

    printf("�ƶ�����Ϊ:\n");

    hanoi(n, src, tmp, dst);
}
