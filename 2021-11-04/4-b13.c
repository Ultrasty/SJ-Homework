/* 1851521 沈天宇 软工 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* ----具体要求----
   1、不允许添加其它头文件
   2、允许定义一个全局变量、不允许定义静态局部变量
   3、允许添加用于输入层数、起始/目标柱的函数，函数中允许使用循环处理错误输入
   4、如果输入用函数进行，则main中不允许出现任何形式的循环
      如果输入在main中进行，则main中允许出现循环
   --------------------------------------------------------------------- */
int count = 0;

   /***************************************************************************
     函数名称：
     功    能：打印n层汉诺塔的移动顺序
     输入参数：int n：层数
               char src：起始柱
               char tmp：中间柱
               char dst：目标柱
     返 回 值：
     说    明：1、函数名、形参、返回类型均不准动
               2、本函数不允许出现任何形式的循环
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
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：完成输入(或调用输入函数)、调用递归函数
***************************************************************************/
int main()
{
    int n, ret;
    char src, tmp, dst;
    //用于清空缓冲区的临时变量
    char c;

    while (1) {
        printf("请输入汉诺塔的层数(1-16)\n");
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
        printf("请输入起始柱(A-C)\n");
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
        printf("请输入目标柱(A-C)\n");
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

    printf("移动步骤为:\n");

    hanoi(n, src, tmp, dst);
}
