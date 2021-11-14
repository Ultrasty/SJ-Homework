/* 1851521 沈天宇 软工 */
#include <iostream>
#include <iomanip>
using namespace std;

int countt = 0;
int stackA[] = { 0,0,0,0,0,0,0,0,0,0 };
int stackB[] = { 0,0,0,0,0,0,0,0,0,0 };
int stackC[] = { 0,0,0,0,0,0,0,0,0,0 };
int A = 0, B = 0, C = 0;
/* ----具体要求----
   1、不允许添加其它头文件
   2、不允许定义全局变量、静态局部变量
   3、允许添加用于输入层数、起始/目标柱的函数，函数中允许使用循环处理错误输入
   4、如果输入用函数进行，则main中不允许出现任何形式的循环
      如果输入在main中进行，则main中允许出现循环
   --------------------------------------------------------------------- */

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

void push(char i,int j)
{
    if (i == 'A') {
        stackA[A++] = j;
    }
    if (i == 'B') {
        stackB[B++] = j;
    }
    if (i == 'C') {
        stackC[C++] = j;
    }
}

int pop(char i) 
{
    int temp = 0;
    if (i == 'A') {
        
        temp= stackA[--A];
        stackA[A] = 0;
    }
    if (i == 'B') {

        temp= stackB[--B];
        stackB[B] = 0;
    }
    if (i == 'C') {

        temp= stackC[--C];
        stackC[C] = 0;
    }
    return temp;
}

void print_stack() 
{
    cout << " A:";
    for (int i = 0; i < 10; i++) {
        if (stackA[i] == 10)
            cout << 10;
        if (stackA[i] < 10 && stackA[i]>0)
            cout << " " << stackA[i];
        if (stackA[i] == 0)
            cout << "  ";
    }
    cout << " ";


    cout << "B:";
    for (int i = 0; i < 10; i++) {
        if (stackB[i] == 10)
            cout << 10;
        if (stackB[i] < 10 && stackB[i]>0)
            cout << " " << stackB[i];
        if (stackB[i] == 0)
            cout << "  ";
    }
    cout << " ";


    cout << "C:";
    for (int i = 0; i < 10; i++) {
        if (stackC[i] == 10)
            cout << 10;
        if (stackC[i] < 10 && stackC[i]>0)
            cout << " " << stackC[i];
        if (stackC[i] == 0)
            cout << "  ";
    }
    cout << endl;

}

void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 1) {
        countt++;
        cout << "第" << setfill(' ') << setw(4) << countt << " 步(" << " 1):" << " " << src << "-->" << dst;
        push(dst,pop(src));
        print_stack();
    }
    else if (n == 2) {
        countt++;
        cout << "第" << setfill(' ') << setw(4) << countt << " 步(" << " 1):" << " " << src << "-->" << tmp;
        push(tmp, pop(src));
        print_stack();

        countt++;
        cout << "第" << setfill(' ') << setw(4) << countt << " 步(" << " 2):" << " " << src << "-->" << dst;
        push(dst, pop(src));
        print_stack();

        countt++;
        cout << "第" << setfill(' ') << setw(4) << countt << " 步(" << " 1):" << " " << tmp << "-->" << dst;
        push(dst, pop(tmp));
        print_stack();
    }
    else {
        hanoi(n - 1, src, dst, tmp);
        countt++;
        cout << "第" << setfill(' ') << setw(4) << countt << " 步(";
        if (n < 10) {
            cout << " ";
        }
        cout << n << "): " << src << "-->" << dst;
        push(dst, pop(src));
        print_stack();
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
    int n;
    char src, tmp, dst;
    //用于清空缓冲区的临时变量
    char c;

    while (1) {
        cout << "请输入汉诺塔的层数(1-10)：" << endl;
        cin >> n;
        if (cin.fail()) {
            cin.clear();
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }
        else if (n < 1 || n>10) {
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }
        else {
            while ((c = getchar()) != '\n' && c != EOF);
            break;
        }
           
    }

    while (1) {
        cout << "请输入起始柱(A-C)：" << endl;
        cin >> src;
        if (cin.fail()) {
            cin.clear();
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
        cout << "请输入目标柱(A-C)：" << endl;
        cin >> dst;
        if (cin.fail()) {
            cin.clear();
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

    //初始化栈
    if (src == 'A') {
        for (int i = 0; i < n; i++) {
            stackA[i] = n - i;
        }
        A = n;
    }
    if (src == 'B') {
        for (int i = 0; i < n; i++) {
            stackB[i] = n - i;
        }
        B = n;
    }
    if (src == 'C') {
        for (int i = 0; i < n; i++) {
            stackC[i] = n - i;
        }
        C = n;
    }

    cout << "初始:               ";
    print_stack();


    hanoi(n, src, tmp, dst);

}
