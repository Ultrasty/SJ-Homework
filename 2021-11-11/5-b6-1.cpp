/* 1851521 ������ �� */
#include <iostream>
#include <iomanip>
using namespace std;

int countt = 0;
int stackA[] = { 0,0,0,0,0,0,0,0,0,0 };
int stackB[] = { 0,0,0,0,0,0,0,0,0,0 };
int stackC[] = { 0,0,0,0,0,0,0,0,0,0 };
int A = 0, B = 0, C = 0;
/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2����������ȫ�ֱ�������̬�ֲ�����
   3������������������������ʼ/Ŀ�����ĺ���������������ʹ��ѭ�������������
   4����������ú������У���main�в���������κ���ʽ��ѭ��
      ���������main�н��У���main���������ѭ��
   --------------------------------------------------------------------- */

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
        cout << "��" << setfill(' ') << setw(4) << countt << " ��(" << " 1):" << " " << src << "-->" << dst;
        push(dst,pop(src));
        print_stack();
    }
    else if (n == 2) {
        countt++;
        cout << "��" << setfill(' ') << setw(4) << countt << " ��(" << " 1):" << " " << src << "-->" << tmp;
        push(tmp, pop(src));
        print_stack();

        countt++;
        cout << "��" << setfill(' ') << setw(4) << countt << " ��(" << " 2):" << " " << src << "-->" << dst;
        push(dst, pop(src));
        print_stack();

        countt++;
        cout << "��" << setfill(' ') << setw(4) << countt << " ��(" << " 1):" << " " << tmp << "-->" << dst;
        push(dst, pop(tmp));
        print_stack();
    }
    else {
        hanoi(n - 1, src, dst, tmp);
        countt++;
        cout << "��" << setfill(' ') << setw(4) << countt << " ��(";
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    �����������(��������뺯��)�����õݹ麯��
***************************************************************************/
int main()
{
    int n;
    char src, tmp, dst;
    //������ջ���������ʱ����
    char c;

    while (1) {
        cout << "�����뺺ŵ���Ĳ���(1-10)��" << endl;
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
        cout << "��������ʼ��(A-C)��" << endl;
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
        cout << "������Ŀ����(A-C)��" << endl;
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

    //��ʼ��ջ
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

    cout << "��ʼ:               ";
    print_stack();


    hanoi(n, src, tmp, dst);

}
