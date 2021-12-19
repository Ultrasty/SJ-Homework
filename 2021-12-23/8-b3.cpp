/* 1851521 沈天宇 软工 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

int main(int argc, char* argv[])
{

    cerr << "文件名以下形式均可以:" << endl;
    cerr << "    a.txt                    : 不带路径形式" << endl;
    cerr << "    ..\\data\\b.dat          : 相对路径形式" << endl;
    cerr << "    C:\\Windows\\System32\\c.dat : 绝对相对路径形式" << endl;
    
    char filename_in[50];
    char filename_out[50];
    
    cerr << "请输入要转换的hex格式文件名 : ";
    cin >> filename_in;
   
    cerr << "请输入转换后的文件名        : ";
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
