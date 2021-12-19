/* 1851521 ������ �� */

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

void print_cache(int c,int cache[],int limit) 
{
    cout << setw(8) << hex << c << "  ";
    for (int i = 0; i < limit; i++) {
        if (i == 8) {
            cout << "- ";
        }
        cout << setw(2) << hex << cache[i] << " ";
    }

    for (int i = limit; i < 16; i++) {
        if (i == 8) {
            cout << "  ";
        }
        cout << "   ";
    }

    cout << "    ";

    for (int i = 0; i < limit; i++) {
        if (cache[i] >= 33 && cache[i] <= 126) {
            cout << char(cache[i]);
        }
        else
            cout << ".";
    }

    cout << endl;
}

int main(int argc, char* argv[])
{

    cerr << "�ļ���������ʽ������:" << endl;
    cerr << "    a.txt                    : ����·����ʽ" << endl;
    cerr << "    ..\\data\\b.dat          : ���·����ʽ" << endl;
    cerr << "    C:\\Windows\\System32\\c.dat : �������·����ʽ" << endl;
    cerr << "�������ļ��� : ";

    char filename[50];
    cin >> filename;

    ifstream in(filename, ios::in | ios::binary);//�ɼ�ios::binary
    int c = 0;
    int current;
    int cache[16];

    cout << setfill('0');

    while ((current = in.get()) != EOF) {

        cache[c % 16] = current;
        c++;   

        if (c % 16 == 0) {
            print_cache(c, cache ,16);
            for (int i = 0; i < 16; i++) {
                cache[i] = 0;
            }
        }       
    }

    print_cache(c, cache ,c % 16);

    in.close();

    return 0;
}
