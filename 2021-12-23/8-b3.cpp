/* 1851521 ������ �� */

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

int main(int argc, char* argv[])
{

    cerr << "�ļ���������ʽ������:" << endl;
    cerr << "    a.txt                    : ����·����ʽ" << endl;
    cerr << "    ..\\data\\b.dat          : ���·����ʽ" << endl;
    cerr << "    C:\\Windows\\System32\\c.dat : �������·����ʽ" << endl;
    
    char filename_in[50];
    char filename_out[50];
    
    cerr << "������Ҫת����hex��ʽ�ļ��� : ";
    cin >> filename_in;
   
    cerr << "������ת������ļ���        : ";
    cin >> filename_out;

    ifstream in(filename_in, ios::in);
    ofstream out(filename_out, ios::out | ios::binary);

    int current;
    char cache[100];
    while (!in.eof()) {

        in.getline(cache,100);

        for (int i = 0; i < 100; i++) {
            if (cache[i] >= 'A' && cache[i] <= 'Z') {
                cache[i] += 0x20;
            }

            if (cache[i] >= 'a' && cache[i] <= 'f') {
                cache[i] = '9' + cache[i] - 'a' + 1;
            }
        }

        for (int i = 0; i < 8; i++) {
            if (cache[i * 3 + 10] == ' ' && cache[i * 3 + 11] == ' ') {
                in.close();
                out.close();
                return 0;
            }
            out << char((cache[i * 3 + 10] - '0') * 16 + cache[i * 3 + 11] - '0');
        }

        for (int i = 0; i < 8; i++) {
            if (cache[i * 3 + 36] == ' ' && cache[i * 3 + 37] == ' ') {
                in.close();
                out.close();
                return 0;
            }
            out << char((cache[i * 3 + 36] - '0') * 16 + cache[i * 3 + 37] - '0');
        }

    }
    in.close();
    out.close();
    return 0;
}
