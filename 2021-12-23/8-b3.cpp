/* 1851521 ������ �� */
/* 2151621 ���� 2051943 ����� 1853539 ����� 1853022 ������ 1854063 ���ž� */
#define _CRT_SECURE_NO_WARNINGS
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
    int count = 0;
    char buf[20] = { 0 };
    char cache[100];
    while (!in.eof()) {

        in.getline(cache,100);

        if (cache[0] == '\0') {
            in.close();
            out.close();
            return 0;
        }

        //�������жϵ�һ�����޴���
        cache[8] = 0;
        sprintf(buf, "%8x", count);
        for (int i = 0; i < 7; i++) {
            if (buf[i] == ' ') {
                buf[i] = '0';
            }
        }
        if (strncmp(buf, cache, 8) != 0) {
            cerr << "������ƫ����0x" << cache << "��������ֵ0x" << buf << endl;
            in.close();
            out.close();
            return 0;
        }


        //��Сдת������'a'-'f'ƫ�Ƶ�'9'����
        for (int i = 0; i < 100; i++) {
            if (cache[i] >= 'A' && cache[i] <= 'Z') {
                cache[i] += 0x20;
            }

            if (cache[i] >= 'a' && cache[i] <= 'f') {
                cache[i] = '9' + cache[i] - 'a' + 1;
            }
        }

        

        //ʮ�������ַ���תʮ�������֣�תΪchar���
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

        count += 16;
    }
    in.close();
    out.close();
    return 0;
}
